#include "Object.hpp"
#include "JVM.hpp"

#include <cstdarg>

using namespace fr::Planquart::JNI;

Object::Object()
	:isGlobal{false}, classObject{0}, object{0}
{
}

Object::Object(Class* classObject, jobject object, bool isGlobal)
	:isGlobal{isGlobal}, classObject{classObject}, object{object}
{
}

Object::Object(const Object& object)
	:isGlobal{object.isGlobal}, classObject{object.classObject}
{
	this->object = JVM::getEnv()->NewLocalRef(object.object);
}

Object::Object(JNIEnv* env, Name* className, Signature* signature, ...)
	:isGlobal{false}, classObject{0}, object{0}
{
	this->classObject = Class::getClass(className, env);
	if (this->classObject != 0)
	{
		jclass clazz = this->classObject->getClassObject(env);
		if (clazz != 0)
		{
			Method* method = this->classObject->getMethod(env, signature);
			if (method != 0)
			{
				va_list arguments_list;
				va_start(arguments_list, signature);
				this->object = env->NewObjectV(clazz, method->methodID, arguments_list);
				va_end(arguments_list);
			}
		}
		else
		{
			this->classObject = 0;
		}
	}
}

Object::~Object()
{
	if (this->isValid())
	{
		return;
	}

	if (this->isGlobal)
	{
		JVM::getEnv()->DeleteWeakGlobalRef(this->object);
	}
	else
	{
		JVM::getEnv()->DeleteLocalRef(this->object);
	}
}

bool Object::isValid()
{
	if (this->classObject == 0 ||
		this->object == 0)
	{
		return false;
	}
	return true;
}

bool Object::isValid(JNIEnv* env)
{
	if (this->isValid())
	{
		if (env->IsSameObject(this->object, 0) == JNI_FALSE)
		{
			return true;
		}
		return false;
	}
	return false;
}

