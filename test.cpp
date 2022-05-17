#include <iostream>
#include <vector>
#include "vector.hpp"
#include "vector.cpp"

int main() {
  
    vector<int> alice{1, 2, 3};
    vector<int> bob{7, 8, 9, 10};
    vector<int> eve{1, 2, 3};
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << (alice == bob) << '\n';
    std::cout << (alice != bob) << '\n';
    std::cout << (alice < bob) << '\n';
    std::cout << (alice <= bob) << '\n';
    std::cout << (alice > bob) << '\n';
    std::cout << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << (alice == eve) << '\n';
    std::cout << (alice != eve) << '\n';
    std::cout << (alice < eve) << '\n';
    std::cout << (alice <= eve) << '\n';
    std::cout << (alice > eve) << '\n';
    std::cout << (alice >= eve) << '\n';
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