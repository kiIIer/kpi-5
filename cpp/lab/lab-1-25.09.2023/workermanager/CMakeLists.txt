cmake_minimum_required(VERSION 3.25)
project(workermanager)

set(CMAKE_CXX_STANDARD 17)
set(FRUIT_USES_BOOST FALSE)


set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dep)

add_subdirectory(${DEPENDENCIES_DIR}/json)

add_subdirectory(${DEPENDENCIES_DIR}/fruit)

add_executable(workermanager main.cpp Employee.cpp Employee.h IJsonParser.h JsonParser.cpp JsonParser.h test.h IJsonParser.cpp IGetCommand.cpp IGetCommand.h GetCommand.cpp GetCommand.h Commands.cpp Commands.h IAddCommand.cpp IAddCommand.h AddCommand.cpp AddCommand.h IDeleteCommand.cpp IDeleteCommand.h DeleteCommand.cpp DeleteCommand.h)

target_include_directories(workermanager PRIVATE ${DEPENDENCIES_DIR})

target_link_libraries(workermanager PRIVATE nlohmann_json::nlohmann_json fruit)

