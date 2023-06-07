#include "obj.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <glad/glad.h>
#include <glm/glm.hpp>


// Constructor loads a filename with the .obj extension
OBJ::OBJ(std::string fileName){
    m_directory_path = fileName.substr(0,fileName.find_last_of('/') + 1);
    std::ifstream input;
    input.open(fileName);
    if(!input.is_open()) {
        std::cout << "Filepath does not exist" << fileName << std::endl;
    } 
    std::string line;
    while(getline(input, line)) { 
        std::stringstream stream(line);
        std::string value;
        while(stream >> value) {
            if(value.front() == 'v' && value.size() == 1) {
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
                        m_indices.push_back(positionIndex);
                        m_textured_vertices.push_back(m_vertices[positionIndex].position.x);
                        m_textured_vertices.push_back(m_vertices[positionIndex].position.y);
                        m_textured_vertices.push_back(m_vertices[positionIndex].position.z);

                        m_textured_vertices.push_back(0.f);
                        m_textured_vertices.push_back(0.f);
                        m_textured_vertices.push_back(0.f);

                        std::getline(viss, indexStr, '/');
                        unsigned int textureIndex = 0;
                        if(indexStr.size() != 0) {
                            textureIndex = std::stoi(indexStr) - 1;
                            m_textured_vertices.push_back(m_vertices[textureIndex].texCoord.x);
                            m_textured_vertices.push_back(m_vertices[textureIndex].texCoord.y);
                        }
                    
                    

                        std::getline(viss, indexStr, '/');
                        unsigned int normalIndex = std::stoi(indexStr) - 1;
                        m_vertex_normals.push_back(normalIndex);
                    
                }
            } else if (value == "mtllib") {
                std::string mtlFilename;
                stream >> mtlFilename;
                std::string mtlFilepath = m_directory_path + mtlFilename;
                std::ifstream mtl;
                mtl.open(mtlFilepath);

                if(!mtl.is_open()) {
                    std::cout << "Mtl filepath does not exist: " << mtlFilepath << std::endl;
                } 

                std::string mtlLine;
                while(getline(mtl, mtlLine)) {
                    std::stringstream mtlStream(mtlLine);
                    std::string mtlToken;
                    while(mtlStream >> mtlToken) {
                        if (mtlToken == "map_Kd") {
                            mtlStream >> m_ppm_filename;
                        }
                    }
                }
                mtl.close();
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



