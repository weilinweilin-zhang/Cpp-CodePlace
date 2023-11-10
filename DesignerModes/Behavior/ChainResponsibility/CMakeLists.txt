cmake_minimum_required(VERSION 3.10)
#项目名
project(ChainResponsibility)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(ChainResponsibility 
${SRC_FILES})

target_include_directories(ChainResponsibility PUBLIC ${PROJECT_SOURCE_DIR})