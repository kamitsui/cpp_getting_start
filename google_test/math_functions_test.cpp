#include <gtest/gtest.h>
//#include "gtest/gtest.h"
#include "math_functions.h"

TEST(MathFunctionsTest, AddPositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathFunctionsTest, AddNegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(MathFunctionsTest, AddZero) {
    EXPECT_EQ(add(0, 5), 5);
}
