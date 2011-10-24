#ifndef FR_PLANQUART_JNI_OBJECT_HPP
#define FR_PLANQUART_JNI_OBJECT_HPP

#include <jni.h>

#include "Class.hpp"
#include "Name.hpp"
#include "Signature.hpp"
#include "traits/Callable.hpp"
#include "traits/FieldStructure.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This class is an abstract representation of a Java object.
	 */
	class Object : public traits::Callable, public traits::FieldStructure
	{
	public:
		/**
		 * Create a new object from class corresponding to className using the
		 * constructor identified by signature. You can pass the parameters
		 * to the constructor at the end of the method.
		 *
		 * @param env The JNI environment
		 * @param className The name of the Java Class
		 * @param signature The signature of the constructor
		 * @param ... The parameters to give to the constructor
		 */
		Object(JNIEnv* env, Name* className, Signature* signature, ...);

		virtual ~Object();

		/**
		 * Check whether the current object is valid. It is only done by
		 * checking if the object is not null.
		 * If the object is not valid you can't perform any operation on it.
		 *
		 * @return A boolean indicating the basic validity of the object
		 */
		bool isValid();

		/**
		 * Check whether the current object is valid. It first check the simple
		 * isValid version then check if the corresponding Java object is
		 * different from null.
		 * If the object is not valid you can't perform any operation on it.
		 *
		 * @param env The JNI environment
		 * @return A boolean indicating the validity of the object.
		 */
		bool isValid(JNIEnv* env);

		/**
		 * Copy constructor. Should be a move constructor for security reason.
		 *
		 * @param object The object to copy.
		 */
		Object(const Object& object);

		/**
		 * Create an abstract representation from an existing java object.
		 *
		 * @param classObject The abstract representation of the class
		 * @param object The Java Object
		 * @param isGlobal Indicates if the object is a weak global reference
		 *	or a local reference.
		 */
		Object(Class* classObject, jobject object, bool isGlobal = false);

		/**
		 * Create a null object, used as return value by Class when there are
		 * any problem.
		 */
		Object();

		/**
		 * Cast this object to the specified java class.
		 *
		 * @param env The JNI environment
		 * @param name The name of the Java Class
		 * @return A reference to the object
		 * @throws Any exception thrown by Class::getClass(Name*, JNIEnv*)
		 */
		Object& castToClass(JNIEnv* env, Name* name)
		{
			this->classObject = Class::getClass(name, env);
			return *this;
		}

		virtual jobject getJavaObject(JNIEnv* env)
		{
			return env->NewLocalRef(this->object);
		}
	protected:
		virtual Field* getFieldDescriptor(JNIEnv* env, Signature* signature)
		{
			return this->classObject->getField(env, signature);
		}

		virtual Method* getMethodDescriptor(JNIEnv* env, Signature* signature)
		{
			return this->classObject->getMethod(env, signature);
		}

		virtual Class* getClass()
		{
			return this->classObject;
		}

		bool isGlobal;
		Class* classObject;
		jobject object;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_OBJECT_HPP */

