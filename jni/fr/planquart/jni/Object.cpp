#include "Object.hpp"

using namespace fr::Planquart::JNI;

Object::Object(jobject object, Class& classObject)
	:object{object}, classObject{classObject}
{
}

Object::~Object()
{
	this->classObject.getEnv()->DeleteLocalRef(this->object);
}

