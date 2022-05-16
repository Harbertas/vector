#include <iostream>
#include <vector>
#include "vector.hpp"
#include "vector.cpp"

int main() {
  vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';

}

// DONE ----------
// assign   +
// at       +
// back     +
// begin    +
// capacity +
// cbegin   +
// cend     +
// clear    +
// crbegin  +
// crend    +
// data     +
// emplace  +
// emplace_back +
// empty    +
// end      +
// erase    +
// front    +
// get_allocator    +
// insert   +
// max_size +
// pop_back +
// push_back    +
// rbegin   +
// rend     +
// reserve  +
// resize   +
// shrink_to_fit  +
// size     +
// swap     +