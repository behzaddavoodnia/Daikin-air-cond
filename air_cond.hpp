#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <gtest/gtest.h>


#ifndef AIR_COND_H
#define AIR_COND_H


#define MAX_TEMP 1500
#define MIN_TEMP -273
#define SENSE_TEMP 20
#define TEMP_STEP 0.1
#define HEATER_PWR 0.25
#define COOLER_PWR 0.25



enum my_mood {hot, cold, ok};


class air_cond {

private:

 float _minTemp = MAX_TEMP; // Min temp that user can enter
 float _MaxTemp = MIN_TEMP; // Max temp that user can enter
 float _currentTemp = SENSE_TEMP; // Sensed temp from the sensor
 float _GoalTemp = 0;   // For storing mean temp
 unsigned int _engExeTime = 0; // Time (minutes) that engine needs to execute
 my_mood mood = ok; // Mood of the room (cold, hot, ok)


public:

    virtual ~air_cond(){};

    air_cond (float min,  float max) : _minTemp(min), _MaxTemp(max) {

        std::cout << "[====================== Hello Daikin! ====================]\n\n";
    };


    // Setter APIs
    virtual void setMinTemp(float minTemp);
    virtual void setMaxTemp(float MaxTemp);
    virtual void setCurrTemp(float currTemp);
    virtual void setGoalTemp(float min, float max);
    
    // Getter APIs
    virtual float getMinTemp();
    virtual float getMaxTemp();
    virtual float getCurrTemp();
    
    // Initialization API
    virtual void Init();
    
    // An API to increase the temp by given steps
    virtual void IncreaseTemp(float step, int numOfSteps);
    
    // An API to decrease the temp by given steps
    virtual void DecreaseTemp(float step, int numOfSteps);
    
    // API to turn on/ off and control the heater/ cooler regarding the heater/ cooler power by minimum energy consumption
    virtual void UpdateCurrTemp(float heaterPower, float coolerPower);
    
    // Sensing the room temp from sensor
    virtual float SenseTempFromSensor(float analogTemp);
    
    // Checks the inputs provided by user is valid or not
    virtual void checkValid(float minVal, float maxVal);
    
    // Shows the sensed temp from the room sensor
    virtual void showSensedTemp();
    
    // Shows the current room temp
    virtual void showCurrTemp();


};


#endif