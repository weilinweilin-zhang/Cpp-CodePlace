cmake_minimum_required(VERSION 3.10)
#项目名
project(Strategy)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Strategy 
${SRC_FILES})

target_include_directories(Strategy PUBLIC ${PROJECT_SOURCE_DIR})