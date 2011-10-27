#include "Callable.hpp"

#include "../Method.hpp"
#include "../Object.hpp"
#include "../Signature.hpp"
#include "../Class.hpp"
#include "../JVM.hpp"

using namespace fr::Planquart::JNI::traits;

inline ::fr::Planquart::JNI::Object Callable::callObjectMethodV(JNIEnv* env, Signature* signature, va_list arguments_list)
{
	Method* method = this->getMethodDescriptor(env, signature);

	if (method != 0)
	{
		jobject object = this->getJavaObject(env);
		jobject value;

		if (object != 0)
		{
			value = env->CallObjectMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return Object();
		}
		env->DeleteLocalRef(object);

		return Object(Class::getClass(JVM::class_Object, env), value);
	}
	return Object();
}

template <>
void Callable::callMethod<void>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		env->CallVoidMethodV(object, method->getMethodID(), arguments_list);
		env->DeleteLocalRef(object);
		va_end(arguments_list);
	}
}

template <>
jboolean Callable::callMethod<jboolean>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jboolean value;
		if (object != 0)
		{
			value = env->CallBooleanMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jbyte Callable::callMethod<jbyte>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jbyte value;
		if (object != 0)
		{
			value = env->CallByteMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jchar Callable::callMethod<jchar>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jchar value;
		if (object != 0)
		{
			value = env->CallCharMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jshort Callable::callMethod<jshort>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jshort value;
		if (object != 0)
		{
			value = env->CallShortMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jint Callable::callMethod<jint>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jint value;
		if (object != 0)
		{
			value = env->CallIntMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jlong Callable::callMethod<jlong>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jlong value;
		if (object != 0)
		{
			value = env->CallLongMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jfloat Callable::callMethod<jfloat>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jfloat value;
		if (object != 0)
		{
			value = env->CallFloatMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jdouble Callable::callMethod<jdouble>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jobject object = this->getJavaObject(env);
		jdouble value;
		if (object != 0)
		{
			value = env->CallDoubleMethodV(object, method->getMethodID(), arguments_list);
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
::fr::Planquart::JNI::Object Callable::callMethod< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ...)
{
	va_list arguments_list;
	va_start(arguments_list, signature);
	Object object = this->callObjectMethodV(env, signature, arguments_list);
	va_end(arguments_list);
	return object;
}

