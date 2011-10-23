#include "Callable.hpp"

#include "../Method.hpp"
#include "../Object.hpp"
#include "../Signature.hpp"
#include "../Class.hpp"

using namespace fr::Planquart::JNI::traits;

inline ::fr::Planquart::JNI::Object Callable::callObjectMethodV(JNIEnv* env, Signature* signature, va_list arguments_list)
{
	Method* method = this->getMethodDescriptor(env, signature);
	if (method != 0)
	{
		jobject value = env->CallObjectMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);

		return Object(this->getClass(), value);
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
		env->CallVoidMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jboolean value = env->CallBooleanMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jbyte value = env->CallByteMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jchar value = env->CallCharMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jshort value = env->CallShortMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jint value = env->CallIntMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jlong value = env->CallLongMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jfloat value = env->CallFloatMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
		jdouble value = env->CallDoubleMethodV(this->getJavaObject(), method->getMethodID(), arguments_list);
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
	return this->callObjectMethodV(env, signature, arguments_list);
	va_end(arguments_list);
}

