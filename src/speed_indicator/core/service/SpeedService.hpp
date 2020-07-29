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
    };
} // namespace s_indicator
