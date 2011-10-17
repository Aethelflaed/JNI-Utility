#include "Class.hpp"

using namespace fr::Planquart::JNI;

Class::Class(JNIEnv* env, char* className)
	:env{env}, classObject{env->FindClass(className)}
{
}

Class::~Class()
{
	this->env->DeleteLocalRef(this->classObject);
}

