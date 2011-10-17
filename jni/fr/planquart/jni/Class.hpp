#ifndef FR_PLANQUART_JNI_CLASS_HPP
#define FR_PLANQUART_JNI_CLASS_HPP

#include <jni.h>
#include "cxx/pair.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Class
	{
	public:
		Class(JNIEnv* env, char* className);
		~Class();

		/**
		 * Get a Java method identifier
		 * @param methodName The name of the method
		 * @param methodSignature The signature of the method
		 * @return A Java method identifier
		 */
		jmethodID getMethodID(const char* methodName, const char* methodSignature);

		/**
		 * Get the JNI environment.
		 * @return The JNI environment
		 */
		JNIEnv* getEnv()
		{
			return this->env;
		}
	private:
		JNIEnv* env;
		jclass classObject;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_CLASS_HPP */

