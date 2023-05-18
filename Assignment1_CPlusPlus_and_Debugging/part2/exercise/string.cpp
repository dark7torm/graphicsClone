// Compile with:
// g++ -std=c++17 string.cpp -o prog
#include <iostream>

int main(){

  // Type out the example.
  // We'll work with std::strings a lot to parse and manipulate data.

  std::string fullName = "Ren Taguchi";

  std::string first = fullName.substr(0,3);
  std::string last = fullName.substr(4, 11);

  std::cout << "First: " << first << std::endl;
  std::cout << "Last: " << last << std::endl;


  unsigned int i = 0;
  while (i < fullName.length()) {
    if(fullName.at(i) == ' ') {
      break;
    }
    std::cout << fullName[i];
    ++i;
  }
	return 0;
}
