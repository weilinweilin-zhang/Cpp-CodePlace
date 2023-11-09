cmake_minimum_required(VERSION 3.10)
#项目名
project(Facade)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Facade 
${SRC_FILES})

target_include_directories(Facade PUBLIC ${PROJECT_SOURCE_DIR})