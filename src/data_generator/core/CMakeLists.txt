project(data_generator)

#
# flags
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

#
# sources
#
set(SOURCES
        main.cpp
        JService.cpp
        )

include_directories(.)

#
# build
#
add_library(${PROJECT_NAME} SHARED ${SOURCES})

find_library(log-lib log)

target_link_libraries(${PROJECT_NAME} PUBLIC ${log-lib} android)
