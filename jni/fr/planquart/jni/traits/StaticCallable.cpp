#include "StaticCallable.hpp"

#include "../Method.hpp"
#include "../Object.hpp"
#include "../Signature.hpp"
#include "../Class.hpp"

using namespace fr::Planquart::JNI::traits;

inline ::fr::Planquart::JNI::Object StaticCallable::callStaticObjectMethodV(JNIEnv* env, Signature* signature, va_list arguments_list)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		jobject value = env->CallStaticObjectMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);

		return Object(this->getClass(), value);
	}
	return Object();
}


template <>
void StaticCallable::callStaticMethod<void>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		env->CallStaticVoidMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
	}
}

template <>
jboolean StaticCallable::callStaticMethod<jboolean>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jboolean value = env->CallStaticBooleanMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jbyte StaticCallable::callStaticMethod<jbyte>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jbyte value = env->CallStaticByteMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jchar StaticCallable::callStaticMethod<jchar>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jchar value = env->CallStaticCharMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jshort StaticCallable::callStaticMethod<jshort>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jshort value = env->CallStaticShortMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jint StaticCallable::callStaticMethod<jint>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jint value = env->CallStaticIntMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jlong StaticCallable::callStaticMethod<jlong>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jlong value = env->CallStaticLongMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jfloat StaticCallable::callStaticMethod<jfloat>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jfloat value = env->CallStaticFloatMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
jdouble StaticCallable::callStaticMethod<jdouble>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jdouble value = env->CallStaticDoubleMethodV(this->getJavaClass(), method->getMethodID(), arguments_list);
		va_end(arguments_list);
		return value;
	}
	return 0;
}

template <>
::fr::Planquart::JNI::Object StaticCallable::callStaticMethod< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ...)
{
	va_list arguments_list;
	va_start(arguments_list, signature);
	return this->callStaticObjectMethodV(env, signature, arguments_list);
	va_end(arguments_list);
}

