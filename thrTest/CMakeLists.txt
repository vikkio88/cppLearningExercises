cmake_minimum_required(VERSION 3.16)

project(thrTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(APP_SOURCES 
  src/main.cpp
)

# creates ./build/bin/thrTest
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} pthread)

