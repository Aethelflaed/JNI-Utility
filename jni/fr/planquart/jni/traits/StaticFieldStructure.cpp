#include "StaticFieldStructure.hpp"

#include "../Field.hpp"
#include "../Object.hpp"
#include "../Signature.hpp"
#include "../Class.hpp"

using namespace fr::Planquart::JNI::traits;

inline ::fr::Planquart::JNI::Object StaticFieldStructure::getStaticObjectField(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject value = env->GetStaticObjectField(this->getJavaClass(), field->getFieldID());
		return Object(this->getClass(), value);
	}
	return Object();
}

inline bool StaticFieldStructure::setStaticObjectField(JNIEnv* env, Signature* signature, Object& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticObjectField(this->getJavaClass(), field->getFieldID(), value.getJavaObject());
		return true;
	}
	return false;
}

template <>
jboolean StaticFieldStructure::getStaticField<jboolean>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jboolean value = env->GetStaticBooleanField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jbyte StaticFieldStructure::getStaticField<jbyte>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jbyte value = env->GetStaticByteField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jchar StaticFieldStructure::getStaticField<jchar>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jchar value = env->GetStaticCharField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jshort StaticFieldStructure::getStaticField<jshort>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jshort value = env->GetStaticShortField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jint StaticFieldStructure::getStaticField<jint>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jint value = env->GetStaticIntField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jlong StaticFieldStructure::getStaticField<jlong>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jlong value = env->GetStaticLongField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jfloat StaticFieldStructure::getStaticField<jfloat>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jfloat value = env->GetStaticFloatField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jdouble StaticFieldStructure::getStaticField<jdouble>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jdouble value = env->GetStaticDoubleField(this->getJavaClass(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
::fr::Planquart::JNI::Object StaticFieldStructure::getStaticField< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature)
{
	return this->getStaticObjectField(env, signature);
}

template <>
bool StaticFieldStructure::setStaticField<jboolean>(JNIEnv* env, Signature* signature, jboolean& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticBooleanField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jbyte>(JNIEnv* env, Signature* signature, jbyte& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticByteField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jchar>(JNIEnv* env, Signature* signature, jchar& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticCharField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jshort>(JNIEnv* env, Signature* signature, jshort& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticShortField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jint>(JNIEnv* env, Signature* signature, jint& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticIntField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jlong>(JNIEnv* env, Signature* signature, jlong& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticLongField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jfloat>(JNIEnv* env, Signature* signature, jfloat& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticFloatField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField<jdouble>(JNIEnv* env, Signature* signature, jdouble& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetStaticDoubleField(this->getJavaClass(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool StaticFieldStructure::setStaticField< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ::fr::Planquart::JNI::Object& value)
{
	return this->setStaticObjectField(env, signature, value);
}

