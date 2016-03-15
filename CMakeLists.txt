cmake_minimum_required(VERSION 2.8)
#project name
set(project_name lut)
project(${project_name})

FIND_PACKAGE(Boost COMPONENTS regex REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

include_directories(./src/ ./src/States)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -L\"C:/Program Files/Boost/boost_1_55_0/stage/lib\"")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb")
endif ()


# file(GLOB_RECURSE source_files "./src/*")
# file(GLOB_RECURSE header_files "./src/**/*.h")
aux_source_directory(src sources)
aux_source_directory(src/States stateSources)

# add_executable(${project_name} ${source_files})
add_executable(${project_name} ${sources} ${stateSources})
TARGET_LINK_LIBRARIES(${project_name} ${Boost_LIBRARIES})