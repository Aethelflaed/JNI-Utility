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
		jobject object = this->getJavaObject(env);
		jobject value;
		if (object != 0)
		{
			value = env->GetObjectField(object, field->getFieldID());
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

inline bool FieldStructure::setObjectField(JNIEnv* env, Signature* signature, Object& value)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		if (object != 0)
		{
			jobject objectValue = value.getJavaObject(env);
			if (objectValue != 0)
			{
				env->SetObjectField(object, field->getFieldID(), objectValue);
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
jboolean FieldStructure::getField<jboolean>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jboolean value;
		if (object != 0)
		{
			value = env->GetBooleanField(object, field->getFieldID());
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
jbyte FieldStructure::getField<jbyte>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jbyte value;
		if (object != 0)
		{
			value = env->GetByteField(object, field->getFieldID());
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
jchar FieldStructure::getField<jchar>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jchar value;
		if (object != 0)
		{
			value = env->GetCharField(object, field->getFieldID());
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
jshort FieldStructure::getField<jshort>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jshort value;
		if (object != 0)
		{
			value = env->GetShortField(object, field->getFieldID());
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
jint FieldStructure::getField<jint>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jint value;
		if (object != 0)
		{
			value = env->GetIntField(object, field->getFieldID());
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
jlong FieldStructure::getField<jlong>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jlong value;
		if (object != 0)
		{
			value = env->GetLongField(object, field->getFieldID());
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
jfloat FieldStructure::getField<jfloat>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jfloat value;
		if (object != 0)
		{
			value = env->GetFloatField(object, field->getFieldID());
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
jdouble FieldStructure::getField<jdouble>(JNIEnv* env, Signature* signature)
{
	Field* field = this->getFieldDescriptor(env, signature);
	if (field != 0)
	{
		jobject object = this->getJavaObject(env);
		jdouble value;
		if (object != 0)
		{
			value = env->GetDoubleField(object, field->getFieldID());
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
		jobject object = this->getJavaObject(env);
		env->SetBooleanField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetByteField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetCharField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetShortField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetIntField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetLongField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetFloatField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
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
		jobject object = this->getJavaObject(env);
		env->SetDoubleField(object, field->getFieldID(), value);
		env->DeleteLocalRef(object);
		return true;
	}
	return false;
}

	template <>
bool FieldStructure::setField< ::fr::Planquart::JNI::Object >(JNIEnv* env, Signature* signature, ::fr::Planquart::JNI::Object& value)
{
	return this->setObjectField(env, signature, value);
}

