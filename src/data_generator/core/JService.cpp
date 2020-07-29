#include "JService.hpp"


namespace data_generator
{
JService::JService(JNIEnv* env, jobject& obj)
    : env_(env)
    , obj_(obj)
{
    jclass jniClass = env_->FindClass("com/example/speed_indicator/DataServiceThread");

    submitCurrentSpeedMethod_ = env_->GetMethodID(jniClass, "submitCurrentSpeed", "(D)V");
    isInterrupredMethod_ = env_->GetMethodID(jniClass, "isInterrupted", "()Z");
}

void JService::submitCurrentSpeed(double value)
{
    env_->CallVoidMethod(obj_, submitCurrentSpeedMethod_, value);
}

bool JService::isInterrupted()
{
    return env_->CallBooleanMethod(obj_, isInterrupredMethod_);
}
} // namespace data_generator
