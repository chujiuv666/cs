#include <jni.h>
#include <android/log.h>

#define LOG_TAG "NativeSim"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

static int memory[1024] = {0};
static int X25 = 400;
static int sunOffset = 596;

extern "C" JNIEXPORT void JNICALL
Java_com_example_arm64sim_MainActivity_initSun(JNIEnv* env, jobject) {
    memory[X25 + sunOffset] = 1000;
    LOGI("初始化阳光数：%d", memory[X25 + sunOffset]);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_arm64sim_MainActivity_useSun(JNIEnv* env, jobject, jint cost) {
    int &sun = memory[X25 + sunOffset];
    sun -= cost;
    if (sun < 0) sun = 0;
    LOGI("扣除阳光 %d 后，剩余 %d", cost, sun);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_arm64sim_MainActivity_getSun(JNIEnv* env, jobject) {
    return memory[X25 + sunOffset];
}
