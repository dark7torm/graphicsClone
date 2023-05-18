// g++ -std=c++17 memory.cpp -o prog
#include <iostream>
#include <vector>


int main(int argc, char** argv){
  // unsigned 8 bit integer, * means pointer
  uint8_t* contiguous_chunk_of_memory = new uint8_t[80];

  uint8_t* one_item = new uint8_t;

  std::cout << "sizeof(contiguous...) =" << sizeof(contiguous_chunk_of_memory) << std::endl;

  delete one_item;
  delete[] contiguous_chunk_of_memory;
  




  // We'll have to get comfortable with working with memory.
  //
  // Eventually we'll be passing around memory from the CPU to GPU and back.
  //
  // That's why I am so adamant you type out the examples now and get practice in early.
  //
  // You can add more to them too--that's the best way to learn!

    return 0;
}
