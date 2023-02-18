#include <iostream>

#ifndef AIR_COND_H
#define AIR_COND_H


#define MAX_TEMP 1500;
#define MIN_TEMP -273;

class air_cond {

private:

 int _minTemp = MAX_TEMP;
 int _MaxTemp = MIN_TEMP;



public:

    virtual ~air_cond(){};

    air_cond (int min, int max) : _minTemp(min), _MaxTemp(max) {

        std::cout << "Hello Daikin!\n";
    };

    virtual int getMinTemp();
    virtual int getMaxTemp();

    virtual void setMinTemp(int minTemp);
    virtual void setMaxTemp(int MaxTemp);

    virtual void showTemp();


};


#endif