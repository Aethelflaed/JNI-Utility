#include "Exception.hpp"

using namespace fr::Planquart::JNI;

void Exception::Throw(JNIEnv* env, const char* name, const char* msg)
{
	jclass exceptionClass = env->FindClass(name);
	/* if exceptionClass is 0, an exception has already been thrown */
	if (exceptionClass != 0)
	{
		env->ThrowNew(exceptionClass, msg);
	}
	/* free the local ref */
	env->DeleteLocalRef(exceptionClass);
}

