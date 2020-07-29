#include <jni.h>


namespace s_indicator
{
    class SpeedService
    {
    public:
        static SpeedService& instance();

        void setJvm(JavaVM* vm);
        int getCurrentSpeed();

    private:
        SpeedService() = default;

        JavaVM* vm_ = nullptr;
        JNIEnv* env_ = nullptr;
        jclass jniStateClass_;
        jmethodID getCurrentSpeedMethod_;

        void initialize();
    };
} // namespace s_indicator
