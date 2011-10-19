#ifndef FR_PLANQUART_JNI_NAME_HPP
#define FR_PLANQUART_JNI_NAME_HPP

#include <string.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	struct Name
	{
		Name(const char* name)
			:name{strdup(name)}
		{
		}
		virtual ~Name()
		{
			free(this->name);
		}

		const char* getName() const
		{
			return this->name;
		}

	private:
		char* name;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_NAME_HPP */

