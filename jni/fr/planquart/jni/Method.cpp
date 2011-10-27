#include "Method.hpp"
#include "Class.hpp"

using namespace fr::Planquart::JNI;

Method::Method(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic)
	:methodID{0}
{
	jclass clazz = classObject->getClassObject(env);
	if (clazz == 0)
	{
		return;
	}
	if (isStatic)
	{
		this->methodID = env->GetStaticMethodID(
				clazz,
				signature->getName(),
				signature->getType());
	}
	else
	{
		this->methodID = env->GetMethodID(
				clazz,
				signature->getName(),
				signature->getType());
	}
	env->DeleteLocalRef(clazz);
}

