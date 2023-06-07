/** @file OBJ.hpp
 *  @brief Class for working with OBJ images
 *  
 *  Class for working with P3 OBJ images specifically.
 *
 *  @author your_name_here
 *  @bug No known bugs.
 */

#ifndef OBJ_HPP
#define OBJ_HPP
#include <glm/glm.hpp>

#include <string>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
};

// struct Vertex2 {
//     float x, y, z, s, t;

//     VertexData(float _x, float _y, float _z, float _s, float _t): x(_x),y(_y),z(_z),s(_s),t(_t) { }
// }



class OBJ{
public:
    // Constructor loads a filename with the .obj extension
    OBJ(std::string fileName);
    // Destructor clears any memory that has been allocated
    ~OBJ();
    
    inline std::vector<Vertex> getVertices() const { return m_vertices; }
    inline std::vector<unsigned int> getIndices() const { return m_indices; }
    inline std::vector<float> getPositions(){
        // for(int i = 0; i < m_textured_vertices.size(); ++i) {
        //     m_vertexTest.push_back(m_textured_vertices[i].position.x);
        //     m_vertexTest.push_back(m_textured_vertices[i].position.y);
        //     m_vertexTest.push_back(m_textured_vertices[i].position.z);
        //     m_vertexTest.push_back(0.f);
        //     m_vertexTest.push_back(0.f);
        //     m_vertexTest.push_back(0.f);
        //     m_vertexTest.push_back(m_textured_vertices[i].texCoord.x);
        //     m_vertexTest.push_back(m_textured_vertices[i].texCoord.y);
        // }
        return m_textured_vertices;
     }
    inline std::vector<float> getVertexTextures() const { return m_vertex_textures; }
    inline std::vector<float> getVertexNormals() const { return m_vertex_normals; }
    inline std::vector<float> getFaces() const { return m_faces; }
    inline std::string getPPM() { return m_directory_path + m_ppm_filename; }
    
private:    
    std::string m_directory_path;
    std::string m_ppm_filename;
    // std::vector<Vertex2> m_vertexTest;
    std::vector<Vertex> m_vertices;
    std::vector<float> m_positions;
    std::vector<unsigned int> m_indices;
    std::vector<float> m_vertex_textures;
    std::vector<float> m_vertex_normals;
    std::vector<float> m_faces;
    std::vector<float> m_textured_vertices;

};


#endif
