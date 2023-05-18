// Compile with:
// g++ -std=c++17 output.cpp -o prog
#include <iostream>
#include <fstream>

int main(){


  std::ofstream outFile;
  outFile.open("temp.txt");
  outFile << "# Some image data" << std::endl;
  outFile << "my name is ren and I like totoro" << std::endl;
  outFile.close();

  // I hope you are typing out the examples and experimenting.

	return 0;
}
