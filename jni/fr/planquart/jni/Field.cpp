#include "Field.hpp"
#include "Class.hpp"

using namespace fr::Planquart::JNI;

Field::Field(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic)
	:classObject{classObject}, signature{signature}, _static{isStatic}
{
	if (_static)
	{
		this->fieldID = env->GetStaticFieldID(
				this->classObject->getClassObject(env),
				this->signature->getName(),
				this->signature->getType());
	}
	else
	{
		this->fieldID = env->GetFieldID(
				this->classObject->getClassObject(env),
				this->signature->getName(),
				this->signature->getType());
	}
}

