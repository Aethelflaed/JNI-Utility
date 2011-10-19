#include "Class.hpp"
#include "JVM.hpp"

using namespace fr::Planquart::JNI;

Class::classes_map Class::classes{};

Class* Class::getClass(Name* className)
{
	Class::classes_map::iterator it = Class::classes.find(className);
	if (it == Class::classes.end())
	{
		return 0;
	}
	return it->second;
}

Class* Class::getClass(Name* className, JNIEnv* env)
{
	Class* classObject = Class::classes[className];
	if (classObject == 0)
	{
		classObject = new Class{env, className};
		Class::classes[className] = classObject;
	}
	return classObject;
}

Class::Class(JNIEnv* env, Name* className)
	:className{className}, static_fields{}, fields{}, static_methods{}, methods{}
{
	jclass classObject = env->FindClass(className->getName());
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

Method* Class::getStaticMethodID(JNIEnv* env, Signature* signature, bool create)
{
	Method* method = this->static_methods[signature];
	if (method == 0 && create == true)
	{
		method = new Method(env, this, signature, true);
		this->static_methods[signature] = method;
	}
	return method;
}

Method* Class::getMethodID(JNIEnv* env, Signature* signature, bool create)
{
	Method* method = this->methods[signature];
	if (method == 0 && create == true)
	{
		method = new Method(env, this, signature);
		this->methods[signature] = method;
	}
	return method;
}

Field* Class::getStaticFieldID(JNIEnv* env, Signature* signature, bool create)
{
	Field* field = this->static_fields[signature];
	if (field == 0 && create == true)
	{
		field = new Field(env, this, signature, true);
		this->static_fields[signature] = field;
	}
	return field;
}

Field* Class::getFieldID(JNIEnv* env, Signature* signature, bool create)
{
	Field* field = this->fields[signature];
	if (field == 0 && create == true)
	{
		field = new Field(env, this, signature);
		this->fields[signature] = field;
	}
	return field;
}

