#include "obj.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <glad/glad.h>
#include <glm/glm.hpp>


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
        while(stream >> value) {
            if(value.front() == 'v') {
                glm::vec3 position;
                stream >> position.x >> position.y >> position.z;
                m_vertices.push_back({ position, glm::vec3(0.0f), glm::vec2(0.0f) });
            } else if(value == "vn") {
                glm::vec3 normal;
                stream >> normal.x >> normal.y >> normal.z;
                if (!m_vertices.empty()) {
                m_vertices.back().normal = normal;
                }
            } else if(value == "vt") {
                glm::vec2 texCoord;
                stream >> texCoord.x >> texCoord.y;
                if (!m_vertices.empty()) {
                m_vertices.back().texCoord = texCoord;
                }
            } else if(value.front() == 'f') {
                std::string vertexData;
                for (unsigned int i = 0; i < 3; ++i) {
                 stream >> vertexData;
                    std::istringstream viss(vertexData);

                    std::string indexStr;
                    std::getline(viss, indexStr, '/');
                    unsigned int positionIndex = std::stoi(indexStr) - 1;

                    std::getline(viss, indexStr, '/');
                    unsigned int texCoordIndex = std::stoi(indexStr) - 1;

                    std::getline(viss, indexStr, '/');
                    unsigned int normalIndex = std::stoi(indexStr) - 1;

                    m_indices.push_back(m_vertices.size());

                    m_vertices.push_back({
                        m_vertices[positionIndex].position,
                        m_vertices[normalIndex].normal,
                        m_vertices[texCoordIndex].texCoord
                    });
                }
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



