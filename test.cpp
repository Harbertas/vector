#include <iostream>
#include <vector>
#include "vector.hpp"
#include "vector.cpp"

int main() {
  
  unsigned int sz = 100000000;
  int p1 = 0, p2 = 0;

  std::vector<int> v1;
  for (int i = 1; i <= sz; ++i) {
    v1.push_back(i);
    if (v1.size() == v1.capacity())
      p1++;
  }

  vector<int> v2;
  for (int i = 1; i <= sz; ++i) {
    v2.push_back(i);
    if (v2.size() == v2.capacity())
      p2++;
  }

  std::cout << "p1: " << p1 << "\np2: " << p2;
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