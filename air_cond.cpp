#include "air_cond.hpp"


void air_cond::setMinTemp(float minTemp){

    _minTemp = minTemp;

}

void air_cond::setMaxTemp(float MaxTemp){

    _MaxTemp = MaxTemp;

}


void air_cond::setCurrTemp(float currTemp){
    
    _currentTemp = currTemp;
}


float air_cond::getMinTemp() {


    return _minTemp;
}


float air_cond::getMaxTemp() {
    
    return _MaxTemp;
}


float air_cond::getCurrTemp(){

    return _currentTemp;
}


float air_cond::SenseTempFromSensor(float analogTemp){

    return analogTemp;
}

void air_cond::setGoalTemp(float min, float max){
    _GoalTemp = (min + max) / 2;
    std::cout << "Mean tempreture is: " << _GoalTemp << " °C\n";
}


void air_cond::Init(){
    
    float min, max;
    std::cout << "Hello User! Please enter minimum and maximum tempreture (°C): \n";
    std::cin >> min;
    std::cin >> max;

    if (!checkValid(min, max))
        exit(EXIT_FAILURE);
    
    setMinTemp(min);
    setMaxTemp(max);
    setGoalTemp(min, max);
    setCurrTemp(SenseTempFromSensor(SENSE_TEMP));
    showSensedTemp();

}


void air_cond::UpdateCurrTemp(float heaterPower, float coolerPower){

    if(_currentTemp >= _minTemp && _currentTemp <= _MaxTemp){
        std::cout << "Now, Temp is: "<< _currentTemp << " °C and it is OK!\n";
        mood = ok;
        _engExeTime = 0;
    }
    else if(_currentTemp < _minTemp && _currentTemp < _MaxTemp) {

        mood = cold;
        std::cout << "Now, Wheather is: " << _currentTemp << " °C and it's too cold! Starting heater...\n";
        
        while(_currentTemp < _minTemp){
        _currentTemp += heaterPower;
        _engExeTime ++;
        }
    }
    else if (_currentTemp > _minTemp && _currentTemp > _MaxTemp) {

        mood = hot;
        std::cout << "Now, Wheather is: " << _currentTemp << " °C and it's too hot! Starting cooler...\n";

        while(_currentTemp > _MaxTemp){
        _currentTemp -= coolerPower;
        _engExeTime ++;
        }
    }
    else{
        std::cout <<"Can not start engine!\n";
        exit(EXIT_FAILURE);
    }
        

}



void air_cond::IncreaseTemp(float step, int numOfSteps){
    
    _currentTemp += (numOfSteps * step);
    std::cout << "Increased Tempreture by: "<< numOfSteps * step << " °C\n";
}



void air_cond::DecreaseTemp(float step, int numOfSteps){
    
    _currentTemp -= (numOfSteps * step);
    std::cout << "Decreased Tempreture by: "<< numOfSteps * step << " °C\n";

}


void air_cond::showSensedTemp(){
    std::cout << "===========================================\n";
    std::cout << "Desirable Tempreture is between: " << getMinTemp() <<" °C and " << getMaxTemp() << " °C\n";
    std::cout << "Sensed room Tempreture is: " << getCurrTemp() <<" °C\n";
    std::cout << "===========================================\n";

}

void air_cond::showCurrTemp(){
    std::cout << "===========================================\n";
    std::cout << "Current Tempreture after "<< _engExeTime << " minutes is: " << getCurrTemp() <<" °C\n";
    std::cout << "===========================================\n";

}

bool air_cond::checkValid(float minVal, float maxVal) {
    
    if ((minVal < MIN_TEMP) || (maxVal > MAX_TEMP) || (maxVal < minVal)){
        std::cout << "Tempreture range is invalid!\n";
        return false;
        }
    return true;
}