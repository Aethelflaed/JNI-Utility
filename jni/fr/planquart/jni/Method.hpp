#ifndef FR_PLANQUART_JNI_METHOD_HPP
#define FR_PLANQUART_JNI_METHOD_HPP

#include <jni.h>

#include "Signature.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Class;
	class Object;

	/**
	 * This class is an abstract representation of a Java Method Identifier.
	 *
	 * It is not intended to be used directly, consider using Signature
	 * object to represent this data.
	 * In order to prevent side-effects, Signature must be instanciated on the
	 * heap and stored statically to ensure a distinct and unique address for
	 * each signature.
	 */
	class Method
	{
	public:
		friend class Class;
		friend class Object;

		jmethodID getMethodID() const
		{
			return this->methodID;
		}

	private:
		Method(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic = false);

		jmethodID methodID;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_METHOD_HPP */

