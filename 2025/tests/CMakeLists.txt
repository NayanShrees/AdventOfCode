include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Disable GoogleTest installation" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(TARGET_TEST AoC_Tests)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/days.cpp
)

add_executable(${TARGET_TEST} ${SOURCES})

target_link_libraries(
  ${TARGET_TEST}
  PUBLIC
  GTest::gtest_main
  ${UTILITY_LIB}
  ${AOC_LIB}
)

include(GoogleTest)
gtest_discover_tests(${TARGET_TEST})
