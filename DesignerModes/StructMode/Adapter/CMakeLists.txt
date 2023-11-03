cmake_minimum_required(VERSION 3.10)
#项目名
project(Adapt)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Adapt 
${SRC_FILES})

target_include_directories(Adapt PUBLIC ${PROJECT_SOURCE_DIR})