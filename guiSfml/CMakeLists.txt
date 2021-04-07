cmake_minimum_required(VERSION 3.16)

project(guiSfml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)


# SFML Lib installed with apt-get install sfml-dev
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
# TGUI installed with https://tgui.eu/tutorials/0.9/linux/
find_package(TGUI 0.9)

set(APP_SOURCES 
  src/main.cpp
)

# creates ./build/bin/guiSfml
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system tgui)

