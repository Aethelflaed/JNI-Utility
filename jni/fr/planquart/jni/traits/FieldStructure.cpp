#include "FieldStructure.hpp"

#include "../Field.hpp"
#include "../Object.hpp"
#include "../Signature.hpp"
#include "../Class.hpp"

using namespace fr::Planquart::JNI::traits;

inline ::fr::Planquart::JNI::Object FieldStructure::getObjectField(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject value = env->GetObjectField(this->getJavaObject(), field->getFieldID());
		return Object(this->getClass(), value);
	}
	return Object();
}

inline bool FieldStructure::setObjectField(JNIEnv* env, Signature* signature, Object& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetObjectField(this->getJavaObject(), field->getFieldID(), value.getJavaObject());
		return true;
	}
	return false;
}

template <>
jboolean FieldStructure::getField<jboolean>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jboolean value = env->GetBooleanField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jbyte FieldStructure::getField<jbyte>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jbyte value = env->GetByteField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jchar FieldStructure::getField<jchar>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jchar value = env->GetCharField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jshort FieldStructure::getField<jshort>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jshort value = env->GetShortField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jint FieldStructure::getField<jint>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jint value = env->GetIntField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jlong FieldStructure::getField<jlong>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jlong value = env->GetLongField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jfloat FieldStructure::getField<jfloat>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jfloat value = env->GetFloatField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
jdouble FieldStructure::getField<jdouble>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jdouble value = env->GetDoubleField(this->getJavaObject(), field->getFieldID());
		return value;
	}
	return 0;
}

template <>
::fr::Planquart::JNI::Object FieldStructure::getField< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature)
{
	return this->getObjectField(env, signature);
}

template <>
bool FieldStructure::setField<jboolean>(JNIEnv* env, Signature* signature, jboolean& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetBooleanField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jbyte>(JNIEnv* env, Signature* signature, jbyte& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetByteField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jchar>(JNIEnv* env, Signature* signature, jchar& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetCharField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jshort>(JNIEnv* env, Signature* signature, jshort& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetShortField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jint>(JNIEnv* env, Signature* signature, jint& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetIntField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jlong>(JNIEnv* env, Signature* signature, jlong& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetLongField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jfloat>(JNIEnv* env, Signature* signature, jfloat& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetFloatField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField<jdouble>(JNIEnv* env, Signature* signature, jdouble& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		env->SetDoubleField(this->getJavaObject(), field->getFieldID(), value);
		return true;
	}
	return false;
}

template <>
bool FieldStructure::setField< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ::fr::Planquart::JNI::Object& value)
{
	return this->setObjectField(env, signature, value);
}

