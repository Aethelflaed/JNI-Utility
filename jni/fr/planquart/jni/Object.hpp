#ifndef FR_PLANQUART_JNI_OBJECT_HPP
#define FR_PLANQUART_JNI_OBJECT_HPP

#include <jni.h>

#include "Class.hpp"
#include "Name.hpp"
#include "Signature.hpp"
#include "traits/Callable.hpp"
#include "traits/FieldStructure.hpp"
#include "traits/JavaObjectWrapper.hpp"
#include "traits/Monitor.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This class is an abstract representation of a Java object.
	 */
	class Object :
		public traits::JavaObjectWrapper,
		public traits::Callable,
		public traits::FieldStructure,
		public traits::Monitor
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
		 * checking if the object and the class are not null.
		 * If the object is not valid you can't perform any operation on it.
		 *
		 * @return A boolean indicating the basic validity of the object
		 */
		virtual bool isValid();

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
		 */
		Object(Class* classObject, jobject object);

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

		virtual jobject getJavaObject(JNIEnv* env) const
		{
			return traits::JavaObjectWrapper::getJavaObject(env);
		}
	protected:
		virtual JavaObjectWrapper& getObjectWrapper()
		{
			return *this;
		}

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

		Class* classObject;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_OBJECT_HPP */

