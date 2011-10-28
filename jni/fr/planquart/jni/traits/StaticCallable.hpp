#ifndef FR_PLANQUART_JNI_TRAITS_STATICCALLABLE_HPP
#define FR_PLANQUART_JNI_TRAITS_STATICCALLABLE_HPP

#include <jni.h>
#include <cstdarg>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Method;
	class Object;
	class Signature;
	class String;

	template <typename T>
		class Array;

namespace traits
{
	namespace private_namespace
	{
		template <typename T>
			struct staticCallable_traits;
	}

	class StaticCallable
	{
	public:
		/**
		 * Call a method on the corresponding Java object.
		 *
		 * Requires one local reference, if the template parameter is Object.
		 * The local reference will be owned by the Object and freed with it.
		 *
		 * The valid template types are :
		 *		void
		 *		jboolean
		 *		jbyte
		 *		jchar
		 *		jshort
		 *		jint
		 *		jlong
		 *		jfloat
		 *		jdouble
		 *		Object
		 *		String
		 *		Array<typename T>
		 *			This last type uses template of the same types of the
		 *			method except the void type. As this type is included in
		 *			the list, you can thus use use complexe types like :
		 *			Array<Array<jin> >.
		 *
		 * @param env The JNI environment
		 * @param signature The method signature
		 * @param ... The parameters to give to the method
		 * @return A value of type T returned by the Java method
		 * @throws Any exception thrown by the called method plus if the local
		 *	reference creation fails, plus if the method recuperation fails.
		 *
		 * Note: if the template type you used in the above list, you will get
		 * a linker error, as the method is not defined.
		 *
		 * Implementation details:
		 *	The method is specicalized for various types. The default
		 *	implementation introduce another struct used for partial
		 *	specicalization. This is used for the Array<typename T> type.
		 */
		template <typename T>
			T callStaticMethod(JNIEnv* env, Signature* signature, ...)
			{
				va_list arguments_list;
				va_start(arguments_list, signature);
				private_namespace::staticCallable_traits<T>::callStaticMethod(env, signature, arguments_list);
				va_end(arguments_list);
			}

	protected:
		virtual Method* getStaticMethodDescriptor(JNIEnv* env, Signature* signature) = 0;
		virtual jclass getJavaClass(JNIEnv* env) const = 0;

		inline Object callStaticObjectMethodV(JNIEnv* env, Signature* signature, va_list arguments_list);

	};

	/**
	 * Template specicalization for callStaticMethod.
	 */
	template <>
		void StaticCallable::callStaticMethod<void>(JNIEnv* env, Signature* signature, ...);
	template <>
		jboolean StaticCallable::callStaticMethod<jboolean>(JNIEnv* env, Signature* signature, ...);
	template <>
		jbyte StaticCallable::callStaticMethod<jbyte>(JNIEnv* env, Signature* signature, ...);
	template <>
		jchar StaticCallable::callStaticMethod<jchar>(JNIEnv* env, Signature* signature, ...);
	template <>
		jshort StaticCallable::callStaticMethod<jshort>(JNIEnv* env, Signature* signature, ...);
	template <>
		jint StaticCallable::callStaticMethod<jint>(JNIEnv* env, Signature* signature, ...);
	template <>
		jlong StaticCallable::callStaticMethod<jlong>(JNIEnv* env, Signature* signature, ...);
	template <>
		jfloat StaticCallable::callStaticMethod<jfloat>(JNIEnv* env, Signature* signature, ...);
	template <>
		jdouble StaticCallable::callStaticMethod<jdouble>(JNIEnv* env, Signature* signature, ...);
	template <>
		Object StaticCallable::callStaticMethod<Object>(JNIEnv* env, Signature* signature, ...);
	template <>
		String StaticCallable::callStaticMethod<String>(JNIEnv* env, Signature* signature, ...);

	namespace private_namespace
	{
		template <typename T>
			struct staticCallable_traits
			{
				static T callStaticMethod(StaticCallable* staticCallable, JNIEnv* env, Signature* signature, va_list arguments_list);
			};

		template <typename T>
			struct staticCallable_traits< Array<T> >
			{
				static Array<T> callStaticMethod(StaticCallable* staticCallable, JNIEnv* env, Signature* signature, va_list arguments_list);
				/*{
					return Array<T>(env, staticCallable->callStaticObjectMethodV(env, signature, arguments_list), signature);
				}*/
			};
	}
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_STATICCALLABLE_HPP */

