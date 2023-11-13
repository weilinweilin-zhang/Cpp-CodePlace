cmake_minimum_required(VERSION 3.10)
#项目名
project(State)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(State 
${SRC_FILES})

target_include_directories(State PUBLIC ${PROJECT_SOURCE_DIR})