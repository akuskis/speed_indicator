cmake_minimum_required(VERSION 3.4.1)

#
# flags
#
set(CMAKE_CXX_STANDARD 17)

#
# SDL
#
add_subdirectory(third_party/freetype)
include_directories(third_party/freetype/include)

add_subdirectory(third_party/SDL2)
include_directories(third_party/SDL2/include)

add_subdirectory(third_party/SDL2_gfx)
include_directories(third_party/SDL2_gfx)

add_subdirectory(third_party/SDL2_ttf)
include_directories(third_party/SDL2_ttf)

#
# sources
#
add_subdirectory(src)
