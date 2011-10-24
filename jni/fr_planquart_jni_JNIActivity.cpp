#include "fr_planquart_jni_JNIActivity.h"

#include "fr/planquart/jni/JVM.hpp"
#include "fr/planquart/jni/Class.hpp"
#include "fr/planquart/jni/Object.hpp"

using namespace fr::Planquart::JNI;

JNIEXPORT jstring JNICALL Java_fr_planquart_jni_JNIActivity_getJNIText
  (JNIEnv * env, jobject thiz)
{
	return env->NewStringUTF("Hello World!");
}

JNIEXPORT jint JNICALL Java_fr_planquart_jni_JNIActivity_JNIAdd
  (JNIEnv * env, jobject thiz, jint a, jint b)
{
	return a + b;
}

JNIEXPORT jobject JNICALL Java_fr_planquart_jni_JNIActivity_getWindowSize
  (JNIEnv * env, jobject thiz)
{
	Object currentActivity (Class::getClass(JVM::class_Activity, env), thiz);
	Object windowManager = currentActivity.callMethod<Object>(env, JVM::method_Activity_getWindowManager_V);
	Object display = windowManager.callMethod<Object>(env, JVM::method_WindowManager_getDefaultDisplay_V);

	jint height = display.callMethod<jint>(env, JVM::method_Display_getHeight_V);
	jint width = display.callMethod<jint>(env, JVM::method_Display_getWidth_V);

	/*jclass Activity = env->FindClass("android/app/Activity");
	if (Activity == 0)
	{
		return 0;
	}

	jclass WindowManager = env->FindClass("android/view/WindowManager");
	if (WindowManager == 0)
	{
		return 0;
	}
	jclass Display = env->FindClass("android/view/Display");
	if (Display == 0)
	{
		return 0;
	}

	jmethodID method = env->GetMethodID(Activity, "getWindowManager", "()Landroid/view/WindowManager;");
	if (method == 0)
	{
		return 0;
	}

	jobject windowManager = env->CallObjectMethod(thiz, method);
	if (windowManager == 0)
	{
		return 0;
	}

	method = env->GetMethodID(WindowManager, "getDefaultDisplay", "()Landroid/view/Display;");
	if (method == 0)
	{
		return 0;
	}
	jobject display = env->CallObjectMethod(windowManager, method);
	if (display == 0)
	{
		return 0;
	}
	method = env->GetMethodID(Display, "getHeight", "()I");
	if (method == 0)
	{
		return 0;
	}
	jint height = env->CallIntMethod(display, method);
	method = env->GetMethodID(Display, "getWidth", "()I");
	if (method == 0)
	{
		return 0;
	}
	jint width = env->CallIntMethod(display, method);
*/
	jclass Point = env->FindClass("android/graphics/Point");
	jmethodID method = env->GetMethodID(Point, "<init>", "(II)V");
	jobject point = env->NewObject(Point, method, width, height);

	return point;
}

