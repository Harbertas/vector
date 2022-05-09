#include <iostream>
#include <vector>
#include "vector.hpp"
#include "vector.cpp"

int main() {
    std::vector<int> v;
    vector<int> v1;


    std::cout << v.size() << "\n";
    std::cout << v1.size() << "\n";
    v.push_back(3);
    v.push_back(8);
    v.push_back(44);
    v.push_back(23);
    // v.push_back(5);

    v1.push_back(8);
    // v1.push_back(44);
    v1.push_back(23);
    v1.push_back(3);
    v1.push_back(5);
    std::cout << v.capacity() << "\n";
    std::cout << v1.capacity() << "\n";

    std::cout << v[3] << "\n";
    std::cout << v1[3] << "\n";

}