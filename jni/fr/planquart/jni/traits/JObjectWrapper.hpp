#ifndef FR_PLANQUART_JNI_TRAITS_JOBJECT_WRAPPER_HPP
#define FR_PLANQUART_JNI_TRAITS_JOBJECT_WRAPPER_HPP

#include <jni.h>

#include "Lockable.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
namespace traits
{
	class JObjectWrapper : public Lockable
	{
	public:
		JObjectWrapper()
			:javaObject{0}
		{
		}

		virtual ~JObjectWrapper()
		{
		}

		virtual bool isValid()
		{
			return this->javaObject != 0;
		}

		virtual bool isValid(JNIEnv* env)
		{
			return this->isValid() &&
				env->IsSameObject(this->javaObject, 0) == JNI_FALSE;
		}

	protected:
		virtual jobject getJavaObject(JNIEnv* env)
		{
			return env->NewLocalRef(this->javaObject);
		}

		virtual bool setJavaObject(jobject javaObject)
		{
			if (this->isLocked() == false)
			{
				this->javaObject = javaObject;
				return true;
			}
			return false;
		}

	private:
		jobject javaObject;
	};
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_JOBJECT_WRAPPER_HPP */

