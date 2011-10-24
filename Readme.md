JNI Utility
===========

A set of Java Native Interface wrapper classes. This projects aims to create an efficient and simple way to access JNI functionality.

Current status : working on creating a specific wrapper for String and Array classes.

### Requirement

* Java 1.2 for basic functionalities.
* Android API Level 3 if you intend to use the classes in android/ subfolder.

### Example

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

