#include "SpeedService.hpp"

#include "JNI.hpp"


namespace s_indicator
{
SpeedService& SpeedService::instance()
{
    static SpeedService instance_;
    return instance_;
}

void SpeedService::setJvm(JavaVM* vm)
{
    vm_ = vm;
}

int SpeedService::getCurrentSpeed()
{
    JNIEnv* env;
    vm_->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION);

    jclass jniTestClass = env->FindClass("com/example/speed_indicator/State");

    jmethodID getCurrentSpeedMethod = env->GetStaticMethodID(jniTestClass, "getCurrentSpeed", "()D");

    return (int)env->CallStaticDoubleMethod(jniTestClass, getCurrentSpeedMethod);
}

} // namespace s_indicator
