#include <stdio.h>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

void callJavaMethod(JNIEnv *env, jobject thiz) {
    jclass clazz = env->FindClass("com/jeff/customjnitest/MainActivity");
    if (clazz == NULL) {
        printf("find class MainActivity error!");
        return;
    }

    jmethodID id = env->GetStaticMethodID(clazz, "methodCalledByJni", "(Ljava/lang/String;)V");
    if (NULL == id)
        printf("find method methodCalledByJni error!");

    jstring msg = env->NewStringUTF("msg send by calledJavaMethod in test2.cpp");
    env->CallStaticVoidMethod(clazz, id, msg);
}

jstring Java_com_jeff_customjnitest_MainActivity_get2(JNIEnv *env, jobject thiz) {
    printf("invoke get in c++\n");
    callJavaMethod(env, thiz);
    return env->NewStringUTF("Hello from JNI in libjni-test.so!=====");
}

#ifdef __cplusplus
}
#endif