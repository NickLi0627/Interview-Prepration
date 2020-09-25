add_library(demo "")

target_sources(
  demo
  PRIVATE
    demo.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/demo.h
)

target_include_directories(demo PUBLIC ${CMAKE_CURRENT_LIST_DIR})
