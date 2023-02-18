
#include "air_cond.hpp"

//using namespace std;

int main(int argc, char* argv[]){
    
    air_cond ac(-100, 300);
    ac.Init();
    ac.IncreaseTemp(TEMP_STEP,100);
    ac.UpdateCurrTemp(HEATER_PWR, COOLER_PWR);
    ac.showCurrTemp();


    return 0;
}