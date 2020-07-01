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
        )

#
# build
#
add_library(${PROJECT_NAME} SHARED ${SOURCES})

find_library(log-lib log)

target_link_libraries(${PROJECT_NAME} PUBLIC ${log-lib} SDL2 hidapi GLESv3 android)
