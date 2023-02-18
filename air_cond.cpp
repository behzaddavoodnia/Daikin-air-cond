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
    std::cout << "Goal (target) tempreture should be: " << _GoalTemp << "\n";
}


void air_cond::Init(){
    
    float min, max;
    std::cout << "Hello User! Please enter minimum and maximum tempreture: \n";
    std::cin >> min;
    std::cin >> max;
    checkValid(min, max);
    setMinTemp(min);
    setMaxTemp(max);
    setGoalTemp(min, max);
    setCurrTemp(SenseTempFromSensor(SENSE_TEMP));
    showInitTemp();

}


void air_cond::UpdateCurrTemp(float heaterPower, float coolerPower){

    if(_currentTemp > _minTemp && _currentTemp < _MaxTemp){
        std::cout << "Temp is: "<< _currentTemp << " and it is OK!\n";
        mood = ok;
        _engExeTime = 0;
    }
    else if(_currentTemp < _minTemp && _currentTemp < _MaxTemp) {

        mood = hot;
        std::cout << "Wheather is: " << _currentTemp << " and it's too cold! Starting heater...\n";
        
        while((ceil(_currentTemp * 100.0) / 100.0)  == (ceil(_GoalTemp * 100.0) / 100.0)){
        _currentTemp += heaterPower;
        _engExeTime ++;
        }
    }
    else if (_currentTemp > _minTemp && _currentTemp > _MaxTemp) {

        mood = cold;
        std::cout << "Wheather is: " << _currentTemp << " and it's too hot! Starting cooler...\n";

        while((ceil(_currentTemp * 100.0) / 100.0)  == (ceil(_GoalTemp * 100.0) / 100.0)){
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
}



void air_cond::DecreaseTemp(float step, int numOfSteps){
    
    _currentTemp -= (numOfSteps * step);
}


void air_cond::showInitTemp(){
    std::cout << "===========================================\n";
    std::cout << "Desirable Tempreture is between: " << getMinTemp() <<" and " << getMaxTemp() << " \n";
    std::cout << "Initial Tempreture is: " << getCurrTemp() <<"\n";
    std::cout << "===========================================\n";

}

void air_cond::showCurrTemp(){
    std::cout << "===========================================\n";
    std::cout << "Current Tempreture after "<< _engExeTime << " minutes is: " << getCurrTemp() <<"\n";
    std::cout << "===========================================\n";

}

void air_cond::checkValid(float minVal, float maxVal) {
    
    if ((minVal < MIN_TEMP) || (maxVal > MAX_TEMP) || (maxVal < minVal)){
        std::cout << "Tempreture range is invalid!\n";
        exit(EXIT_FAILURE);
        }

}