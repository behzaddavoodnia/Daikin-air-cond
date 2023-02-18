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



void air_cond::showTemp(){
    
    std::cout << "Tempreture is between: " << getMinTemp() <<" and " << getMaxTemp() << " \n";

}

void air_cond::checkValid(float minVal, float maxVal) {
    
    if ((minVal < MIN_TEMP) || (maxVal > MAX_TEMP) || (maxVal < minVal)){
        std::cout << "Tempreture range is invalid!\n";
        exit(EXIT_FAILURE);
        }

}