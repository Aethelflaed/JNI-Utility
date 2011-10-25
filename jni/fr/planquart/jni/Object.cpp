#include "Object.hpp"
#include "JVM.hpp"

#include <cstdarg>

using namespace fr::Planquart::JNI;

Object::Object()
	:classObject{0}
{
}

Object::Object(Class* classObject, jobject object)
	:classObject{classObject}
{
	this->setJavaObject(object);
}

Object::Object(const Object& object)
	:classObject{object.classObject}
{
	this->setJavaObject(object.getJavaObject(JVM::getEnv()));
}

Object::Object(JNIEnv* env, Name* className, Signature* signature, ...)
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
				this->setJavaObject(env->NewObjectV(clazz, method->getMethodID(), arguments_list));
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
	if (this->isValid() == false)
	{
		return;
	}

	JVM::getEnv()->DeleteLocalRef(traits::JavaObjectWrapper::getJavaObject());
}

bool Object::isValid()
{
	return traits::JavaObjectWrapper::isValid() &&
		this->classObject != 0;
}

