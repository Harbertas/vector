#include "functions.hpp"

int main() {
    // vector<Student> v;
    // read_data(v, "1000st_10nd.txt");

    // Student stud(v[0]);
    // cout << stud.name() << " " << stud.surname() << " " << stud.finalGrade() << "\n";
    // stud = v[1];
    // cout << stud.name() << " " << stud.surname() << " " << stud.finalGrade() << "\n";
    // cout << (stud == v[0]) << "\n";
    // cout << (stud == v[1]) << "\n";
    // cout << (stud != v[0]) << "\n";
    // cout << (stud != v[1]) << "\n";
    // cout << stud;

    // for(auto stud:v)
    //     cout << stud.name() << " " << stud.surname() << " " << stud.finalGrade() << "\n";
    
    string cont;
    cout << "Koki konteineri norite naudoti?\n1 - vector\n2 - std::list\n3 - std::deque\n";
    while(true) {
        cin >> cont;
        if (check_select3(cont)) {
            break;
        } else {
            cout << "Iveskite 1, 2 arba 3\n";
        }
    }

    string act;
    cout << "Ka norite daryti?\n1 - ivesti duomeis\n2 - sugeneruoti duomenis\n3 - surusioti studentus i vargsiukus ir kietiakus\n";
    while(true) {
        cin >> act;
        if (check_select3(act)) {
            break;
        } else {
            cout << "Iveskite 1, 2 arba 3\n";
        }
    }

    int container = std::stoi(cont);
    int action = std::stoi(act);

    switch(action) {
        case 1:
            // manual data input
            switch (container) {
                case 1:
                    // vector
                    vector_data_input();
                    break;
                case 2:
                    // list
                    list_data_input();
                    break;
                case 3:
                    // deque
                    deque_data_input();
                    break;
            }
            break;
        case 2:
            // generate data
            generate_data();
            break;
        case 3:
            // read data from file, split into 2 files
            switch (container) {
                case 1:
                    // vector
                    vector_student_sorting();
                    break;
                case 2:
                    // list
                    list_student_sorting();
                    break;
                case 3:
                    // deque
                    deque_student_sorting();
                    break;
            }
            break;
    }
}