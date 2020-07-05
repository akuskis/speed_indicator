project(speed_indicator_core)

#
# flags
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

#
# sources
#
set(SOURCES
        main.cpp
        Configuration.cpp
        engine/Engine.cpp
        engine/Fps.cpp
        gui/GraphicsObject.cpp
        gui/SpeedIndicator/SpeedIndicator.cpp
        gui/SpeedIndicator/BasePlate.cpp
        misc/ExtraPrimitives.cpp
        misc/Point.cpp
        misc/Size.cpp
        widget/Widget.cpp
        )

include_directories(.)

#
# build
#
add_library(${PROJECT_NAME} SHARED ${SOURCES})

find_library(log-lib log)

target_link_libraries(${PROJECT_NAME} PUBLIC ${log-lib} SDL2 SDL2_gfx hidapi GLESv3 android)
