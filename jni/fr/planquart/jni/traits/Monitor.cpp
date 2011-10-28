#include "Monitor.hpp"
#include "Callable.hpp"

#include "../Class.hpp"
#include "../Method.hpp"

using ::fr::Planquart::JNI::Log;

namespace fr
{
namespace Planquart
{
namespace JNI
{
namespace traits
{
namespace private_namespace
{
	class MonitorCallable :
		public ::fr::Planquart::JNI::traits::Callable
	{
	public:
		typedef ::fr::Planquart::JNI::Class Class;
		typedef ::fr::Planquart::JNI::Method Method;;
		typedef ::fr::Planquart::JNI::Signature Signature;;

		Class* classObject;
		jobject javaObject;

		virtual Method* getMethodDescriptor(JNIEnv* env, Signature* signature)
		{
			if (this->classObject = 0)
			{
				return 0;
			}
			return this->classObject->getMethod(env, signature);
		}

		virtual jobject getJavaObject(JNIEnv* env) const
		{
			return env->NewLocalRef(this->javaObject);;
		}

		virtual Class* getClass()
		{
			return this->classObject;
		}
	};
}
}
}
}
}

using namespace fr::Planquart::JNI::traits;

bool Monitor::synchronize(JNIEnv* env)
{
	if (this->synchronized)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();
	jobject javaObject = object.getJavaObject(env);

	if (env->MonitorEnter(javaObject) != JNI_OK)
	{
		env->DeleteLocalRef(javaObject);
		return false;
	}
	env->DeleteLocalRef(javaObject);

	object.lock((int)this);
	this->synchronized = true;
	return true;
}

bool Monitor::desynchronize(JNIEnv* env)
{
	if (this->synchronized == false)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();
	jobject javaObject = object.getJavaObject(env);

	if (env->MonitorExit(javaObject) != JNI_OK)
	{
		env->DeleteLocalRef(javaObject);
		return false;
	}
	env->DeleteLocalRef(javaObject);

	object.unlock((int)this);
	this->synchronized = false;
	return true;
}

bool Monitor::notify(JNIEnv* env)
{
	if (this->synchronized == false)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();

	private_namespace::MonitorCallable callable;
	callable.classObject = ::fr::Planquart::JNI::Class::getClass(
			::fr::Planquart::JNI::JVM::class_Object, env);
	callable.javaObject = object.getJavaObject(env);

	callable.callMethod<void>(env, ::fr::Planquart::JNI::JVM::method_Object_notify);
	if (env->ExceptionCheck() != JNI_OK)
	{
		env->DeleteLocalRef(callable.javaObject);
		return false;
	}

	env->DeleteLocalRef(callable.javaObject);
	return true;
}

bool Monitor::notifyAll(JNIEnv* env)
{
	if (this->synchronized == false)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();

	private_namespace::MonitorCallable callable;
	callable.classObject = ::fr::Planquart::JNI::Class::getClass(
			::fr::Planquart::JNI::JVM::class_Object, env);
	callable.javaObject = object.getJavaObject(env);

	callable.callMethod<void>(env, ::fr::Planquart::JNI::JVM::method_Object_notifyAll);
	if (env->ExceptionCheck() != JNI_OK)
	{
		env->DeleteLocalRef(callable.javaObject);
		return false;
	}

	env->DeleteLocalRef(callable.javaObject);
	return true;
}

bool Monitor::wait(JNIEnv* env)
{
	if (this->synchronized == false)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();

	private_namespace::MonitorCallable callable;
	callable.classObject = ::fr::Planquart::JNI::Class::getClass(
			::fr::Planquart::JNI::JVM::class_Object, env);
	callable.javaObject = object.getJavaObject(env);

	callable.callMethod<void>(env, ::fr::Planquart::JNI::JVM::method_Object_wait);
	if (env->ExceptionCheck() != JNI_OK)
	{
		env->DeleteLocalRef(callable.javaObject);
		return false;
	}

	env->DeleteLocalRef(callable.javaObject);
	return true;
}

bool Monitor::wait(JNIEnv* env, jlong millis)
{
	if (this->synchronized == false)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();

	private_namespace::MonitorCallable callable;
	callable.classObject = ::fr::Planquart::JNI::Class::getClass(
			::fr::Planquart::JNI::JVM::class_Object, env);
	callable.javaObject = object.getJavaObject(env);

	callable.callMethod<void>(env, ::fr::Planquart::JNI::JVM::method_Object_wait_L, millis);
	if (env->ExceptionCheck() != JNI_OK)
	{
		env->DeleteLocalRef(callable.javaObject);
		return false;
	}

	env->DeleteLocalRef(callable.javaObject);
	return true;
}

bool Monitor::wait(JNIEnv* env, jlong millis, jint nanos)
{
	if (this->synchronized == false)
	{
		return true;
	}

	JavaObjectWrapper& object = this->getObjectWrapper();

	private_namespace::MonitorCallable callable;
	callable.classObject = ::fr::Planquart::JNI::Class::getClass(
			::fr::Planquart::JNI::JVM::class_Object, env);
	callable.javaObject = object.getJavaObject(env);

	callable.callMethod<void>(env, ::fr::Planquart::JNI::JVM::method_Object_wait_LI, millis, nanos);
	if (env->ExceptionCheck() != JNI_OK)
	{
		env->DeleteLocalRef(callable.javaObject);
		return false;
	}

	env->DeleteLocalRef(callable.javaObject);
	return true;
}

