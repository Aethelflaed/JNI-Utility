#ifndef FR_PLANQUART_JNI_TRAITS_CALLABLE_HPP
#define FR_PLANQUART_JNI_TRAITS_CALLABLE_HPP

#include <jni.h>
#include <cstdarg>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Class;
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
			struct callable_traits;
	}

	class Callable
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
			T callMethod(JNIEnv* env, Signature* signature, ...)
			{
				va_list arguments_list;
				va_start(arguments_list, signature);
				private_namespace::callable_traits<T>::callMethod(this, env, signature, arguments_list);
				va_end(arguments_list);
			}

	protected:
		virtual Method* getMethodDescriptor(JNIEnv* env, Signature* signature) = 0;
		virtual jobject getJavaObject() = 0;
		virtual Class* getClass() = 0;

		inline Object callObjectMethodV(JNIEnv* env, Signature* signature, va_list arguments_list);

	};

	/**
	 * Template specicalization for callMethod.
	 */
	template <>
		void Callable::callMethod<void>(JNIEnv* env, Signature* signature, ...);
	template <>
		jboolean Callable::callMethod<jboolean>(JNIEnv* env, Signature* signature, ...);
	template <>
		jbyte Callable::callMethod<jbyte>(JNIEnv* env, Signature* signature, ...);
	template <>
		jchar Callable::callMethod<jchar>(JNIEnv* env, Signature* signature, ...);
	template <>
		jshort Callable::callMethod<jshort>(JNIEnv* env, Signature* signature, ...);
	template <>
		jint Callable::callMethod<jint>(JNIEnv* env, Signature* signature, ...);
	template <>
		jlong Callable::callMethod<jlong>(JNIEnv* env, Signature* signature, ...);
	template <>
		jfloat Callable::callMethod<jfloat>(JNIEnv* env, Signature* signature, ...);
	template <>
		jdouble Callable::callMethod<jdouble>(JNIEnv* env, Signature* signature, ...);
	template <>
		Object Callable::callMethod<Object>(JNIEnv* env, Signature* signature, ...);
	template <>
		String Callable::callMethod<String>(JNIEnv* env, Signature* signature, ...);

	namespace private_namespace
	{
		template <typename T>
			struct callable_traits
			{
				static T callMethod(Callable* callable, JNIEnv* env, Signature* signature, va_list arguments_list);
			};

		template <typename T>
			struct callable_traits< Array<T> >
			{
				static Array<T> callMethod(Callable* callable, JNIEnv* env, Signature* signature, va_list arguments_list);
			};
	}
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_CALLABLE_HPP */

