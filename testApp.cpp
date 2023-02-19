#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "air_cond.hpp"

using ::testing::Return;

class MockedAirCond : public air_cond {


public:
    MockedAirCond() = default;


    MOCK_METHOD(float, getMinTemp, ());
    MOCK_METHOD(float, getMaxTemp, ());
    MOCK_METHOD(float, getCurrTemp, ());
    
     MOCK_METHOD(void, setMinTemp, (float minTemp));
     MOCK_METHOD(void, setMaxTemp, (float MaxTemp));
     MOCK_METHOD(void, setCurrTemp, (float currTemp));
     MOCK_METHOD(void, setGoalTemp, (float min, float max));
    

     MOCK_METHOD(void, Init, ());
     MOCK_METHOD(void, IncreaseTemp, (float step, int numOfSteps));
     MOCK_METHOD(void, DecreaseTemp, (float step, int numOfSteps));
     MOCK_METHOD(void, UpdateCurrTemp, (float heaterPower, float coolerPower));
     MOCK_METHOD(float, SenseTempFromSensor, (float analogTemp));
     MOCK_METHOD(bool, checkValid, (float minVal, float maxVal));
     MOCK_METHOD(void, showSensedTemp, ());
     MOCK_METHOD(void, showCurrTemp, ());


};

//**************************** Start of testcases *******************************//

TEST(DaikinAPItestSuit, checkValid){

    MockedAirCond mc;
    float min, max;
    std::cout << "Hello User! Please enter minimum and maximum tempreture (°C): \n";
    std::cin >> min;
    std::cin >> max;

    EXPECT_CALL(mc, checkValid(testing::_, testing::_)).Times(1).WillRepeatedly(Return(true));
    ASSERT_TRUE(mc.checkValid(min, max));
    ASSERT_GE(min, MIN_TEMP);
    ASSERT_LE(max, MAX_TEMP);
    ASSERT_GE(max, min);
    ASSERT_LE(min, max);
}

TEST(DaikinAPItestSuit, setMinTemp){

    MockedAirCond mc;
    const float min = -100;
    EXPECT_CALL(mc, setMinTemp(testing::_)).Times(1).WillOnce(Return());
    mc.setMinTemp(min);
  
}

TEST(DaikinAPItestSuit, setMaxTemp){

    MockedAirCond mc;
    const float max = 100;
    EXPECT_CALL(mc, setMaxTemp(testing::_)).Times(1).WillOnce(Return());
    mc.setMaxTemp(max);

}

TEST(DaikinAPItestSuit, setGoalTemp){

    MockedAirCond mc;
    EXPECT_CALL(mc, setGoalTemp(testing::_, testing::_)).Times(1).WillOnce(Return());
    mc.setGoalTemp(MIN_TEMP, MAX_TEMP);

}

TEST(DaikinAPItestSuit, SenseTempFromSensor){

    MockedAirCond mc;
    float test = 100;
    EXPECT_CALL(mc, SenseTempFromSensor(test)).Times(1).WillRepeatedly(Return(test));
    float returnVal = mc.SenseTempFromSensor(test);
    ASSERT_EQ(test, returnVal);
    ASSERT_GE(returnVal, MIN_TEMP);
    ASSERT_LE(returnVal, MAX_TEMP);  
}

TEST(DaikinAPItestSuit, setCurrTemp){

    MockedAirCond mc;
    const float tmp = 20;
    EXPECT_CALL(mc, setCurrTemp(testing::_)).Times(1).WillOnce(Return());
    mc.setCurrTemp(tmp);

}


TEST(DaikinAPItestSuit, getMinTemp){

    MockedAirCond mc;
    float test1 = 0.0;
    //mc.setMinTemp(test1);
    EXPECT_CALL(mc, getMinTemp()).Times(1).WillOnce(Return(0.0));
    ASSERT_EQ(mc.getMinTemp(), test1);

}


TEST(DaikinAPItestSuit, getMaxTemp){

    MockedAirCond mc;
    float test2 = 0.0;
    //mc.setMaxTemp(test2);
    EXPECT_CALL(mc, getMaxTemp()).Times(1).WillOnce(Return(0.0));
    float pest = mc.getMaxTemp();
    ASSERT_EQ(pest, test2);

}


TEST(DaikinAPItestSuit, getCurrTemp){

    MockedAirCond mc;
    float test3 = 0.0;
    //mc.setCurrTemp(test3);
    EXPECT_CALL(mc, getCurrTemp()).Times(1).WillOnce(Return(0.0));
    float pest = mc.getCurrTemp(); 
    ASSERT_EQ(pest, test3);
}


TEST(DaikinAPItestSuit, DecreaseTemp){

    MockedAirCond mc;
    EXPECT_CALL(mc, DecreaseTemp(testing::_,testing::_)).Times(1).WillOnce(Return());
    mc.DecreaseTemp(TEMP_STEP, 100); 
}


TEST(DaikinAPItestSuit, IncreaseTemp){

    MockedAirCond mc;
    EXPECT_CALL(mc, IncreaseTemp(testing::_, testing::_)).Times(1).WillOnce(Return());
    mc.IncreaseTemp(TEMP_STEP, 100);
}

TEST(DaikinAPItestSuit, UpdateCurrTemp){

    MockedAirCond mc;
    EXPECT_CALL(mc, UpdateCurrTemp(testing::_, testing::_)).Times(1).WillOnce(Return());
    mc.UpdateCurrTemp(HEATER_PWR, COOLER_PWR);
}

//************************ End of testcases *******************************//

int main(int argc, char* argv[]){

testing::InitGoogleTest(&argc, argv);

return RUN_ALL_TESTS();

    
}