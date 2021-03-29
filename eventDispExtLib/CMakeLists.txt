cmake_minimum_required(VERSION 3.16)

project(eventDisp2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# the -I flag in compiler
include_directories(
  ${PROJECT_SOURCE_DIR}/deps/eventDisp/includes/
)

set(APP_SOURCES 
  src/main.cpp
)

# creates ./build/bin/eventDisp2
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/deps/eventDisp/libEventDispatcher.so)

