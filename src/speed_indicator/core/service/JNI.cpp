#include "JNI.hpp"

#include "service/SpeedService.hpp"

#include <jni.h>


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /* reserved */)
{
    s_indicator::SpeedService::instance().setJvm(vm);

    return JNI_VERSION;
}