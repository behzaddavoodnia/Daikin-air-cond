#ifndef AIR_COND_H
#define AIR_COND_H

#define MAX_TEMP 1500;
#define MIN_TEMP -273;

class air_cond {

private:
 int minTemp = MIN_TEMP;
 int MaxTemp = MAX_TEMP;

public:

virtual ~air_cond() {};
air_cond(int min, int max) : minTemp(min), MaxTemp(max) {}

virtual int getMinTemp(int _minTemp);
virtual int getMaxTemp(int _MaxTemp);

virtual int setMinTemp(int _minTemp);
virtual int setMaxTemp(int _MaxTemp);


};


#endif