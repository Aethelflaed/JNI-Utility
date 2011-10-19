#ifndef FR_PLANQUART_JNI_OBJECT_HPP
#define FR_PLANQUART_JNI_OBJECT_HPP

#include <jni.h>

#include "Class.hpp"
#include "Field.hpp"
#include "Method.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Object
	{
	public:
		Object(jobject object);
		Object(Class* classObject, jobject object);
		Object(Class* classObject, Method* method, ...);
		~Object();
	private:
		Class* classObject;
		jobject object;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_OBJECT_HPP */

