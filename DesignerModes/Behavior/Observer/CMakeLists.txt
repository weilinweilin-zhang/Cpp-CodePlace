cmake_minimum_required(VERSION 3.10)
#项目名
project(Observerh)

file(GLOB SRC_FILES ./*.cpp ./*.h)
add_executable(Observer 
${SRC_FILES})

target_include_directories(Observer PUBLIC ${PROJECT_SOURCE_DIR})