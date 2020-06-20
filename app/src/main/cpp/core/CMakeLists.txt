project(throttle_core)

set(SOURCES
        main.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

find_library(log-lib log)

target_link_libraries(${PROJECT_NAME} ${log-lib})
