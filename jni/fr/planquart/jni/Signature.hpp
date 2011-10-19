#ifndef FR_PLANQUART_JNI_SIGNATURE_HPP
#define FR_PLANQUART_JNI_SIGNATURE_HPP

#include <string.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
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

