#ifndef FR_PLANQUART_JNI_TRAITS_STATICFIELDSTRUCTURE_HPP
#define FR_PLANQUART_JNI_TRAITS_STATICFIELDSTRUCTURE_HPP

#include <jni.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Class;
	class Field;
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
			struct staticFieldStructure_traits;
	}

	class StaticFieldStructure
	{
	public:
		/**
		 * Get the specified field of the corresponding Java object.
		 *
		 * Requires one local reference, if the template parameter is Object
		 * The local reference will be owned by the Object and freed with it.
		 *
		 * The valid template types are :
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
		 *			method. As this type is included in
		 *			the list, you can thus use use complexe types like :
		 *			Array<Array<jin> >.
		 *
		 * @param env The JNI environment
		 * @param signature The field signature
		 * @return A value of type T corresponding to the field value.
		 * @throws Any exception thrown if the reference creation fails, plus
		 * if the field recuperation fails.
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
			T getStaticField(JNIEnv* env, Signature* signature)
			{
				private_namespace::staticFieldStructure_traits<T>::getStaticField(this, env, signature);
			}

		/**
		 * Set the specified field of the corresponding Java object to the
		 * given value.
		 *
		 * The valid template types are :
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
		 *			method. As this type is included in
		 *			the list, you can thus use use complexe types like :
		 *			Array<Array<jin> >.
		 *
		 * @param env The JNI environment
		 * @param signature The field signature
		 * @param value The value to set
		 * @return True on success, false on failure (check for exception)
		 * @throws Any exception thrown if the field recuperation fails.
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
			bool setStaticField(JNIEnv* env, Signature* signature, T& value)
			{
				private_namespace::staticFieldStructure_traits<T>::setStaticField(this, env, signature, value);
			}

	protected:
		virtual Field* getStaticFieldDescriptor(JNIEnv* env, Signature* signature) = 0;
		virtual jclass getJavaClass(JNIEnv* env) const = 0;
		virtual Class* getClass() = 0;

		inline Object getStaticObjectField(JNIEnv* env, Signature* signature);
		inline bool setStaticObjectField(JNIEnv* env, Signature* signature, Object& value);
	};

	/**
	 * Template specicalization for getStaticField.
	 */
	template <>
		jboolean StaticFieldStructure::getStaticField<jboolean>(JNIEnv* env, Signature* signature);
	template <>
		jbyte StaticFieldStructure::getStaticField<jbyte>(JNIEnv* env, Signature* signature);
	template <>
		jchar StaticFieldStructure::getStaticField<jchar>(JNIEnv* env, Signature* signature);
	template <>
		jshort StaticFieldStructure::getStaticField<jshort>(JNIEnv* env, Signature* signature);
	template <>
		jint StaticFieldStructure::getStaticField<jint>(JNIEnv* env, Signature* signature);
	template <>
		jlong StaticFieldStructure::getStaticField<jlong>(JNIEnv* env, Signature* signature);
	template <>
		jfloat StaticFieldStructure::getStaticField<jfloat>(JNIEnv* env, Signature* signature);
	template <>
		jdouble StaticFieldStructure::getStaticField<jdouble>(JNIEnv* env, Signature* signature);
	template <>
		Object StaticFieldStructure::getStaticField<Object>(JNIEnv* env, Signature* signature);
	template <>
		String StaticFieldStructure::getStaticField<String>(JNIEnv* env, Signature* signature);

	/**
	 * Template specicalization for setStaticField.
	 */
	template <>
		bool StaticFieldStructure::setStaticField<jboolean>(JNIEnv* env, Signature* signature, jboolean& value);
	template <>
		bool StaticFieldStructure::setStaticField<jbyte>(JNIEnv* env, Signature* signature, jbyte& value);
	template <>
		bool StaticFieldStructure::setStaticField<jchar>(JNIEnv* env, Signature* signature, jchar& value);
	template <>
		bool StaticFieldStructure::setStaticField<jshort>(JNIEnv* env, Signature* signature, jshort& value);
	template <>
		bool StaticFieldStructure::setStaticField<jint>(JNIEnv* env, Signature* signature, jint& value);
	template <>
		bool StaticFieldStructure::setStaticField<jlong>(JNIEnv* env, Signature* signature, jlong& value);
	template <>
		bool StaticFieldStructure::setStaticField<jfloat>(JNIEnv* env, Signature* signature, jfloat& value);
	template <>
		bool StaticFieldStructure::setStaticField<jdouble>(JNIEnv* env, Signature* signature, jdouble& value);
	template <>
		bool StaticFieldStructure::setStaticField<Object>(JNIEnv* env, Signature* signature, Object& value);
	template <>
		bool StaticFieldStructure::setStaticField<String>(JNIEnv* env, Signature* signature, String& value);

	namespace private_namespace
	{
		template <typename T>
			struct staticFieldStructure_traits
			{
				static T getStaticField(StaticFieldStructure* staticFieldStructure, JNIEnv* env, Signature* signature);
				static bool setStaticField(StaticFieldStructure* staticFieldStructure, JNIEnv* env, Signature* signature, T& value);
			};

		template <typename T>
			struct staticFieldStructure_traits< Array<T> >
			{
				static Array<T> getStaticField(StaticFieldStructure* staticFieldStructure, JNIEnv* env, Signature* signature);
				static bool setStaticField(StaticFieldStructure* staticFieldStructure, JNIEnv* env, Signature* signature, Array<T>& value);
			};
	}
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_STATICFIELDSTRUCTURE_HPP */

