#include "A/index.h" 
#include "B/lib.h"
#include "gtest/gtest.h"

TEST(testA, returnZero) {
    EXPECT_EQ(setA(), '0');
}

TEST(testB, returnOne) {
    EXPECT_EQ(setB(), '1');
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
