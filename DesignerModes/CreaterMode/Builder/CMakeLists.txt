cmake_minimum_required(VERSION 3.10)
project(AbStractFactory)
file(GLOB SRC_FILES ./*.cpp ./Src_dp/*)
set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -W3 -g-")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -W3 -g-")
add_executable(AbStractFactory ${SRC_FILES})
target_include_directories(AbStractFactory PUBLIC ${PROJECT_SOURCE_DIR})
