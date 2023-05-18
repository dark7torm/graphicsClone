// Compile with:
// g++ -std=c++17 datasize.cpp -o prog
#include <iostream>

int main(){

	// Most of the time a 'signed int' is abbreviated as simply an 'int'e.
	std::cout << "Data size of int in bytes = " << sizeof(int) << std::endl;
	// Most of the time a 'signed char' is abbreviated as simply a 'char'.	
	std::cout << "Data size of char in bytes = " << sizeof(char) << std::endl;
	// If we are truly trying to represent a number, than a uint8_t is preferred.
	// This is an 'unsigned integer' that can hold 8 bits of information.	
	std::cout << "Data size of uint8_t in bytes = " << sizeof(uint8_t) << std::endl;
	
	// Additionally, we have types that allow us decimal precision.
	std::cout << "Data size of float in bytes = " << sizeof(float) << std::endl;
	std::cout << "Data size of double in bytes = " << sizeof(double) << std::endl;

	return 0;
}
