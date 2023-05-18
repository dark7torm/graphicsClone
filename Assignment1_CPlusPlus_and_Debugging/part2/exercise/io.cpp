// Compile with:
// g++ -std=c++17 io.cpp -o prog
#include <iostream>

int main(){

	// Type out the example and have some fun with this one.
	std::cout << "Hello" << std::endl;
	std::cout << "What year are you?" << std::endl;

	int year;

	std::cin >> year;
	std::cout << "You are so old for being in year " << year << std::endl;


	return 0;
}
