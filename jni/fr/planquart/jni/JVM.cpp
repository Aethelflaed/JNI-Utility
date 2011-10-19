#include "JVM.hpp"
#include "Class.hpp"

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

void JVM::initialize()
{
	//JNIEnv* env = JVM::getEnv();

//#error JVM initialize method not implemented
}

void JVM::clean()
{
	Class::releaseAll(getEnv());
//#error JVM clean method not implemented
}

