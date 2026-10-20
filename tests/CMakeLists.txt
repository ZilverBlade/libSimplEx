cmake_minimum_required(VERSION 3.14)

include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723 # release-1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(libSimplExTests
    Test.cpp
)

gtest_discover_tests(libSimplExTests)

target_link_libraries(libSimplExTests
  libSimplEx
  GTest::gtest_main
  GTest::gmock_main
)
