// g++ -std=c++17 vector.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

  // Understanding how to use a std::vector will probably
  // get you through about 80% of the course.
  // Start getting practice now by typing out the example and
  // playing with it a bit.
    std::vector <unsigned char> myData;

    for(unsigned int i = 65; i < 117; ++i) {
      myData.push_back(i);
    }

    for(unsigned int i = 0; i < myData.size(); ++i) {
      std::cout << myData[i];
    }
    return 0;
}
