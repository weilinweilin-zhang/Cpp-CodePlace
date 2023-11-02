cmake_minimum_required(VERSION 3.10)
#项目名
project(Singleton)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Singleton 
${SRC_FILES})

target_include_directories(Singleton PUBLIC ${PROJECT_SOURCE_DIR})