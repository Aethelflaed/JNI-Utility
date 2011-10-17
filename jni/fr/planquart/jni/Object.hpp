#ifndef FR_PLANQUART_JNI_OBJECT_HPP
#define FR_PLANQUART_JNI_OBJECT_HPP

#include <jni.h>
#include "Class.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Object
	{
	public:
		Object(jobject object, Class& classObject);
		Object(Class& classObject, ...);
		~Object();
	private:
		Class& classObject;
		jobject object;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_OBJECT_HPP */

