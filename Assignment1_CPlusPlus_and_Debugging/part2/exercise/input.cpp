// Compile with:
// g++ -std=c++17 input.cpp -o prog
#include <iostream>
#include <fstream> 
#include <string>

int main(int argc, char** argv){


  std::ifstream input; 


  if (argc != 2) {
    std::cerr << "There needs to be two arguments \n";
    std::cerr << "ProgramName filepath. \n";
    return 0;
  }


  input.open(argv[1]);

  if(input.is_open()) {
    std::string line;
    while(getline(input, line)) {
      std::cout << line << std::endl;
    }
  } else {
    std::cout << "Filepath does not exist" << argv[1] << std::endl;
    std::cout << "Make sure your path is correct relative to where you execute the program" << std::endl;
  }

  input.close();


  // Learning how to read in values will be useful for the course.

	return 0;
}
