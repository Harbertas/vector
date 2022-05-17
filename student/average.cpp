#include "average.hpp"

double median(vector<int> grades) {
    std::sort(grades.begin(), grades.end());

    if(grades.size() % 2 == 0) {
        return (grades[grades.size()/2] + grades[(grades.size() / 2) - 1]) / 2.0;
    } else  {
        return grades[grades.size()/2];
    }
}

double average(vector<int> arr) {
    if(arr.size() > 0) {
        return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
    } else {
        return 0;
    }
}