#include "Class.hpp"
#include "JVM.hpp"

using namespace fr::Planquart::JNI;

Class::classes_map Class::classes{};

Class* Class::getClass(const char* className)
{
	Class::classes_map::iterator it = Class::classes.find(className);
	if (it == Class::classes.end())
	{
		return 0;
	}
	return it->second;
}

Class* Class::getClass(const char* className, JNIEnv* env)
{
	Class* classObject = Class::classes[className];
	if (classObject == 0)
	{
		classObject = new Class{env, className};
		Class::classes[className] = classObject;
		return classObject;
	}
	return classObject;
}

Class::Class(JNIEnv* env, const char* className)
	:className{className}
{
	jclass classObject = env->FindClass(className);
	if (classObject == 0)
	{
		/* ClassNotFoundException or OutOfMemoryException */
		return;
	}
	this->classObject = static_cast<jclass>(env->NewWeakGlobalRef(classObject));
	env->DeleteLocalRef(classObject);
}

Class::~Class()
{
	if (this->classObject != 0)
	{
		this->release(JVM::getEnv());
	}
}

void Class::remove()
{
	Class::classes[this->className] = 0;

	delete this;
}

void Class::releaseAll(JNIEnv* env)
{
	Class::classes_map::iterator it = Class::classes.begin();
	if (it->second != 0)
	{
		it->second->release(env);
		delete it->second;
	}
	Class::classes.erase(it);
}

