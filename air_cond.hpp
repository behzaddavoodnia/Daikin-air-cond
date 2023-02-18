#include <iostream>
#include <sstream>
#include <string>

#ifndef AIR_COND_H
#define AIR_COND_H


#define MAX_TEMP 1500
#define MIN_TEMP -273
#define CURR_TEMP 20 

class air_cond {

private:

 float _minTemp = MAX_TEMP;
 float _MaxTemp = MIN_TEMP;
 float _currentTemp = CURR_TEMP;



public:

    virtual ~air_cond(){};

    air_cond (float min,  float max) : _minTemp(min), _MaxTemp(max) {

        std::cout << "[================ Hello Daikin! ==============]\n\n";
    };



    virtual void setMinTemp(float minTemp);
    virtual void setMaxTemp(float MaxTemp);
    virtual void setCurrTemp(float currTemp);
    
    virtual float getMinTemp();
    virtual float getMaxTemp();
    virtual float getCurrTemp();
    
    virtual void checkValid(float minVal, float maxVal);
    virtual void showTemp();


};


#endif