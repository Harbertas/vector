#include "student.hpp"

Student::Student(const Student &stud) {
    name__ = stud.name();
    surname__ = stud.surname();
    grades_ = stud.grades();
    exam_ = stud.exam();
}

Student& Student::operator=(const Student& stud) {
    name__ = stud.name();
    surname__ = stud.surname();
    grades_ = stud.grades();
    exam_ = stud.exam();
    return *this;
}

bool Student::operator==(const Student& stud) {
    return (name__ == stud.name() && surname__ == stud.surname() && grades_ == stud.grades() && exam_ == stud.exam());
}

bool Student::operator!=(const Student& stud) {
    return !(name__ == stud.name() && surname__ == stud.surname() && grades_ == stud.grades() && exam_ == stud.exam());
}

std::ostream& operator<<(std::ostream& out, const Student& stud) {
    out << std::left << std::setw(20) << stud.name__ << std::left << std::setw(20) << stud.surname__ << std::left << std::setw(20) << stud.finalGrade();
    return out;
}

double Student::finalGrade(double (*func) (vector<int>)) const {
    return 0.4 * func(grades_) + 0.6 * exam_;
}

bool compareBySurname(const Student& a, const Student& b) {
    if (a.surname() != b.surname())
        return a.surname() < b.surname();
    else
        return a.name() < b.name();
}