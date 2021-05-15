//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, TestAdd){
    EXPECT_EQ(Add(7, 9), 16);
    EXPECT_EQ(Add(7, 7), 14);
    EXPECT_EQ(Add(0, 7), 7);
}