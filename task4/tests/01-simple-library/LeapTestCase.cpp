//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"
#include <Functions.h>

TEST_F(LeapTestCase, yearIsPositive) {
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
}

//-------------------------------------------------------------------------------

/*if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
    return true;
  }
  return false;  <--- THIS CASE
*/

TEST_F(LeapTestCase, yearTest1) {
    EXPECT_FALSE(IsLeap(13));
}

/*if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true; <--- THIS CASE
    }
    return true; 
  }
  return false;  
*/

TEST_F(LeapTestCase, yearTest2) {
    EXPECT_TRUE(IsLeap(16));
}

/*if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false; <--- THIS CASE
      }
    } else {
      return true;
    }
    return true; 
  }
  return false;  
*/

TEST_F(LeapTestCase, yearTest3) {
    EXPECT_FALSE(IsLeap(100));
}

/*if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true; <--- THIS CASE
      } else {
        return false; 
      }
    } else {
      return true;
    }
    return true; 
  }
  return false;  
*/

TEST_F(LeapTestCase, Test5) {
    EXPECT_TRUE(IsLeap(400));
}

//-----------------------------------------------------------------------------------------------

/*if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false; 
      }
    } else {
      return true;
    }
    return true; <--- THIS CASE IS STUPID, UNATTAINABLE STATE
  }
  return false;  
*/


TEST_F(LeapTestCase, Test6) {
    EXPECT_EQ(GetMonthDays(2021, 4), 30);
}