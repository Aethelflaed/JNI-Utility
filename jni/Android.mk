LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE	:= fr_planquart_jni_JNIActivity
LOCAL_SRC_FILES	:= fr_planquart_jni_JNIActivity.cpp

LOCAL_SRC_FILES += fr/planquart/jni/JVM.cpp
LOCAL_SRC_FILES += fr/planquart/jni/Class.cpp

include $(BUILD_SHARED_LIBRARY)

