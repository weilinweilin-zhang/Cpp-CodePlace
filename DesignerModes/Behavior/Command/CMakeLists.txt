cmake_minimum_required(VERSION 3.10)
#项目名
project(Command)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Command 
${SRC_FILES})

target_include_directories(Command PUBLIC ${PROJECT_SOURCE_DIR})