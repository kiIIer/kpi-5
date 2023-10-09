cmake_minimum_required(VERSION 3.25)
project(workermanager)

set(CMAKE_CXX_STANDARD 17)
set(FRUIT_USES_BOOST FALSE)


set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dep)

add_library(entities SHARED
        entities/Employee.cpp
        entities/Employee.h
        )

add_subdirectory(${DEPENDENCIES_DIR}/json)

add_subdirectory(${DEPENDENCIES_DIR}/fruit)

#add_executable(workermanager main.cpp entities/Employee.cpp entities/Employee.h tools/IJsonParser.h tools/JsonParser.cpp tools/JsonParser.h tools/IJsonParser.cpp commands/Get/IGetCommand.cpp commands/Get/IGetCommand.h commands/Get/GetCommand.cpp commands/Get/GetCommand.h commands/Commands.cpp commands/Commands.h commands/Add/IAddCommand.cpp commands/Add/IAddCommand.h commands/Add/AddCommand.cpp commands/Add/AddCommand.h commands/Delete/IDeleteCommand.cpp commands/Delete/IDeleteCommand.h commands/Delete/DeleteCommand.cpp commands/Delete/DeleteCommand.h commands/Move/IMoveCommand.cpp commands/Move/IMoveCommand.h commands/Move/MoveCommand.cpp commands/Move/MoveCommand.h)
add_executable(workermanager main.cpp tools/IJsonParser.h tools/JsonParser.cpp tools/JsonParser.h tools/IJsonParser.cpp commands/Get/IGetCommand.cpp commands/Get/IGetCommand.h commands/Get/GetCommand.cpp commands/Get/GetCommand.h commands/Commands.cpp commands/Commands.h commands/Add/IAddCommand.cpp commands/Add/IAddCommand.h commands/Add/AddCommand.cpp commands/Add/AddCommand.h commands/Delete/IDeleteCommand.cpp commands/Delete/IDeleteCommand.h commands/Delete/DeleteCommand.cpp commands/Delete/DeleteCommand.h commands/Move/IMoveCommand.cpp commands/Move/IMoveCommand.h commands/Move/MoveCommand.cpp commands/Move/MoveCommand.h)

target_include_directories(workermanager PRIVATE ${DEPENDENCIES_DIR})
target_include_directories(entities PRIVATE ${DEPENDENCIES_DIR})

target_link_libraries(entities PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(workermanager PRIVATE nlohmann_json::nlohmann_json fruit entities)
