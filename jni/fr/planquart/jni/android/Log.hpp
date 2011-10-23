#ifndef FR_PLANQUART_JNI_ANDROID_LOG_HPP
#define FR_PLANQUART_JNI_ANDROID_LOG_HPP

#include <android/log.h>
#include <cstdarg>

namespace fr
{
namespace Planquart
{
namespace JNI
{
namespace android
{
	/**
	 * This class provide with the same logging abilities as the android
	 * class android.util.Log.
	 *
	 * Note that it uses the long name instead of the short one and that
	 * the log level "What a Terrible Failure" (abbr. wtf) is replaced by
	 * fatal.
	 */
	class Log
	{
	public:
		static void verbose(const char* tag, const char* msg, ...)
		{
			va_list arguments_list;
			va_start(arguments_list, msg);
			__android_log_vprint(ANDROID_LOG_VERBOSE, tag, msg, arguments_list);
			va_end(arguments_list);
		}

		static void debug(const char* tag, const char* msg, ...)
		{
			va_list arguments_list;
			va_start(arguments_list, msg);
			__android_log_vprint(ANDROID_LOG_DEBUG, tag, msg, arguments_list);
			va_end(arguments_list);
		}

		static void info(const char* tag, const char* msg, ...)
		{
			va_list arguments_list;
			va_start(arguments_list, msg);
			__android_log_vprint(ANDROID_LOG_INFO, tag, msg, arguments_list);
			va_end(arguments_list);
		}

		static void warn(const char* tag, const char* msg, ...)
		{
			va_list arguments_list;
			va_start(arguments_list, msg);
			__android_log_vprint(ANDROID_LOG_WARN, tag, msg, arguments_list);
			va_end(arguments_list);
		}

		static void error(const char* tag, const char* msg, ...)
		{
			va_list arguments_list;
			va_start(arguments_list, msg);
			__android_log_vprint(ANDROID_LOG_ERROR, tag, msg, arguments_list);
			va_end(arguments_list);
		}

		static void fatal(const char* tag, const char* msg, ...)
		{
			va_list arguments_list;
			va_start(arguments_list, msg);
			__android_log_vprint(ANDROID_LOG_FATAL, tag, msg, arguments_list);
			va_end(arguments_list);
		}
	};
}
}
}
}

#endif /* FR_PLANQUART_JNI_ANDROID_LOG_HPP */

