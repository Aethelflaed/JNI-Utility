#include "Object.hpp"
#include <cstdarg>

using namespace fr::Planquart::JNI;

Object::Object(Class* classObject, jobject object);
	:classObject{classObject}, object{object}
{
}

Object::~Object()
{
	this->classObject.getEnv()->DeleteLocalRef(this->object);
}

