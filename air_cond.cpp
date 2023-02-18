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

void air_cond::UpdateCurrTemp(float newTemp){
    
    _currentTemp += newTemp;
}


void air_cond::showTemp(){
    
    std::cout << "Desirable Tempreture is between: " << getMinTemp() <<" and " << getMaxTemp() << " \n";
    std::cout << "Current Tempreture is: " << getCurrTemp() << "\n";

}

void air_cond::checkValid(float minVal, float maxVal) {
    
    if ((minVal < MIN_TEMP) || (maxVal > MAX_TEMP) || (maxVal < minVal)){
        std::cout << "Tempreture range is invalid!\n";
        exit(EXIT_FAILURE);
        }

}