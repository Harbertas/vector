#pragma once

#include <string>
#include <iostream>

class Person {
    protected:
        std::string name__;
        std::string surname__;

    public:
        Person() : name__(""), surname__("") {}
        Person(std::string name, std::string surname);
        
        inline std::string name() const { return name__; }
        inline std::string surname() const { return surname__; }

        virtual void setName(std::string name) = 0;
        virtual void setSurame(std::string surname) = 0;

        friend bool operator<(const Person& a, const Person& b); // less than operator
        friend bool operator>(const Person& a, const Person& b); // greater than operator
        friend bool operator<=(const Person& a, const Person& b); // less than or equal to operator
        friend bool operator>=(const Person& a, const Person& b); // greater than or equal to operator

        virtual std::ostream& write(std::ostream&) const;
        friend std::ostream& operator<<(std::ostream&, const Person&);
};