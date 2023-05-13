// Files that end in the .cpp extension are 'C++' files

// Bring in libraries here
#include <iostream> // input and output 'stream' library
#include <vector>   // std::vector data structure.

void PrintVector(const std::vector<int>& v) {
	std::cout << "PrintVector" << std::endl;
	for(int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << std::endl;
	}
}

void PrintRawArray(int array[], int size) {
	std::cout << "PrintRawArray" << std::endl;
	for(int i = 0; i < size; i++) {
		std::cout << array[i] << std::endl;
	}
}

int main(){
	std::cout << "Hello my name is Ren" << std::endl;

	// Raw array
	int array[3] = {1, 2, 3};


	// this is a data structure that abstracts around a raw array, 
	// so it is a little safer, and can have some member functions
	// do some actions
	std::vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	PrintVector(myVector);
	PrintRawArray(myVector.data(), myVector.size());
	return 0;


}
