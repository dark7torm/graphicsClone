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

#include <string>

class OBJ{
public:
    // Constructor loads a filename with the .OBJ extension
    OBJ(std::string fileName);
    // Destructor clears any memory that has been allocated
    ~OBJ();
    // Returns the raw pixel data in an array.
    // You may research what 'inline' does.
    // You may also want to research what 'const' does on a function.
    // In brief, 'const' gaureentees that we are not modifying 
    // any member variables in a class, and this is useful if we are
    // returning private member variables.
    inline std::vector<uint8_t> pixelData() const { return m_PixelData; }
    // Returns image width
    inline int getWidth() const { return m_width; }
    // Returns image height
    inline int getHeight() const { return m_height; }
// NOTE:    You may add any helper functions you like in the
//          private section.
private:    
    // Store the raw pixel data here
    // Data is R,G,B format
    // Note: Yes, you are allowed to replace 'uint8_t* m_PixelDatal' with a std::vector<uint8_t> m_PixelData.
    //       In fact, using a std::vector will likely make your life easier.    
    std::vector<uint8_t> m_PixelData;
    // Store width and height of image.
    int m_width{0};
    int m_height{0};
    int m_maxRGB{0};
};


#endif
