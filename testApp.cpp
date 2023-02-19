#include <gtest/gtest.h>

#include "air_cond.hpp"

TEST(Daikin_test_suit, Daikin_test){

    air_cond ac(-100, 300);
    int output = ac.SenseTempFromSensor(SENSE_TEMP);
    ASSERT_EQ(20, output);
}


int main(int argc, char* argv[]){

testing::InitGoogleTest(&argc, argv);

return RUN_ALL_TESTS();

    
}