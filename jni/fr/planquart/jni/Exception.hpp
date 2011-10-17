#ifndef FR_PLANQUART_JNI_EXCEPTION_HPP
#define FR_PLANQUART_JNI_EXCEPTION_HPP

#include <jni.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * @author Geoffroy PLANQUART <geoffroy@planquart.fr>
	 *
	 * Manages JNI exceptions
	 */
	class Exception
	{
	public:
		/**
		 * Throw a new Java exception given its name.
		 *
		 * Requires one local reference, released after use.
		 *
		 * @param env The JNI environement
		 * @param name The exception class name
		 * @param msg The exception message to pass to the constructor
		 * @throws The exception which class is given as param
		 */
		static void throwByName(JNIEnv* env, const char* name, const char* msg)
		{
			jclass exceptionClass = env->FindClass(name);
			if (exceptionClass != 0)
			{
				env->ThrowNew(exceptionClass, msg);
			}
			env->DeleteLocalRef(exceptionClass);
		}
	};
}
}
}

#endif /* FR_PLANQUART_JNI_EXCEPTION_HPP */

