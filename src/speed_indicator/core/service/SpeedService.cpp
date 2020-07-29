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
    if (!env_)
        initialize();

    return (int)env_->CallStaticDoubleMethod(jniStateClass_, getCurrentSpeedMethod_);
}

void SpeedService::initialize()
{
    vm_->GetEnv(reinterpret_cast<void**>(&env_), JNI_VERSION);
    jniStateClass_ = env_->FindClass("com/example/speed_indicator/State");
    getCurrentSpeedMethod_ = env_->GetStaticMethodID(jniStateClass_, "getCurrentSpeed", "()D");
}

} // namespace s_indicator
