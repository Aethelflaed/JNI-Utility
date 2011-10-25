#include "Class.hpp"
#include "Object.hpp"
#include "JVM.hpp"

#include <cstdarg>

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
	Class* classInstance = Class::classes[className];
	if (classInstance == 0)
	{
		classInstance = new Class{env, className};
		Class::classes[className] = classInstance;
	}
	return classInstance;
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
	this->setJavaObject(env->NewWeakGlobalRef(classObject));
	env->DeleteLocalRef(classObject);
}

Class::~Class()
{
	if (traits::JavaObjectWrapper::getJavaObject() != 0)
	{
		this->release(JVM::getEnv());
	}
	fields_map::iterator fieldIterator = this->fields.begin();
	while (fieldIterator != this->fields.end())
	{
		delete fieldIterator->second;
		fieldIterator++;
	}
	fieldIterator = this->static_fields.begin();
	while (fieldIterator != this->static_fields.end())
	{
		delete fieldIterator->second;
		fieldIterator++;
	}
	methods_map::iterator methodIterator = this->methods.begin();
	while (methodIterator != this->methods.end())
	{
		delete methodIterator->second;
		methodIterator++;
	}
	methodIterator = this->static_methods.begin();
	while (methodIterator != this->static_methods.end())
	{
		delete methodIterator->second;
		methodIterator++;
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

Method* Class::getStaticMethod(JNIEnv* env, Signature* signature)
{
	Method* method = this->static_methods[signature];
	if (method == 0 && env != 0)
	{
		method = new Method(env, this, signature, true);
		if (method->getMethodID() == 0)
		{
			delete method;
			return 0;
		}
		this->static_methods[signature] = method;
	}
	return method;
}

Method* Class::getMethod(JNIEnv* env, Signature* signature)
{
	Method* method = this->methods[signature];
	if (method == 0 && env != 0)
	{
		method = new Method(env, this, signature);
		if (method->getMethodID() == 0)
		{
			delete method;
			return 0;
		}
		this->methods[signature] = method;
	}
	return method;
}

Field* Class::getStaticField(JNIEnv* env, Signature* signature)
{
	Field* field = this->static_fields[signature];
	if (field == 0 && env != 0)
	{
		field = new Field(env, this, signature, true);
		if (field->getFieldID() == 0)
		{
			delete field;
			return 0;
		}
		this->static_fields[signature] = field;
	}
	return field;
}

Field* Class::getField(JNIEnv* env, Signature* signature)
{
	Field* field = this->fields[signature];
	if (field == 0 && env != 0)
	{
		field = new Field(env, this, signature);
		if (field->getFieldID() == 0)
		{
			delete field;
			return 0;
		}
		this->fields[signature] = field;
	}
	return field;
}

