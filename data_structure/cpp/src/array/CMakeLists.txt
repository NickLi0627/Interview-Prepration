add_library(array "")

target_sources(
  array
  PRIVATE
    array.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/array.h
)

target_include_directories(array PUBLIC ${CMAKE_CURRENT_LIST_DIR})
