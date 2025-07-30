cmake_minimum_required(VERSION 3.16)
project(Coding-Challenge CXX)

set(CMAKE_CXX_STANDARD 20)
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /O2")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Require TARGET to be passed in via command line
if(NOT DEFINED TARGET)
    message(FATAL_ERROR "You must pass -DTARGET=XX when configuring CMake.")
endif()

# Set file paths
set(SRC ${CMAKE_SOURCE_DIR}/src/${TARGET}.cpp)
set(EXECUTABLE_NAME ${TARGET})

# Add the executable
add_executable(${EXECUTABLE_NAME} ${SRC})

# Put the binary in the build/ directory
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
)

# Add a custom 'run' target
add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/build/${TARGET} < ${CMAKE_SOURCE_DIR}/input/${TARGET}.txt
    DEPENDS ${EXECUTABLE_NAME}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
