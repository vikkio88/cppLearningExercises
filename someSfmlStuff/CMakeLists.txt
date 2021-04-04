cmake_minimum_required(VERSION 3.16)

project(someStuff)

# SFML Lib installed with apt-get install sfml-dev
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# the -I flag in compiler
include_directories(
  ${PROJECT_SOURCE_DIR}/src/include/
) 

set(APP_SOURCES 
  src/main.cpp
  src/SceneManager.cpp
  src/Window.cpp
  src/Game.cpp
  src/scenes/GameScene.cpp
  src/scenes/SplashScreen.cpp
  src/scenes/state/GameState.cpp
  src/scenes/libs/helpers.cpp
)

# This if you want clang-tidy on build
# it is terribly slow
# set(CMAKE_CXX_CLANG_TIDY
#     clang-tidy;
#     -header-filter=.;
#     -checks=*;)
message("Build Type: " ${CMAKE_BUILD_TYPE})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("Setting build to show FPS")
  add_compile_definitions(DEBUG)
endif()

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# creates ./build/bin/someStuff
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)