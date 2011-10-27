#include "String.hpp"
#include "JVM.hpp"

#include <cstdio>
#include <cstring>

using namespace fr::Planquart::JNI;

String::String(JNIEnv* env, Signature* signature, ...)
	:Object{env, JVM::class_String, signature}
{
}

String::String(JNIEnv* env, const char* string)
	:Object{}
{
	this->classObject = Class::getClass(JVM::class_String, env);
	if (this->classObject != 0)
	{
		jclass clazz = this->classObject->getClassObject(env);
		if (clazz != 0)
		{
			jbyteArray bytes;
			jint length;

			length = strlen(string);
			bytes = env->NewByteArray(length);

			if (bytes != 0)
			{
				env->SetByteArrayRegion(bytes, 0, length, (jbyte*)string);

				Method* method = this->classObject->getMethod(env, JVM::ctor_String__3B);
				if (method != 0)
				{
					this->setJavaObject(env->NewObject(clazz, method->getMethodID(), bytes));
				}

				env->DeleteLocalRef(bytes);
			}
		}
		else
		{
			this->classObject = 0;
		}
	}
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
	jstring javaString = this->getJavaObject(env);

	jint length = env->GetStringLength(javaString);

	char* string = (char*) malloc(sizeof(char) * length);
	env->GetStringUTFRegion(javaString, 0, length, string);

	env->DeleteLocalRef(javaString);
	return string;
}

