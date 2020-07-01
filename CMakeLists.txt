cmake_minimum_required(VERSION 3.4.1)

#
# flags
#
set(CMAKE_CXX_STANDARD 17)

#
# SDL
#
add_subdirectory(third_party/SDL2)
include_directories(third_party/SDL2/include)

#
# sources
#
add_subdirectory(src)
