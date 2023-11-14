cmake_minimum_required(VERSION 3.10)
#项目名
project(Mediator)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Mediator 
${SRC_FILES})

target_include_directories(Mediator PUBLIC ${PROJECT_SOURCE_DIR})