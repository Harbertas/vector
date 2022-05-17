#pragma once

#include <string>
#include "../vector.hpp"
#include <numeric>
#include <iostream>
#include <iomanip>

#include "../person/person.hpp"
#include "average.hpp"

class Student : public Person {
    private:
        int exam_;
        vector<int> grades_;
    public:
        Student() : exam_(0) {} // default constructor
        Student(std::string name, std::string surname, vector<int> grades, int exam) : Person(name, surname), grades_(grades), exam_(exam) {}
        ~Student() { grades_.clear(); } // destructor
        Student(const Student& stud); // copy constructor

        Student& operator=(const Student& stud); // copy assignment operator
        friend std::ostream& operator<<(std::ostream& out, const Student& stud); // insertion operator

        bool operator==(const Student& stud);
        bool operator!=(const Student& stud);

        inline std::string name() const { return name__; }
        inline std::string surname() const { return surname__; }
        inline int exam() const { return exam_; }
        inline vector<int> grades() const { return grades_; }

        void setName(std::string name) { name__ = name; }
        void setSurame(std::string surname) { surname__ = surname; }
        inline void setGrades(vector<int> grades) { grades_ = grades; }
        inline void setExam(int exam) { exam_ = exam; }

        double finalGrade(double (*func) (vector<int>) = average) const;
};