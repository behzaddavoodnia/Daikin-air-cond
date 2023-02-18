#include "air_cond.hpp"


void air_cond::setMinTemp(int minTemp){

    _minTemp = minTemp;

}

void air_cond::setMaxTemp(int MaxTemp){

    _MaxTemp = MaxTemp;

}


int air_cond::getMinTemp() {

    return _minTemp;
}


int air_cond::getMaxTemp() {
    
    return _MaxTemp;
}

void air_cond::showTemp(){
    
    std::cout << "Tempreture is between: " << _minTemp << " and " << _MaxTemp << " \n";

}