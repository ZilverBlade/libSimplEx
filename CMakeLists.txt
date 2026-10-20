cmake_minimum_required(VERSION 3.14)

SET(ZB_SIMPLEX_BUILD_TESTS ON)
SET(ZB_SIMPLEX_BUILD_EXAMPLES ON)

if (ZB_SIMPLEX_BUILD_TESTS)
  enable_testing()
endif()

add_subdirectory(src)

if (ZB_SIMPLEX_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if (ZB_SIMPLEX_BUILD_TESTS)
  add_subdirectory(tests)
endif()