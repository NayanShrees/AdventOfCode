set(TARGET_LIBRARY libAoC)
set(TARGET_LIBRARY ${TARGET_LIBRARY} PARENT_SCOPE)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/lib)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/days/day_one.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/file_reader.cpp
)

add_library(${TARGET_LIBRARY} SHARED ${SOURCES})
target_include_directories(${TARGET_LIBRARY} PUBLIC ${INCLUDE_DIR})
