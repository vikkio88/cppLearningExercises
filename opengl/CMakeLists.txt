cmake_minimum_required(VERSION 3.16)

project(testOGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# SFML Lib installed with apt-get install sfml-dev
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
# GLEW installed with apt-get install libglew-dev
find_package(GLEW 2.1 REQUIRED)

find_package(OpenGL REQUIRED)

set(APP_SOURCES 
  src/main.cpp
)

# creates ./build/bin/testOGL
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})

