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
	Object windowManager = currentActivity.callMethod<Object>(env, JVM::method_Activity_getWindowManager_V).castToClass(env, JVM::class_WindowManager);
	Object display = windowManager.callMethod<Object>(env, JVM::method_WindowManager_getDefaultDisplay_V).castToClass(env, JVM::class_Display);

	jint height = display.callMethod<jint>(env, JVM::method_Display_getHeight_V);
	jint width = display.callMethod<jint>(env, JVM::method_Display_getWidth_V);

	Object point(env, JVM::class_Point, JVM::ctor_Point_II, width, height);

	return point.getJavaObject(env);
}

