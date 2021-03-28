cmake_minimum_required(VERSION 3.16)

project(dispo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")


# the -I flag in compiler
include_directories(
  ${PROJECT_SOURCE_DIR}/include/
)

set(EVENT_DISPATCHER_LIB_SOURCES 
  include/eventDispatcher/EventDispatcher.cpp
  include/eventDispatcher/Event.cpp
)

set(APP_SOURCES 
  src/main.cpp
)

set(EVENT_DISPATCHER_LIBRARY_NAME EventDispatcher)
add_library(${EVENT_DISPATCHER_LIBRARY_NAME} SHARED ${EVENT_DISPATCHER_LIB_SOURCES})

# creates ./build/bin/dispo
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} ${EVENT_DISPATCHER_LIBRARY_NAME} pthread)