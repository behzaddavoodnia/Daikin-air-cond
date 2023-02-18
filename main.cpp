
#include "air_cond.hpp"

//using namespace std;

int main(int argc, char* argv[]){
    
    air_cond ac(-100, 300);
    
    ac.setMinTemp(18);
    ac.setMaxTemp(22);
    ac.showTemp();


    return 0;
}