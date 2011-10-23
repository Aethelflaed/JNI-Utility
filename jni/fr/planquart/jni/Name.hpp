#ifndef FR_PLANQUART_JNI_NAME_HPP
#define FR_PLANQUART_JNI_NAME_HPP

#include <string.h>

namespace fr
{
namespace Planquart
{
namespace JNI
{
	/**
	 * This class is designed to store a Java Class Name.
	 *
	 * This software intend to use this structure as statically and
	 * heap-instanciated objects. It should be used to represent the
	 * corresponding Java class.
	 */
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

