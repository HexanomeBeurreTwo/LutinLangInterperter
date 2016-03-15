cmake_minimum_required(VERSION 2.8)
#project name
set(project_name lut)
project(${project_name})

FIND_PACKAGE(Boost COMPONENTS regex REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

include_directories(./src/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -L\"C:/Program Files/Boost/boost_1_55_0/stage/lib\" -lboost_regex")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -lboost_regex")
endif ()


file(GLOB source_files "./src/*.cpp")
file(GLOB header_files "./src/*.h")

add_executable(${project_name} ${header_files} ${source_files})
TARGET_LINK_LIBRARIES(${project_name} ${Boost_LIBRARIES})