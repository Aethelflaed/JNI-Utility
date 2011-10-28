#ifndef FR_PLANQUART_JNI_TRAITS_FIELDSTRUCTURE_HPP
#define FR_PLANQUART_JNI_TRAITS_FIELDSTRUCTURE_HPP

#include <jni.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
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
			struct fieldStructure_traits;
	}

	class FieldStructure
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
			T getField(JNIEnv* env, Signature* signature)
			{
				private_namespace::fieldStructure_traits<T>::getField(this, env, signature);
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
			bool setField(JNIEnv* env, Signature* signature, T& value)
			{
				private_namespace::fieldStructure_traits<T>::setField(this, env, signature, value);
			}

	protected:
		virtual Field* getFieldDescriptor(JNIEnv* env, Signature* signature) = 0;
		virtual jobject getJavaObject(JNIEnv* env) const = 0;

		inline Object getObjectField(JNIEnv* env, Signature* signature);
		inline bool setObjectField(JNIEnv* env, Signature* signature, Object& value);
	};

	/**
	 * Template specicalization for getField.
	 */
	template <>
		jboolean FieldStructure::getField<jboolean>(JNIEnv* env, Signature* signature);
	template <>
		jbyte FieldStructure::getField<jbyte>(JNIEnv* env, Signature* signature);
	template <>
		jchar FieldStructure::getField<jchar>(JNIEnv* env, Signature* signature);
	template <>
		jshort FieldStructure::getField<jshort>(JNIEnv* env, Signature* signature);
	template <>
		jint FieldStructure::getField<jint>(JNIEnv* env, Signature* signature);
	template <>
		jlong FieldStructure::getField<jlong>(JNIEnv* env, Signature* signature);
	template <>
		jfloat FieldStructure::getField<jfloat>(JNIEnv* env, Signature* signature);
	template <>
		jdouble FieldStructure::getField<jdouble>(JNIEnv* env, Signature* signature);
	template <>
		Object FieldStructure::getField<Object>(JNIEnv* env, Signature* signature);
	template <>
		String FieldStructure::getField<String>(JNIEnv* env, Signature* signature);

	/**
	 * Template specicalization for setField.
	 */
	template <>
		bool FieldStructure::setField<jboolean>(JNIEnv* env, Signature* signature, jboolean& value);
	template <>
		bool FieldStructure::setField<jbyte>(JNIEnv* env, Signature* signature, jbyte& value);
	template <>
		bool FieldStructure::setField<jchar>(JNIEnv* env, Signature* signature, jchar& value);
	template <>
		bool FieldStructure::setField<jshort>(JNIEnv* env, Signature* signature, jshort& value);
	template <>
		bool FieldStructure::setField<jint>(JNIEnv* env, Signature* signature, jint& value);
	template <>
		bool FieldStructure::setField<jlong>(JNIEnv* env, Signature* signature, jlong& value);
	template <>
		bool FieldStructure::setField<jfloat>(JNIEnv* env, Signature* signature, jfloat& value);
	template <>
		bool FieldStructure::setField<jdouble>(JNIEnv* env, Signature* signature, jdouble& value);
	template <>
		bool FieldStructure::setField<Object>(JNIEnv* env, Signature* signature, Object& value);
	template <>
		bool FieldStructure::setField<String>(JNIEnv* env, Signature* signature, String& value);

	namespace private_namespace
	{
		template <typename T>
			struct fieldStructure_traits
			{
				static T getField(FieldStructure* fieldStructure, JNIEnv* env, Signature* signature);
				static bool setField(FieldStructure* fieldStructure, JNIEnv* env, Signature* signature, T& value);
			};

		template <typename T>
			struct fieldStructure_traits< Array<T> >
			{
				static Array<T> getField(FieldStructure* fieldStructure, JNIEnv* env, Signature* signature);
				static bool setField(FieldStructure* fieldStructure, JNIEnv* env, Signature* signature, Array<T>& value);
			};
	}
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_FIELDSTRUCTURE_HPP */

