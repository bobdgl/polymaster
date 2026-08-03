#include <jni.h>
#include <android/log.h>
#include <memory>

// Forward declarations из PolyMaster
namespace pm {
    class Engine;
}

#define LOG_TAG "PolyMaster"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Для теста - просто логируем
extern "C" {
    JNIEXPORT void JNICALL
    Java_com_polymaster_editor_NativeEngine_init(JNIEnv* env, jobject obj, jint width, jint height) {
        LOGI("PolyMaster Engine Init: %dx%d", width, height);
    }
    
    JNIEXPORT void JNICALL
    Java_com_polymaster_editor_NativeEngine_update(JNIEnv* env, jobject obj, jfloat deltaTime) {
        LOGI("Update: %.2f ms", deltaTime);
    }
    
    JNIEXPORT void JNICALL
    Java_com_polymaster_editor_NativeEngine_render(JNIEnv* env, jobject obj) {
        LOGI("Render frame");
    }
    
    JNIEXPORT void JNICALL
    Java_com_polymaster_editor_NativeEngine_shutdown(JNIEnv* env, jobject obj) {
        LOGI("Engine shutdown");
    }
}
