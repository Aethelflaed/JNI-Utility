LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE	:= fr_planquart_jni_JNIActivity
LOCAL_LDLIBS	+= -llog

LOCAL_SRC_FILES	:= fr_planquart_jni_JNIActivity.cpp

LOCAL_SRC_FILES += fr/planquart/jni/JVM.cpp
LOCAL_SRC_FILES += fr/planquart/jni/Class.cpp
LOCAL_SRC_FILES += fr/planquart/jni/Object.cpp
LOCAL_SRC_FILES += fr/planquart/jni/String.cpp
LOCAL_SRC_FILES += fr/planquart/jni/Field.cpp
LOCAL_SRC_FILES += fr/planquart/jni/Method.cpp
LOCAL_SRC_FILES += fr/planquart/jni/traits/Callable.cpp
LOCAL_SRC_FILES += fr/planquart/jni/traits/StaticCallable.cpp
LOCAL_SRC_FILES += fr/planquart/jni/traits/FieldStructure.cpp
LOCAL_SRC_FILES += fr/planquart/jni/traits/StaticFieldStructure.cpp
LOCAL_SRC_FILES += fr/planquart/jni/traits/Monitor.cpp

include $(BUILD_SHARED_LIBRARY)

