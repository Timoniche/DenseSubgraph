cmake_minimum_required(VERSION 3.17)
project(DenseSubgraph)

set(CMAKE_CXX_STANDARD 20)
set(BOOST_ROOT "/usr/local/Cellar/boost/1.75.0_1")

find_package(Boost 1.75.0 COMPONENTS graph REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

include_directories(${Boost_INCLUDE_DIRS})
add_executable(DenseSubgraph main.cpp MaxFlowBoostWrapper.h Goldbergs.h)
target_link_libraries(DenseSubgraph ${Boost_LIBRARIES})