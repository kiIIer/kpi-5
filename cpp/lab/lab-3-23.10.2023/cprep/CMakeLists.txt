cmake_minimum_required(VERSION 3.25)
project(cprep)

set(CMAKE_CXX_STANDARD 17)

set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dep)

set(Boost_INCLUDE_DIR ${DEPENDENCIES_DIR})
#set(FRUIT_USES_BOOST FALSE)


add_subdirectory(${DEPENDENCIES_DIR}/fruit)

add_executable(cprep main.cpp program/IProgram.cpp program/IProgram.h program/Program.cpp program/Program.h program/option-parser/IOptionParser.cpp program/option-parser/IOptionParser.h program/worker/IWorker.cpp program/worker/IWorker.h program/result-parser/IResultExporter.cpp program/result-parser/IResultExporter.h program/queue/IQueueFactory.cpp program/queue/IQueueFactory.h program/utils/Task.h program/utils/Option.h program/utils/Result.h program/queue/IQueue.cpp program/queue/IQueue.h)

target_include_directories(cprep PRIVATE ${DEPENDENCIES_DIR})
target_link_libraries(cprep PRIVATE fruit)
