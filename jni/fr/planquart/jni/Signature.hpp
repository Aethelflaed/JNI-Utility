#ifndef FR_PLANQUART_JNI_SIGNATURE_HPP
#define FR_PLANQUART_JNI_SIGNATURE_HPP

#include <string.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This struct is designed to store a Java Signature, corresponding to
	 * either a method or a field.
	 *
	 * This software intend to use this structure as statically and
	 * heap-instanciated objects. It should be used to represent the
	 * corresponding Java field or method.
	 */
	struct Signature
	{
		Signature(const char* name, const char* type)
			:name{strdup(name)}, type{strdup(type)}
		{
		}
		virtual ~Signature()
		{
			free(this->name);
			free(this->type);
		}

		const char* getName() const
		{
			return this->name;
		}
		const char* getType() const
		{
			return this->type;
		}

	private:
		char* name;
		char* type;
	};

}
}
}

#endif /* FR_PLANQUART_JNI_SIGNATURE_HPP */

