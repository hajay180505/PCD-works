cmake_minimum_required(VERSION 3.10)

# Project name
project(FiniteStateAutomaton)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(headers)

# Add source files
set(SOURCE_FILES
        src/FiniteStateAutomaton.cpp
        src/State.cpp
        src/Transition.cpp
        src/TransitionTable.cpp
        src/utils.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})
