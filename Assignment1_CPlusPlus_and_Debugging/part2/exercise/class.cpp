// g++ -std=c++17 class.cpp -o prog
#include <iostream>
#include <vector>



class PPM{
    public:
    
    PPM(unsigned int width, unsigned int height) {
        pixelData = new unsigned char(width*height*3);
    }

    ~PPM() {
        delete[] pixelData;
    }



    private:    // Data not visible to a user of 
            // this object.
    uint8_t* pixelData;

};

int main(int argc, char** argv){

    // You know what you need to do... :) Type it out.
    //
    //
    // Here's something I found funny as a reward:
    // https://stackoverflow.blog/2021/04/19/how-often-do-people-actually-copy-and-paste-from-stack-overflow-now-we-know/
    //
    // (Stack overflow is good too--but copying and pasting doesn't help us learn)
    //
    //
    // Anyway, at this point you know most of the C++ you'll need to get you through the course.
    PPM myPPM(64, 128);
    return 0;
}
