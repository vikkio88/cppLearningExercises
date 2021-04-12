cmake_minimum_required(VERSION 3.16)

project(vulkTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(APP_SOURCES 
  src/main.cpp
  src/Game.cpp
)

# creates ./build/bin/vulkTest
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw vulkan dl pthread X11 Xxf86vm Xrandr Xi)

