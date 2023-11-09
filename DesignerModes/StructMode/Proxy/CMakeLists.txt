cmake_minimum_required(VERSION 3.10)
#项目名
project(Proxy)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Proxy 
${SRC_FILES})

target_include_directories(Proxy PUBLIC ${PROJECT_SOURCE_DIR})