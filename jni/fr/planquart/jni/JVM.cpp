#include "JVM.hpp"

using namespace fr::Planquart::JNI;

JavaVM* JVM::jvm = 0;

jint JVM::jni_version = JNI_VERSION_1_6;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved)
{
	JVM::setJVM(jvm);
	JVM::initialize();
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* jvm, void* reserved)
{
	JVM::setJVM(0);
	JVM::clean();
}

void JVM::initialize()
{
//#error JVM initialize method not implemented
}

void JVM::clean()
{
//#error JVM clean method not implemented
}

