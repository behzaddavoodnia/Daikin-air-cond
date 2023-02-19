======== How to build and run =========
1- sudo apt install google-mock && libgmock-dev

2- download google test suit from https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
unzip file

3- sudo cmake CMakeLists.txt 
4- sudo make

5- cd lib
6- sudo cp *.a /usr/lib

7- cd ../googlemock/include
8- sudo cp -r gmock /usr/local/include/

9- cd ../../googletest/include
10- sudo cp -r gtest /usr/local/include/

11- Now you can include gtest and gmock header files in your code
12- Go to your project code directory. 

13- mkdir build && cd build
14- cmake .. && make
15- ./mainApp
16- ./testApp
