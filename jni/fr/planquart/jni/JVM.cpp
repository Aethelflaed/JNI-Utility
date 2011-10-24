#include "JVM.hpp"
#include "Class.hpp"
#include "Object.hpp"
#include "String.hpp"

#include "android/Log.hpp"

#include <cstdio>

using namespace fr::Planquart::JNI;

JavaVM* JVM::jvm = 0;

jint JVM::jni_version = JNI_VERSION_1_6;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved)
{
	JVM::setJVM(jvm);
	JVM::initialize();

	return JVM::getVersion();
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* jvm, void* reserved)
{
	JVM::clean();
	JVM::setJVM(0);
}

Name* JVM::class_Class = new Name("java/lang/Class");
Name* JVM::class_Object = new Name("java/lang/Object");
Name* JVM::class_String = new Name("java/lang/String");
Name* JVM::class_Activity = new Name("android/app/Activity");
Name* JVM::class_WindowManager = new Name("android/view/WindowManager");
Name* JVM::class_Display = new Name("android/view/Display");
Name* JVM::class_Point = new Name("android/graphics/Point");

Signature* JVM::method_Class_getName_V = new Signature("getName", "()Ljava/lang/String;");
Signature* JVM::method_Object_toString_V = new Signature("toString", "()Ljava/lang/String;");
Signature* JVM::method_Object_hashCode_I = new Signature("hashCode", "()I");
Signature* JVM::method_Activity_getWindowManager_V = new Signature("getWindowManager", "()Landroid/view/WindowManager;");
Signature* JVM::method_WindowManager_getDefaultDisplay_V = new Signature("getDefaultDisplay", "()Landroid/view/Display;");
Signature* JVM::method_Display_getHeight_V = new Signature("getHeight", "()I");
Signature* JVM::method_Display_getWidth_V = new Signature("getWidth", "()I");
Signature* JVM::ctor_Point_II = new Signature("<init>", "(II)V");
Signature* JVM::ctor_String__3B = new Signature("<init>", "([B)V");

void JVM::initialize()
{
	JNIEnv* env = JVM::getEnv();
	Class* classObject = Class::getClass(JVM::class_String, env);

	android::Log::debug("JVM", "jclass value = %p", classObject->classObject);

	Object object = classObject->callMethod<Object>(env, JVM::method_Class_getName_V);

	String* stringObject = static_cast<String*>(&object);

	jint hash = classObject->callMethod<jint>(env, JVM::method_Object_hashCode_I);

	android::Log::debug("JVM", "jclass hash : %d", hash);
	android::Log::debug("JVM", "jclass name : %s", stringObject->getUTFString(env).c_str());

//#error JVM initialize method not implemented
}

void JVM::clean()
{
	Class::releaseAll(getEnv());
//#error JVM clean method not implemented
}

