cmake_minimum_required(VERSION 3.10)
#项目名
project(Visitor)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Visitor 
${SRC_FILES})

target_include_directories(Visitor PUBLIC ${PROJECT_SOURCE_DIR})