#include <jni.h>
#include <string>
#include <android/log.h>
#include <stdlib.h>
#include <unistd.h>

#define  LOG_TAG    "nativeprint"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__

jint intFromFastJNI(
        JNIEnv* env,
        jclass clazz) {
    return 123;
}

jint intFromNormalJNI(
        JNIEnv* env,
        jclass clazz) {
    return 123;
}

jint intFromCriticalJNI() {
    return 123;
}


static const JNINativeMethod jniNativeMethod[] = {
        {"intFromFastJNI", "()I", (void *) (intFromFastJNI)},
        {"intFromNormalJNI", "()I", (void *) (intFromNormalJNI)},
        {"intFromCriticalJNI", "()I", (void *) (intFromCriticalJNI)},
};


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *javaVm, void *pVoid) {
    JNIEnv *jniEnv = nullptr;
    jint result = javaVm->GetEnv(reinterpret_cast<void **>(&jniEnv), JNI_VERSION_1_6);
    if (result != JNI_OK) {
        return -1;
    }

    jclass jniClass = jniEnv->FindClass("me/linjw/demo/ndk/MainActivity");
    jniEnv->RegisterNatives(
            jniClass,
            jniNativeMethod,
            sizeof(jniNativeMethod) / sizeof(JNINativeMethod)
    );
    return JNI_VERSION_1_6;
}