cmake_minimum_required(VERSION 3.10)
#项目名
project(Decorator)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Decorator 
${SRC_FILES})

target_include_directories(Decorator PUBLIC ${PROJECT_SOURCE_DIR})