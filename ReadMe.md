======== How to build and run =========

1. sudo apt install google-mock && libgmock-dev

2. download google test suit from https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip and unzip file

3. cd path/to/googletest

4. sudo cmake CMakeLists.txt 

5. sudo make

6. cd lib

7. sudo cp *.a /usr/lib

8. cd ../googlemock/include

9. sudo cp -r gmock /usr/local/include/

10. cd ../../googletest/include

11. sudo cp -r gtest /usr/local/include/

12. Now you can include gtest and gmock header files in your code
13. Go to your project code directory. 

14. mkdir build && cd build
15. cmake .. && make
16. ./mainApp
17. ./testApp
