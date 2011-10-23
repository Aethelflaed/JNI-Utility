#ifndef FR_PLANQUART_JNI_FIELD_HPP
#define FR_PLANQUART_JNI_FIELD_HPP

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
	 * This class is an abstract representation of a Java Field Identifier.
	 *
	 * It is not intended to be used directly, consider using Signature
	 * object to represent this data.
	 * In order to prevent side-effects, Signature must be instanciated on the
	 * heap and stored statically to ensure a distinct and unique address for
	 * each signature.
	 */
	class Field
	{
	public:
		friend class Class;
		friend class Object;

		jfieldID getFieldID() const
		{
			return this->fieldID;
		}

	private:
		Field(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic = false);

		jfieldID fieldID;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_FIELD_HPP */

