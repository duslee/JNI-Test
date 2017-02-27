// test.cpp

#include <stdio.h>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

jstring Java_com_jeff_customjnitest_MainActivity_get(JNIEnv *env, jobject thiz) {
    printf("invoke get in c++\n");
    return env->NewStringUTF("Hello from JNI in libjni-test.so!");
}

void Java_com_jeff_customjnitest_MainActivity_set(JNIEnv *env, jobject thiz, jstring string) {
    printf("invoke set from c++\n");
    char *str = (char*) env->GetStringUTFChars(string, NULL);
    printf("%s\n", str);
    env->ReleaseStringUTFChars(string, str);
}

#ifdef __cplusplus
}
#endif
