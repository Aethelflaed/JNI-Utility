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
	this->release(JVM::getEnv());
}

