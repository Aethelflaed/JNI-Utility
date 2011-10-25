#ifndef FR_PLANQUART_JNI_TRAITS_JAVAOBJECT_WRAPPER_HPP
#define FR_PLANQUART_JNI_TRAITS_JAVAOBJECT_WRAPPER_HPP

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
	class JavaObjectWrapper : public Lockable
	{
	public:
		JavaObjectWrapper()
			:javaObject{0}
		{
		}

		virtual ~JavaObjectWrapper()
		{
		}

		/**
		 * Check whether the corresponding java object is valid. It is only
		 * done by checking if the object is not null.
		 * If the object is not valid you can't perform any operation on it.
		 *
		 * @return A boolean indicating the basic validity of the object
		 */
		virtual bool isValid()
		{
			return this->javaObject != 0;
		}

		/**
		 * Check whether the corresponding java object is valid. It first check
		 * the simple isValid version then check if the corresponding Java
		 * object is different from null.
		 * If the object is not valid you can't perform any operation on it.
		 *
		 * @param env The JNI environment
		 * @return A boolean indicating the validity of the object.
		 */
		virtual bool isValid(JNIEnv* env)
		{
			return this->isValid() &&
				env->IsSameObject(this->javaObject, 0) == JNI_FALSE;
		}

	protected:
		/**
		 * Get a new local reference to the java object.
		 *
		 * @param env The JNI environment
		 * @return A local reference to the object or null
		 */
		virtual jobject getJavaObject(JNIEnv* env) const
		{
			return env->NewLocalRef(this->javaObject);
		}

		/**
		 * Set the reference of the java object to a new value.
		 * This is only done if the object is not locked.
		 *
		 * @param javaObject The new reference
		 * @return A boolean indicating success or failure
		 */
		virtual bool setJavaObject(jobject javaObject)
		{
			if (this->isLocked() == false)
			{
				this->javaObject = javaObject;
				return true;
			}
			return false;
		}

		/**
		 * Return the reference truly owned by the class.
		 *
		 * @return The reference ownd by the object.
		 */
		jobject getJavaObject() const
		{
			return this->javaObject;
		}

	private:
		jobject javaObject;
	};
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_JAVAOBJECT_WRAPPER_HPP */

