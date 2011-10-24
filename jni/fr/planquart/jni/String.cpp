#include "String.hpp"
#include "JVM.hpp"

#include <cstdio>

using namespace fr::Planquart::JNI;

String::String(JNIEnv* env, Signature* signature, ...)
	:Object{env, JVM::class_String, signature}
{
}

std::string String::getUTFString(JNIEnv* env)
{
	char* c_string = this->getCUTFString(env);
	std::string string(c_string);
	free(c_string);

	return string;
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

