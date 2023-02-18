#include "air_cond.hpp"

int air_cond::setMinTemp(int _minTemp){

    minTemp = _minTemp;

}

int air_cond::setMaxTemp(int _MaxTemp){

    MaxTemp = _MaxTemp;

}


int air_cond::getMinTemp(int _minTemp) {

    return _minTemp;
}


int air_cond::getMaxTemp(int _MaxTemp) {
    
    return _MaxTemp;
}