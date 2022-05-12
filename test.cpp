#include <iostream>
#include <vector>
#include "vector.hpp"
#include "vector.cpp"

int main() {
    std::vector<int> v;
    vector<int> v1;

    v.push_back(5);
    v.push_back(4);

    v1.push_back(5);
    v1.push_back(4);

    v.assign(9, 15);
    v1.assign(9, 15);

    v.push_back(3);
    v1.push_back(3);

}

// DONE ----------
// assign
// at
// back
// begin
// cbegin
// cend
// clear
// crbegin
// crend
// data

// end

// push_back

// reserve

// shrink_to_fit
// size

// TODO ------------
// emplace
// emplace_back
// empty
// erase
// front
// get_allocator
// insert
// max_size
// pop_back
// rbegin
// rend
// resize
// swap