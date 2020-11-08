#include <jni.h>
#include <string>

extern "C" {
extern int arm_add(int a, int b);
extern int arm_sub(int a, int b);
extern void strcopy(char *d, const char *s);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_assemblydemo_MainActivity_addTest(
        JNIEnv *env,
        jobject /* this */, jint a, jint b) {
    int i1 = arm_add(a, b);
    char *dest = (char *) malloc(11);
    sprintf(dest, "add=%d", i1);
    return env->NewStringUTF(dest);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_assemblydemo_MainActivity_subTest(JNIEnv *env, jobject thiz, jint a, jint b) {
    int i1 = arm_sub(a, b);
    char *dest = (char *) malloc(11);
    sprintf(dest, "sub=%d", i1);
    return env->NewStringUTF(dest);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_assemblydemo_MainActivity_strTest(JNIEnv *env, jobject thiz) {
    char *dest = (char *) malloc(200);
    const char *srcstr = "First string - source";
    char dstchar[] = "Second string - destination";
    strcopy(dstchar, srcstr);
    sprintf(dest, "str=%s", dstchar);
    return env->NewStringUTF(dest);
}