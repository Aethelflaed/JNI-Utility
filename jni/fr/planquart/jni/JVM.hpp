#ifndef FR_PLANQUART_JNI_JVM_HPP
#define FR_PLANQUART_JNI_JVM_HPP

#include <jni.h>

#include "Signature.hpp"
#include "Name.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* jvm, void* reserved);

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * Manage the JVM reference and centralize static resources.
	 *
	 * You are free to add static fields in this class, such as string
	 * references to be able to use them as simple key identifier in other
	 * classes.
	 * Initialize your resources on the heap in JVM::initialize() and delete
	 * them in JVM::clean().
	 */
	class JVM
	{
	public:
		static Name* class_Class;
		static Name* class_String;

		static Signature* method_Class_getName_V;
		static Signature* method_Object_toString_V;
		static Signature* method_Object_hashCode_I;

		/**
		 * Method provided for user-defined initialization.
		 * Put your initialization code in this method, which is
		 * fired from JNI_OnLoad.
		 */
		static void initialize();

		/**
		 * Method provided for user-defined cleaning.
		 * Put your cleaning code in this method, which is
		 * fired from JNI_OnUnload.
		 */
		static void clean();

		/**
		 * Set the Java VM in use.
		 * @param javaVM The Java Virtual Machine
		 */
		static void setJVM(JavaVM* javaVM)
		{
			JVM::jvm = javaVM;
		}

		/**
		 * Get the Java VM in use
		 * @return The Java Virtual Machine
		 */
		static JavaVM* getJVM()
		{
			return JVM::jvm;
		}

		/**
		 * Get the JNI environment for the current thread
		 * @return The current JNI environment or 0 if it is not available
		 */
		static JNIEnv* getEnv()
		{
			if (JVM::jvm == 0)
			{
				return 0;
			}
			JNIEnv* env;
			JVM::jvm->GetEnv((void**)&env, JVM::jni_version);
			return env;
		}

		/**
		 * Get the JNI Version used to get the JNI environment
		 * @return The JNI version
		 */
		static jint getVersion()
		{
			return JVM::jni_version;
		}

		/**
		 * Set the JNI Version to use to get the JNI environment
		 * @param version The JNI version
		 */
		static void setVersion(jint version)
		{
			JVM::jni_version = version;
		}
	private:
		static JavaVM* jvm;
		static jint jni_version;

		/**
		 * Prevent instantiation
		 */
		JVM() {}
	};
}
}
}

#endif /* FR_PLANQUART_JNI_JVM_HPP */

