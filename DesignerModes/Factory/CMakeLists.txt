cmake_minimum_required(VERSION 3.10)
#项目名
project(Factory)

file(GLOB SRC_FILES ./*.cpp)
add_executable(Factory 
${SRC_FILES})

target_include_directories(Factory PUBLIC ${PROJECT_SOURCE_DIR})