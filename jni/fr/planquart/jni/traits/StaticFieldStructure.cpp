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
		jclass object = this->getJavaClass(env);
		jobject value;
		if (object != 0)
		{
			value = env->GetStaticObjectField(object, field->getFieldID());
		}
		else
		{
			return Object();
		}
		env->DeleteLocalRef(object);
		return Object(this->getClass(), value);
	}
	return Object();
}

inline bool StaticFieldStructure::setStaticObjectField(JNIEnv* env, Signature* signature, Object& value)
{
	Field* field = this->getStaticFieldDescriptor(env, signature);
	if (field != 0)
	{
		jclass object = this->getJavaClass(env);
		if (object != 0)
		{
			jobject objectValue = value.getJavaObject(env);
			if (objectValue != 0)
			{
				env->SetStaticObjectField(object, field->getFieldID(), objectValue);
			}
			else
			{
				env->DeleteLocalRef(object);
				return false;
			}
			env->DeleteLocalRef(objectValue);
		}
		else
		{
			return false;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jboolean value;
		if (object != 0)
		{
			value = env->GetStaticBooleanField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jbyte value;
		if (object != 0)
		{
			value = env->GetStaticByteField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jchar value;
		if (object != 0)
		{
			value = env->GetStaticCharField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jshort value;
		if (object != 0)
		{
			value = env->GetStaticShortField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jint value;
		if (object != 0)
		{
			value = env->GetStaticIntField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jlong value;
		if (object != 0)
		{
			value = env->GetStaticLongField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jfloat value;
		if (object != 0)
		{
			value = env->GetStaticFloatField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		jdouble value;
		if (object != 0)
		{
			value = env->GetStaticDoubleField(object, field->getFieldID());
		}
		else
		{
			return 0;
		}
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticBooleanField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticByteField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticCharField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticShortField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticIntField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticLongField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticFloatField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jclass object = this->getJavaClass(env);
		env->SetStaticDoubleField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
		return true;
	}
	return false;
}

	template <>
bool StaticFieldStructure::setStaticField< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ::fr::Planquart::JNI::Object& value)
{
	return this->setStaticObjectField(env, signature, value);
}

