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
Name* JVM::class_String = new Name("java/lang/String");

Signature* JVM::method_Class_getName_V = new Signature("getName", "()Ljava/lang/String;");
Signature* JVM::method_Object_toString_V = new Signature("toString", "()Ljava/lang/String;");
Signature* JVM::method_Object_hashCode_I = new Signature("hashCode", "()I");

void JVM::initialize()
{
	JNIEnv* env = JVM::getEnv();
	Class* classObject = Class::getClass(JVM::class_String, env);

	android::Log::debug("JVM", "jclass value = %p", classObject->classObject);

	Object object = classObject->callMethod<Object>(env, JVM::method_Class_getName_V);

	String* stringObject = static_cast<String*>(&object);

	jint hash = classObject->callMethod<jint>(env, JVM::method_Object_hashCode_I);

	char* string = stringObject->getCUTFString(env);

	android::Log::debug("JVM", "jclass hash : %d", hash);
	android::Log::debug("JVM", "jclass name : %s", string);

	free(string);

//#error JVM initialize method not implemented
}

void JVM::clean()
{
	Class::releaseAll(getEnv());
//#error JVM clean method not implemented
}

