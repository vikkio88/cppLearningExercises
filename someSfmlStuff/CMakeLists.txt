cmake_minimum_required(VERSION 3.16)

project(someStuff)
set(CMAKE_CXX_STANDARD 17)


# SFML Lib installed with apt-get install sfml-dev
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# the -I flag in compiler
include_directories(
  ${PROJECT_SOURCE_DIR}/include/
)


set(YOKU_LIB_SOURCES 
  include/yoku/Assets.cpp
  include/yoku/SceneManager.cpp
  include/yoku/Window.cpp
  include/yoku/Game.cpp
)
set(YOKU_LIBRARY_NAME yoku)
add_library(${YOKU_LIBRARY_NAME} STATIC ${YOKU_LIB_SOURCES})

set(APP_SOURCES 
  src/main.cpp
  src/TestGame.cpp
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


#add_compile_definitions(FPS=1)
message("Build Type: " ${CMAKE_BUILD_TYPE})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_definitions(DEBUG)
endif()

# copying assets
file(COPY src/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
# creates ./build/bin/someStuff
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system ${YOKU_LIBRARY_NAME})