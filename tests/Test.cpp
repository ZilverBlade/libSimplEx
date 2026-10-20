#include <gtest/gtest.h>
#include <SimplEx/SimplEx.h>
TEST(TestBootstrap, TestVersion) {
    EXPECT_GT(SpxVersion(), 0);
}