cmake_minimum_required(VERSION 3.16)

project(testOGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include_directories(${PROJECT_SOURCE_DIR}/deps/)
  
add_subdirectory(deps/glad)
set(APP_SOURCES 
  src/main.cpp
  src/helpers.cpp
)

execute_process(COMMAND cp -r assets/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
# creates ./build/bin/testOGL
add_executable(${PROJECT_NAME} ${APP_SOURCES})
# dl pthread X11 Xxf86vm Xrandr Xi
# -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl
# removed: glad
target_link_libraries(${PROJECT_NAME} GL glfw glad dl pthread)

