cmake_minimum_required(VERSION 3.10)
#项目名
project(Iterator)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Iterator 
${SRC_FILES})

target_include_directories(Iterator PUBLIC ${PROJECT_SOURCE_DIR})