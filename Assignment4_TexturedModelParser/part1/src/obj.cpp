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

    std::string path = fileName.substr(0, fileName.find_last_of('/') + 1);
    m_directory_path = path;

    if(!input.is_open()) {
        std::cout << "Filepath does not exist" << fileName << std::endl;
        std::cout << "Make sure your path is correct relative to where you execute the program" << std::endl;
    } 

    std::string line;

    std::vector<glm::vec3> v_pos;
    std::vector<glm::vec2> v_tex;
    std::vector<glm::vec3> v_norm;

    std::vector<unsigned int> v_posn_indices;
    std::vector<unsigned int> v_tex_indices;
    std::vector<unsigned int> v_norm_indices;

    while(getline(input, line)) { 
        std::stringstream stream(line);
        std::string token;
        while(stream >> token) {
            if(token.front() == 'v' && token.size() == 1) {
                glm::vec3 position;
                stream >> position.x >> position.y >> position.z;
                v_pos.push_back(position);
            } else if(token == "vn") {
                glm::vec3 normal;
                stream >> normal.x >> normal.y >> normal.z;
                v_norm.push_back(normal);
            } else if(token == "vt") {
                glm::vec2 texCoord;
                stream >> texCoord.x >> texCoord.y;
                v_tex.push_back(texCoord);
            } else if(token.front() == 'f') {
                std::string vertexData;
                for (unsigned int i = 0; i < 3; ++i) {
                 stream >> vertexData;
                    std::istringstream viss(vertexData);
                    std::string indexStr;
                    std::getline(viss, indexStr, '/');
                    unsigned int positionIndex = std::stoi(indexStr) - 1;
                    v_posn_indices.push_back(positionIndex);

                    std::getline(viss, indexStr, '/');
                    unsigned int texCoordIndex = std::stoi(indexStr) - 1;
                    v_tex_indices.push_back(texCoordIndex);
                    

                    std::getline(viss, indexStr, '/');
                    unsigned int normalIndex = std::stoi(indexStr) - 1;
                    v_norm_indices.push_back(normalIndex);
                }
            } else if (token == "mtllib") {
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

    m_vertices.resize(v_posn_indices.size());

    for (int i = 0; i < m_vertices.size(); ++i) {
        
        m_vertices[i].position = v_pos[v_posn_indices[i]];
        m_vertices[i].color = glm::vec3(0.f, 0.f, 0.f);
        m_vertices[i].texCoord = v_tex[v_tex_indices[i]];
        m_vertices[i].normal = v_norm[v_norm_indices[i]];
        m_indices.push_back(i);
    }


    
    

  input.close();
}

// Destructor deletes(delete or delete[]) any memory that has been allocated
// or otherwise calls any 'shutdown' or 'destroy' routines for this deletion
// to occur. This class does not have any dynamically allocated memory using
// "new", so the destructor is empty
OBJ::~OBJ(){}





