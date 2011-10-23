#ifndef FR_PLANQUART_JNI_CLASS_HPP
#define FR_PLANQUART_JNI_CLASS_HPP

#include <jni.h>
#include <map>

#include "JVM.hpp"

#include "Field.hpp"
#include "Method.hpp"
#include "Name.hpp"
#include "Signature.hpp"
#include "traits/Callable.hpp"
#include "traits/StaticCallable.hpp"
#include "traits/StaticFieldStructure.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Object;

	/**
	 * This class is an abstract representation of a Java Class object.
	 */
	class Class
		: public traits::StaticCallable,
		  public traits::Callable,
		  public traits::StaticFieldStructure
	{
	public:
		friend class JVM;

		typedef std::map<Name*, Class*> classes_map;
		typedef std::map<Signature*, Field*> fields_map;
		typedef std::map<Signature*, Method*> methods_map;

		/**
		 * Get the the address of the Class object corresponding to the
		 * Java class named by className.
		 *
		 * @param className The name of the Java class
		 * @return A Class object representing the Java class object or null
		 */
		static Class* getClass(Name* className);

		/**
		 * Get the address of the Class object corresponding to the Java
		 * class named by className.
		 *
		 * If the object doesn't exists, it tries to create it using the
		 * JNI environment.
		 *
		 * Requires one local reference, released after use, if the method
		 * should construct a new Class object.
		 *
		 * @param className The name of the Java class
		 * @param env The JNI environment
		 * @return A Class object representing the Java class object or null
		 * @throws ClassNotFoundException if the class is not found.
		 *	OutOfMemoryException if the class reference can't be
		 *	loaded.
		 */
		static Class* getClass(Name* className, JNIEnv* env);

		/**
		 * Release the internal Java Class reference
		 *
		 * @param env The JNI environment
		 */
		void release(JNIEnv* env)
		{
			if (this->classObject != 0)
			{
				env->DeleteWeakGlobalRef(this->classObject);
				this->classObject = 0;
			}
		}

		/**
		 * Remove a class object a free up memory used by both the C++ heap
		 * and the JNI.
		 */
		void remove();

		/**
		 * Get a local reference from the internal Java Class reference.
		 * The methods check for living object before returning.
		 *
		 * Requires one local reference, returned.
		 *
		 * Note : If the method returns 0 it doesn't mean an exception will
		 * be thrown. Consider removing the object in this case,
		 * using remove method.
		 *
		 * @param env The JNI environment
		 * @return A local ref to the Java Class object or 0
		 */
		jclass getClassObject(JNIEnv* env)
		{
			if (this->classObject == 0)
			{
				return 0;
			}
			if (env->IsSameObject(this->classObject, 0) == JNI_TRUE)
			{
				this->release(env);
				return 0;
			}
			return static_cast<jclass>(env->NewLocalRef(this->classObject));
		}

		/**
		 * Get an Identifier to a static method of this class designed by
		 * a Signature object.
		 *
		 * Note: if `env` param is 0 and the method returns 0, is just
		 * indicates that the method identifier is not registered and no
		 * exception is thrown. If env is not null and the method returns 0
		 * then a Java exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @param signature The method signature
		 * @return A method opaque identifier or 0
		 * @throws NoSuchMethodError, OutOfMemoryError,
		 *	ExceptionInInitializerError
		 */
		Method* getStaticMethod(JNIEnv* env, Signature* signature);

		/**
		 * Get an Identifier to a method of this class designed by
		 * a Signature object.
		 *
		 * Note: if `env` param is 0 and the method returns 0, is just
		 * indicates that the method identifier is not registered and no
		 * exception is thrown. If env is not null and the method returns 0
		 * then a Java exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @param signature The method signature
		 * @return A method opaque identifier or 0
		 * @throws NoSuchMethodError, OutOfMemoryError,
		 *	ExceptionInInitializerError
		 */
		Method* getMethod(JNIEnv* env, Signature* signature);

		/**
		 * Get an Identifier to a static field of this class designed by
		 * a Signature object.
		 *
		 * Note: if `env` param is 0 and the method returns 0, is just
		 * indicates that the field identifier is not registered and no
		 * exception is thrown. If env is not null and the method returns 0
		 * then a Java exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @param signature The field signature
		 * @return A field opaque identifier or 0
		 * @throws NoSuchMethodError, OutOfMemoryError,
		 *	ExceptionInInitializerError
		 */
		Field* getStaticField(JNIEnv* env, Signature* signature);

		/**
		 * Get an Identifier to a field of this class designed by
		 * a Signature object.
		 *
		 * Note: if `env` param is 0 and the method returns 0, is just
		 * indicates that the field identifier is not registered and no
		 * exception is thrown. If env is not null and the method returns 0
		 * then a Java exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @param signature The field signature
		 * @return A field opque Identifier or 0
		 * @throws NoSuchMethodError, OutOfMemoryError,
		 *	ExceptionInInitializerError
		 */
		Field* getField(JNIEnv* env, Signature* signature);

	protected:
		virtual Method* getMethodDescriptor(JNIEnv* env, Signature* signature)
		{
			return Class::getClass(JVM::class_Class, env)->getMethod(env, signature);
		}

		virtual Method* getStaticMethodDescriptor(JNIEnv* env, Signature* signature)
		{
			return this->getStaticMethod(env, signature);
		}

		virtual Field* getStaticFieldDescriptor(JNIEnv* env, Signature* signature)
		{
			return this->getStaticField(env, signature);
		}

		virtual jobject getJavaObject(JNIEnv* env)
		{
			return this->getClassObject(env);
		}

		virtual jclass getJavaClass(JNIEnv* env)
		{
			return this->getClassObject(env);
		}

		virtual Class* getClass()
		{
			return this;
		}

	private:
		/**
		 * Release all instances.
		 */
		static void releaseAll(JNIEnv* env);

		/**
		 * Initialize a new Class object representing no Java Class.
		 */
		Class();

		/**
		 * Initializate a new Class object representing the Java Class
		 * designed by className.
		 *
		 * Requires one local reference, released after use.
		 *
		 * @param env The JNI environment
		 * @param className The name of the Java Class to use
		 * @throws ClassNotFoundException if the class is not found.
		 *	OutOfMemoryException if the class reference can't be
		 *	loaded.
		 */
		Class(JNIEnv* env, Name* className);

		~Class();

		/**
		 * The Java Class object associated with this abstract representation
		 * This object is a weak global reference to keep the same reference
		 * between threads without preventing it from being unloaded.
		 */
		jclass classObject;

		/**
		 * A copy of the class name.
		 */
		Name* className;

		/**
		 * A map between class name and Class objects.
		 * This mapping uses the class name address as key, which involves
		 * creating the strings on the heap and in a static way.
		 *
		 * Initialization may be done in JVM::initialize()
		 */
		static classes_map classes;

		/**
		 * A map caching all static fields of the class.
		 * This mapping uses the field name address as key, which involves
		 * creating the strings on the heap and in a static way.
		 *
		 * Initialization may be done in JVM::initialize()
		 */
		fields_map static_fields;

		/**
		 * A map caching all fields of the class.
		 * This mapping uses the field name address as key, which involves
		 * creating the strings on the heap and in a static way.
		 *
		 * Initialization may be done in JVM::initialize()
		 */
		fields_map fields;

		/**
		 * A map caching all static methods of the class.
		 * This mapping uses the field name address as key, which involves
		 * creating the strings on the heap and in a static way.
		 *
		 * Initialization may be done in JVM::initialize()
		 */
		methods_map static_methods;

		/**
		 * A map caching all methods of the class.
		 * This mapping uses the field name address as key, which involves
		 * creating the strings on the heap and in a static way.
		 *
		 * Initialization may be done in JVM::initialize()
		 */
		methods_map methods;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_CLASS_HPP */

