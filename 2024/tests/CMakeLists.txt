include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TARGET_TEST AoCTests)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/days/test_day_one.cpp
)

add_executable(${TARGET_TEST} ${SOURCES})

target_link_libraries(
  ${TARGET_TEST}
  PUBLIC
  GTest::gtest_main
  ${TARGET_LIBRARY}
)

include(GoogleTest)
gtest_discover_tests(${TARGET_TEST})

set(TESTS_OUTPUT_DIR ${CMAKE_BINARY_DIR}/tests PARENT_SCOPE)
