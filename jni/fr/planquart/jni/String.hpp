#ifndef FR_PLANQUART_JNI_STRING_HPP
#define FR_PLANQUART_JNI_STRING_HPP

#include <jni.h>

#include <string>

#include "Object.hpp"
#include "Class.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This class is an abstract representation of a Java string.
	 */
	class String : public Object
	{
	public:
		/**
		 * Same constructor as Object, see object
		 */
		String(JNIEnv* env, Signature* signature, ...);

		/**
		 * Create a Java String representation from a C string
		 *
		 * Requires 2 local reference, one freed and the other owned by
		 * the object.
		 *
		 * @param env The JNI environment
		 * @param string The C string
		 * @throws OutOfMemoryError
		 */
		String(JNIEnv* env, const char* string);

		/**
		 * Return a std::string corresponding to the Java String.
		 * The strin is copied as an UTF8 string.
		 *
		 * @param env The JNI environment
		 * @return A std::wstring
		 * @throws OutOfMemoryError
		 */
		std::string getUTFString(JNIEnv* env);

		/**
		 * Return a head-allocated C character array corresponding to the
		 * Java String. The string is copied as an UTF8 string.
		 *
		 * Requires one local reference, freed.
		 *
		 * @param env The JNI environment
		 * @return A manually allocated C string, which has to be freed.
		 * @throws OutOfMemoryError
		 */
		char* getCUTFString(JNIEnv* env);

		virtual jstring getJavaObject(JNIEnv* env) const
		{
			return static_cast<jstring>(this->Object::getJavaObject(env));
		}
	};
}
}
}

#endif /* FR_PLANQUART_JNI_STRING_HPP */

