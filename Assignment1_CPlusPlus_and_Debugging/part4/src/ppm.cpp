#include "PPM.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Constructor loads a filename with the .ppm extension
PPM::PPM(std::string fileName){
    std::ifstream input;
    input.open(fileName);
    int valueNum = 0;
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
            if(value.front() == '#') {
                break;
            }
            if(valueNum == 0 ) {
                ++valueNum;
            } else if(valueNum == 1) {
                m_width = stoi(value);
                ++valueNum;
            } else if(valueNum == 2) {
                m_height = stoi(value);
                ++valueNum;
            } else if (valueNum == 3) {
                m_maxRGB = stoi(value);
                ++valueNum;
            } else {
                m_PixelData.push_back(stoi(value));
            }
        }
    }


  input.close();
    
}

// Destructor deletes(delete or delete[]) any memory that has been allocated
// or otherwise calls any 'shutdown' or 'destroy' routines for this deletion
// to occur. This class does not have any dynamically allocated memory using
// "new", so the destructor is empty
PPM::~PPM(){}

// Saves a PPM Image to a new file.
void PPM::savePPM(std::string outputFileName) const {
    std::ofstream output;
    output.open(outputFileName);
    output << "P3" << std::endl;
    output << "# some_image.ppm" << std::endl;
    output << m_width << " " << m_height << std::endl;
    output << m_maxRGB << std::endl;
    int spaceCount = 0;
    for(int i = 0; i < m_PixelData.size(); ++i) {
        output << unsigned(m_PixelData.at(i)) << std::endl;
    }
    output.close();


}

// Darken halves (integer division by 2) each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be less than
// 0 in a ppm.
void PPM::darken(){
    for(int i = 0; i < m_PixelData.size(); ++i) {
        m_PixelData[i] = m_PixelData[i] / 2;
    }
}

// Lighten doubles (integer multiply by 2) each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be greater than
// 255 in a ppm.
void PPM::lighten(){
    for(int i = 0; i < m_PixelData.size(); ++i) {
        int dataAsInt = static_cast<uint8_t>(m_PixelData[i]) * 2;
        if(dataAsInt <= 255) {
            m_PixelData[i] = static_cast<int>(dataAsInt);
        } else m_PixelData[i] = 255;
 
    }
}

// Sets a pixel to a specific R,G,B value 
// Note: You do not *have* to use setPixel in your implementation, but
//       it may be useful to implement.
void PPM::setPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B){
    // TODO: Optional to implement.
}
