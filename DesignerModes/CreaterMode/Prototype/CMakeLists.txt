cmake_minimum_required(VERSION 3.10)
#项目名
project(Prototype)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Prototype 
${SRC_FILES})

target_include_directories(Prototype PUBLIC ${PROJECT_SOURCE_DIR})