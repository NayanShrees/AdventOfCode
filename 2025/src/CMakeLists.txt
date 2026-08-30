set(TARGET_APP AoC)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/days/day_1.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(${TARGET_APP} ${SOURCES})
target_include_directories(${TARGET_APP} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${TARGET_APP} PUBLIC ${UTILITY_LIB})

if(DEVELOPMENT_MODE)
  target_compile_definitions(${TARGET_APP} PRIVATE DEVELOPMENT_MODE)
endif()

set_target_properties(${TARGET_APP}
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  INSTALL_RPATH "$ORIGIN/../lib;$ORIGIN/../lib/utility"
)

include(FetchContent)
FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts GIT_TAG v3.3.1)
FetchContent_MakeAvailable(cxxopts)
target_link_libraries(${TARGET_APP} PRIVATE cxxopts::cxxopts)

add_custom_command(
  TARGET ${TARGET_APP} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets"
    "$<TARGET_FILE_DIR:${TARGET_APP}>/../assets"
)

install(TARGETS ${TARGET_APP}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/assets"
  DESTINATION "."
  FILES_MATCHING PATTERN "*"
)
