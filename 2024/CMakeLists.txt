cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(AoC VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

set(TEXT_RESOURCES
    ${CMAKE_SOURCE_DIR}/resources/day_1/day_1_example.txt
    ${CMAKE_SOURCE_DIR}/resources/day_1/day_1.txt
)

file(
    COPY
    ${TEXT_RESOURCES}
    DESTINATION
    ${BINARY_OUTPUT_DIR}
)

file(
    COPY
    ${TEXT_RESOURCES}
    DESTINATION
    ${TESTS_OUTPUT_DIR}
)
