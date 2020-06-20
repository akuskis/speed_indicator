cmake_minimum_required(VERSION 3.4.1)

#
# flags
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
set(CMAKE_CXX_STANDARD 17)

#
# sources
#
add_subdirectory(core)
add_subdirectory(tests)
