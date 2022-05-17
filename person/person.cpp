#include "person.hpp"

Person::Person(std::string name, std::string surname) {
    name__ = name;
    surname__ = surname;
}

bool operator<(const Person& a, const Person& b) {
    if (a.name__ != b.name__)
        return a.name__ < b.name__;
    else
        return a.surname__ < b.surname__;
}

bool operator>(const Person& a, const Person& b) {
    if (a.name__ != b.name__)
        return a.name__ > b.name__;
    else
        return a.surname__ > b.surname__;
}

bool operator<=(const Person& a, const Person& b) {
    if (a.name__ != b.name__)
        return a.name__ <= b.name__;
    else
        return a.surname__ <= b.surname__;
}

bool operator>=(const Person& a, const Person& b) {
    if (a.name__ != b.name__)
        return a.name__ >= b.name__;
    else
        return a.surname__ >= b.surname__;
}

std::ostream& Person::write(std::ostream& os) const { 
    os << name__ << " " << surname__;
    return os;
}

std::ostream& operator<<(std::ostream& out, const Person& p) { 
    return p.write(out);
}