#ifndef FR_PLANQUART_JNI_CLASS_HPP
#define FR_PLANQUART_JNI_CLASS_HPP

#include <jni.h>
#include <map>

#include "JVM.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This class is an abstract representation of a Java Class object.
	 */
	class Class
	{
	public:
		friend class JVM;

		typedef std::map<const char*, Class*> classes_map;


		/**
		 * Get the the address of the Class object corresponding to the
		 * Java class named by className.
		 *
		 * @param className The name of the Java class
		 * @return A Class object representing the Java class object or null
		 */
		static Class* getClass(const char* className);

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
		static Class* getClass(const char* className, JNIEnv* env);

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
		 * Requires on local reference, returned.
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
			if (env->IsSameObject(this->classObject, 0) == JNI_FALSE)
			{
				this->release(env);
				return 0;
			}
			return static_cast<jclass>(env->NewLocalRef(this->classObject));
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
		Class(JNIEnv* env, const char* className);

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
		const char* className;

		/**
		 * A map between class name and Class objects.
		 * This mapping uses the class name address as key, which involves
		 * creating the strings on the heap and in a static way.
		 *
		 * Initialization may be done in JVM::initialize()
		 */
		static classes_map classes;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_CLASS_HPP */

