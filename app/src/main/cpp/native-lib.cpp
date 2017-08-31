#include <jni.h>
#include <string>
extern "C"
JNIEXPORT jstring
Java_per_mm_ouhaibo_nativetest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from JNI";
    return env->NewStringUTF(hello.c_str());
}
