#pragma once

#include <jni.h>

namespace data_generator
{
class JService
{
public:
    JService(JNIEnv* env, jobject& obj);

    void submitCurrentSpeed(double value);
    bool isInterrupted();

private:
    JNIEnv* env_;
    jobject obj_;

    jmethodID submitCurrentSpeedMethod_;
    jmethodID isInterrupredMethod_;
};
} // namespace s_indicator
