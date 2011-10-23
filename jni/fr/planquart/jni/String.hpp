#ifndef FR_PLANQUART_JNI_STRING_HPP
#define FR_PLANQUART_JNI_STRING_HPP

#include <jni.h>
#include "Object.hpp"
#include "Class.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This class is an abstract representation of a Java string.
	 */
	class String : public Object
	{
	public:
		friend class Class;

		String(JNIEnv* env, Signature* signature, ...);
	};
}
}
}

#endif /* FR_PLANQUART_JNI_STRING_HPP */

