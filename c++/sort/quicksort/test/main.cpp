#include "gtest/gtest.h"

TEST(example, add) {
double res;
res = add_numbers(1.0, 2.0);
ASSERT_NEAR(res, 3.0, 1.0e-11);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}