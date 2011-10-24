#ifndef FR_PLANQUART_JNI_TRAITS_LOCKABLE_HPP
#define FR_PLANQUART_JNI_TRAITS_LOCKABLE_HPP

#include <jni.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
namespace traits
{
	/**
	 * A small interface to provide other classes with lock verification.
	 *
	 * The class extending this one must ensure no big modification of its
	 * content (e.g. not to changed its jobject or jclass field) when the
	 * isLocked method returns true.
	 */
	class Lockable
	{
	public:
		Lockable()
			:locked{false}
		{
		}

		virtual ~Lockable()
		{
		}

		/**
		 * Get the lock status
		 *
		 * @return The lock status
		 */
		bool isLocked()
		{
			return this->locked;
		}

		/**
		 * Set the lock status of the object
		 *
		 * @param locked The lock status
		 */
		void setLocked(bool locked)
		{
			this->locked = locked;
		}

	private:
		bool locked;
	};
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_LOCKABLE_HPP */

