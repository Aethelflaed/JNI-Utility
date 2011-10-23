#include "Field.hpp"
#include "Class.hpp"

using namespace fr::Planquart::JNI;

Field::Field(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic)
	:fieldID{0}
{
	jclass clazz = classObject->getClassObject(env);
	if (clazz == 0)
	{
		return;
	}
	if (isStatic)
	{
		this->fieldID = env->GetStaticFieldID(
				clazz,
				signature->getName(),
				signature->getType());
	}
	else
	{
		this->fieldID = env->GetFieldID(
				clazz,
				signature->getName(),
				signature->getType());
	}
}

