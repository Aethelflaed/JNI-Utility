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
			:locked{false}, key{0}
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
		bool isLocked() const
		{
			return this->locked;
		}

		/**
		 * Lock the object with the given key
		 *
		 * @param key The key used to lock the object. Reuse this key with
		 *	unlock()
		 * @return false if object is already locked, true otherwise
		 */
		bool lock(int key)
		{
			if (this->locked)
			{
				return false;
			}
			this->locked = true;
			this->key = key;
		}

		/**
		 * Unlock the object using the given key
		 *
		 * @param key The key used to unlock the object.
		 * @return false if key mismatch, true otherwise
		 */
		bool unlock(int key)
		{
			if (this->key != key && key != 0)
			{
				return false;
			}
			this->locked = false;
			return true;
		}

	private:
		bool locked;
		int key;
	};
}
}
}
}

#endif /* FR_PLANQUART_JNI_TRAITS_LOCKABLE_HPP */

