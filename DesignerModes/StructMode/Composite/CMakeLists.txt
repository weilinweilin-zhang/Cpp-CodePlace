cmake_minimum_required(VERSION 3.10)
#项目名
project(Composite)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Composite 
${SRC_FILES})

target_include_directories(Composite PUBLIC ${PROJECT_SOURCE_DIR})