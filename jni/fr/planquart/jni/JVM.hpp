#ifndef FR_PLANQUART_JNI_JVM_HPP
#define FR_PLANQUART_JNI_JVM_HPP

#include <jni.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class JVM
	{
	public:
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
	};
}
}
}

#endif /* FR_PLANQUART_JNI_JVM_HPP */

