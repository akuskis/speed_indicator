#include "JService.hpp"

#include <cmath>
#include <cstdlib>
#include <jni.h>
#include <thread>


namespace
{
double getCurrentSpeed()
{
    using namespace std::chrono;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    return (std::sin(ms.count() / 1000.) + 1) * 50
           + (std::sin(ms.count() / 2000.) + 1) * 30
           + (std::sin(ms.count() / 3000.) + 1) * 30;
}

} // namespace


extern "C" JNIEXPORT void JNICALL Java_com_example_speed_1indicator_DataServiceThread_startGenerator(JNIEnv* env,
                                                                                                     jobject obj)
{
    data_generator::JService service(env, obj);

    using namespace std::chrono_literals;
    while (!service.isInterrupted())
    {
        std::this_thread::sleep_for(20ms);

        auto value = getCurrentSpeed();
        service.submitCurrentSpeed(value);
    }
}
