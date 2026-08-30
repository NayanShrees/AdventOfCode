cmake_minimum_required(VERSION 4.1.6)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(AdventOfCode VERSION 0.1)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  if(CMAKE_HOST_UNIX)
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink
      "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json"
      "${CMAKE_SOURCE_DIR}/build/compile_commands.json"
    )
  endif()
endif()

add_subdirectory(libs/utility)
add_subdirectory(src)

option(DEVELOPMENT_MODE "Enable development mode" OFF)
