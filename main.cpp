
#include "air_cond.hpp"

//using namespace std;

int main(int argc, char* argv[]){
    
    float min, max;

    air_cond ac(-100, 300);
    
    std::cout << "Hello User! Please enter minimum and maximum tempreture: \n";
    std::cin >> min;
    std::cin >> max;
    ac.checkValid(min, max);

    ac.setMinTemp(min);
    ac.setMaxTemp(max);
    ac.setCurrTemp(ac.SenseTempFromSensor(CURR_TEMP));
    
    ac.showTemp();


    return 0;
}