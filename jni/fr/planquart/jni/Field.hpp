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

	class Field
	{
	public:
		friend class Class;
		friend class Object;

		bool isStatic()
		{
			return this->_static;
		}

	private:
		Field(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic = false);

		Class* classObject;
		Signature* signature;
		jfieldID fieldID;
		bool _static;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_FIELD_HPP */

