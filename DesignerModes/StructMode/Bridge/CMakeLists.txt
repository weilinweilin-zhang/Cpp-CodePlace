cmake_minimum_required(VERSION 3.10)
#项目名
project(Bridge)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Bridge 
${SRC_FILES})

target_include_directories(Bridge PUBLIC ${PROJECT_SOURCE_DIR})