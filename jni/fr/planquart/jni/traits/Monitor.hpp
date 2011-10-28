#ifndef FR_PLANQUART_JNI_TRAITS_MONITOR_HPP
#define FR_PLANQUART_JNI_TRAITS_MONITOR_HPP

#include <jni.h>

#include "JavaObjectWrapper.hpp"
#include "../JVM.hpp"

#include "../Log.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Class;
	class Method;
	class Object;
	class Signature;

namespace traits
{
	class Monitor
	{
	public:
		/**
		 * Initialize the Monitor state
		 */
		Monitor()
			:synchronized{false}
		{
		}

		/**
		 * Virtual destructor for safety check.
		 * If the object has not been desynchronized, then it is done.
		 *
		 * WARNING : if the object is still synchronized the desynchronized
		 * method is called with current thread's JNIEnv. It may throw one
		 * or more exception, which could cause the application to be unstable.
		 *
		 * Try to always desynchronize the object before stop using it!
		 * The destructor will log  any hazardous behavior.
		 */
		virtual ~Monitor()
		{
			if (this->synchronized)
			{
				::fr::Planquart::JNI::Log::fatal("Monitor", "Monitor destructor called on synchronized object!");
				this->desynchronize(
					::fr::Planquart::JNI::JVM::getEnv());
			}
		}

		/**
		 * Enter the monitor, i.e. the synchronized block
		 *
		 * You must not own the monitor first! If you own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * This method lock the object using the Lockable traits. You must not
		 * change the internal jobject (returned by getJavaObject)  reference!
		 *
		 * @param env The JNI environment
		 * @return False on error, true on success
		 */
		bool synchronize(JNIEnv* env);

		/**
		 * Exit the monitor, i.e. the synchronized block
		 *
		 * You must own the monitor first! If you don't own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * This method unlock the object using the Lockable traits. You
		 * can update the internal jobject (returned by getJavaObject) again.
		 *
		 * @param env The JNI environment
		 * @return False on error, true on success
		 * @throws OutOfMemoryError: if the system runs out of memory.
		 *	IllegalMonitorStateException: if the current thread does not owned
		 *	the monitor.
		 */
		bool desynchronize(JNIEnv* env);

		/**
		 * Get the monitor state of the object.
		 *
		 * @return True if the object has the monitor, false otherwise.
		 */
		bool isSynchronized()
		{
			return this->synchronized;
		}

		/**
		 * Call the java method java.lang.Object.notify(), i.e. wake up another
		 * waiting thread. A waiting thread is a thread in the same
		 * synchronized block which called a wait() method.
		 *
		 * You must own the monitor first! If you don't own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @return False on error, true on success
		 */
		bool notify(JNIEnv* env);

		/**
		 * Call the java method java.lang.Object.notifyAll(), i.e. wake
		 * up all waiting threads. A waiting thread is a thread in
		 * the same synchronized block which called a wait() method.
		 *
		 * You must own the monitor first! If you don't own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @return False on error, true on success
		 */
		bool notifyAll(JNIEnv* env);

		/**
		 * Call the java method java.lang.Object.wait(), i.e. make this thread
		 * wait for another thread in the same synchronized block to call
		 * notify or notifyAll.
		 *
		 * You must own the monitor first! If you don't own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @return False on error, true on success
		 */
		bool wait(JNIEnv* env);

		/**
		 * Call the java method java.lang.Object.wait(long), i.e. make this
		 * thread wait for another thread in the same synchronized block to
		 * call notify or notifyAll. If millis millisecond are spent, the
		 * method stop waiting.
		 *
		 * You must own the monitor first! If you don't own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @param millis The maximum number of millisecond to wait
		 * @return False on error, true on success
		 */
		bool wait(JNIEnv* env, jlong millis);

		/**
		 * Call the java method java.lang.Object.wait(long, int), i.e. make
		 * this thread wait for another thread in the same synchronized block
		 * to call notify or notifyAll. If millis milliseconds and nonos
		 * nanoseconds are spent, the method stop waiting.
		 *
		 * You must own the monitor first! If you don't own the monitor, the
		 * method still return true, as no exception has been thrown.
		 *
		 * @param env The JNI environment
		 * @param millis The maximum number of millisecond to wait
		 * @return False on error, true on success
		 */
		bool wait(JNIEnv* env, jlong millis, jint nanos);

	protected:
		virtual JavaObjectWrapper& getObjectWrapper() = 0;

	private:
		bool synchronized;
	};
}

}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_MONITOR_HPP */

