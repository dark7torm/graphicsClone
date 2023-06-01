#include "obj.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Constructor loads a filename with the .obj extension
OBJ::OBJ(std::string fileName){
    std::ifstream input;
    input.open(fileName);
    if(!input.is_open()) {
        std::cout << "Filepath does not exist" << fileName << std::endl;
        std::cout << "Make sure your path is correct relative to where you execute the program" << std::endl;
    } 
    std::string line;
    while(getline(input, line)) { 
        std::stringstream stream(line);
        std::string value;
        if(line.front() == '#') {
            continue;
        }
        while(stream >> value) {
            if(value.front() == 'v') {
                
            } else if(value == "vn") {
                m_width = stoi(value);
                
            } else if(value.front() == 'f') {
                m_height = stoi(value);
                
            }
        }
    }


  input.close();
    
}

// Destructor deletes(delete or delete[]) any memory that has been allocated
// or otherwise calls any 'shutdown' or 'destroy' routines for this deletion
// to occur. This class does not have any dynamically allocated memory using
// "new", so the destructor is empty
OBJ::~OBJ(){}



