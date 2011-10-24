#include "StaticCallable.hpp"

#include "../Method.hpp"
#include "../Object.hpp"
#include "../Signature.hpp"
#include "../Class.hpp"
#include "../JVM.hpp"

using namespace fr::Planquart::JNI::traits;

inline ::fr::Planquart::JNI::Object StaticCallable::callStaticObjectMethodV(JNIEnv* env, Signature* signature, va_list arguments_list)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		jclass object = this->getJavaClass(env);
		jobject value;
		if (object != 0)
		{
			value = env->CallStaticObjectMethodV(object, method->getMethodID(), arguments_list);
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
void StaticCallable::callStaticMethod<void>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		env->CallStaticVoidMethodV(object, method->getMethodID(), arguments_list);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jboolean value;
		if (object != 0)
		{
			value = env->CallStaticBooleanMethodV(object, method->getMethodID(), arguments_list);
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
jbyte StaticCallable::callStaticMethod<jbyte>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jbyte value;
		if (object != 0)
		{
			value = env->CallStaticByteMethodV(object, method->getMethodID(), arguments_list);
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
jchar StaticCallable::callStaticMethod<jchar>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jchar value;
		if (object != 0)
		{
			value = env->CallStaticCharMethodV(object, method->getMethodID(), arguments_list);
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
jshort StaticCallable::callStaticMethod<jshort>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jshort value;
		if (object != 0)
		{
			value = env->CallStaticShortMethodV(object, method->getMethodID(), arguments_list);
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
jint StaticCallable::callStaticMethod<jint>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jint value;
		if (object != 0)
		{
			value = env->CallStaticIntMethodV(object, method->getMethodID(), arguments_list);
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
jlong StaticCallable::callStaticMethod<jlong>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jlong value;
		if (object != 0)
		{
			value = env->CallStaticLongMethodV(object, method->getMethodID(), arguments_list);
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
jfloat StaticCallable::callStaticMethod<jfloat>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jfloat value;
		if (object != 0)
		{
			value = env->CallStaticFloatMethodV(object, method->getMethodID(), arguments_list);
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
jdouble StaticCallable::callStaticMethod<jdouble>(JNIEnv* env, Signature* signature, ...)
{
	Method* method = this->getStaticMethodDescriptor(env, signature);
	if (method != 0)
	{
		va_list arguments_list;
		va_start(arguments_list, signature);
		jclass object = this->getJavaClass(env);
		jdouble value;
		if (object != 0)
		{
			value = env->CallStaticDoubleMethodV(object, method->getMethodID(), arguments_list);
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
::fr::Planquart::JNI::Object StaticCallable::callStaticMethod< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ...)
{
	va_list arguments_list;
	va_start(arguments_list, signature);
	Object object = this->callStaticObjectMethodV(env, signature, arguments_list);
	va_end(arguments_list);
	return object;
}

