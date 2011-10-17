#ifndef FR_PLANQUART_JNI_EXCEPTION_HPP
#define FR_PLANQUART_JNI_EXCEPTION_HPP

#include <jni.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Exception
	{
	public:
		/**
		 * Throw a new Java exception given its name.
		 * @param env The JNI environement
		 * @param name The exception class name
		 * @param msg The exception message to pass to the constructor
		 * @throws exception The exception which class is given as param
		 */
		static void Throw(JNIEnv* env, const char* name, const char* msg);
	};
}
}
}

#endif /* FR_PLANQUART_JNI_EXCEPTION_HPP */

