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
		String(JNIEnv* env, Signature* signature, ...);

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

	};
}
}
}

#endif /* FR_PLANQUART_JNI_STRING_HPP */

