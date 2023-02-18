#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

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

 float _minTemp = MAX_TEMP;
 float _MaxTemp = MIN_TEMP;
 float _currentTemp = SENSE_TEMP;
 float _GoalTemp = 0;
 unsigned int _engExeTime = 0;
 my_mood mood = ok;


public:

    virtual ~air_cond(){};

    air_cond (float min,  float max) : _minTemp(min), _MaxTemp(max) {

        std::cout << "[================ Hello Daikin! ==============]\n\n";
    };



    virtual void setMinTemp(float minTemp);
    virtual void setMaxTemp(float MaxTemp);
    virtual void setCurrTemp(float currTemp);
    virtual void setGoalTemp(float min, float max);
    
    virtual float getMinTemp();
    virtual float getMaxTemp();
    virtual float getCurrTemp();
    
    virtual void Init();
    virtual void IncreaseTemp(float step, int numOfSteps);
    virtual void DecreaseTemp(float step, int numOfSteps);
    virtual void UpdateCurrTemp(float heaterPower, float coolerPower);
    virtual float SenseTempFromSensor(float analogTemp);
    virtual void checkValid(float minVal, float maxVal);
    virtual void showSensedTemp();
    virtual void showCurrTemp();


};


#endif