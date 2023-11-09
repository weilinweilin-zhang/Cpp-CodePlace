cmake_minimum_required(VERSION 3.10)
#项目名
project(Flyweight)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Flyweight 
${SRC_FILES})

target_include_directories(Flyweight PUBLIC ${PROJECT_SOURCE_DIR})