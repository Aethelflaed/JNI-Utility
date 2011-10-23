#include "String.hpp"
#include "JVM.hpp"

using namespace fr::Planquart::JNI;

String::String(JNIEnv* env, Signature* signature, ...)
	:Object{env, JVM::class_String, signature}
{
}

