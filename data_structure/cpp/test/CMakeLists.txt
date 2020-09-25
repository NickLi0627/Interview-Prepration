add_executable(
  unit_tests
  demo_test.cpp
)

target_link_libraries(
  unit_tests
  gtest_main
  demo
)

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
