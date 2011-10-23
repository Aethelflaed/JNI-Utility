#include "String.hpp"
#include "JVM.hpp"

#include <cstdio>

using namespace fr::Planquart::JNI;

String::String(JNIEnv* env, Signature* signature, ...)
	:Object{env, JVM::class_String, signature}
{
}

char* String::getCUTFString(JNIEnv* env)
{
	jstring javaString = static_cast<jstring>(this->getJavaObject(env));

	jint length = env->GetStringLength(javaString);
	char* string = (char*) malloc(sizeof(char) * length);
	env->GetStringUTFRegion(javaString, 0, length, string);

	env->DeleteLocalRef(javaString);
	return string;
}

