#include "../functions.hpp"

void split_two_new(list<Student> arr) {
    auto start = hrClock::now();
    // calculate final grade and split students
    list<Student> vargsiukai, kietiakai;
    for(auto student:arr) {
        if (student.finalGrade() < 5)
            vargsiukai.push_back(student);
        else
            kietiakai.push_back(student);
    }
    arr.clear();

    auto stop = hrClock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";

    auto start5 = hrClock::now();

    kietiakai.sort();
    vargsiukai.sort();

    auto stop5 = hrClock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop5 - start5);
    cout << "Studentu rusiavimas pagal vardus uztruko: " << duration5.count() * 1e-9 << " \n";
    
    start = hrClock::now();
    write_students("kietiakai.txt", kietiakai);
    kietiakai.clear();
    write_students("vargsiukai.txt", vargsiukai);
    vargsiukai.clear();
    stop = hrClock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Vargsiuku ir kietiaku rasymas i failus uztruko: " << duration.count() * 1e-9 << "s\n";
    // cout << "Studentai surusiuoti i falus kietiakai.txt ir vargsiukai.txt\n";
}

void split_one_new(list<Student> kietiakai) {
    auto start = hrClock::now();
    
    list<Student> vargsiukai;
    
    auto it = kietiakai.begin();
    while(it != kietiakai.end()) {
        if ((*it).finalGrade() < 5) {
            vargsiukai.push_back((*it));
            it = kietiakai.erase(it);
        } else
            it++;
    }

    auto stop = hrClock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";

    auto start5 = hrClock::now();

    kietiakai.sort();
    vargsiukai.sort();

    auto stop5 = hrClock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop5 - start5);
    cout << "Studentu rusiavimas pagal vardus uztruko: " << duration5.count() * 1e-9 << " \n";
    
    start = hrClock::now();
    write_students("kietiakai.txt", kietiakai);
    kietiakai.clear();
    write_students("vargsiukai.txt", vargsiukai);
    vargsiukai.clear();
    stop = hrClock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Vargsiuku ir kietiaku rasymas i failus uztruko: " << duration.count() * 1e-9 << "s\n";
    // cout << "Studentai surusiuoti i falus kietiakai.txt ir vargsiukai.txt\n";
}

void input_data(list<Student>& arr) {
    int i = 0;
    Student tmp;
    while (true) {
        // input and verify name
        cout << "Vardas: ";
        string name;
        while(true) {
            cin >> name;
            if(!check_name(name)) {
                cout << "Ar " << name << " tikrai yra mokinio vardas? (y/n): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'y') {
                    tmp.setName(name);
                    break;
                } else {
                    cout << "Vardas: ";
                }
            } else {
                tmp.setName(name);
                break;
            }
        }

        // input and verify surname
        cout << "Pavarde: ";
        string surname;
        while(true) {
            cin >> surname;
            if(!check_name(surname)) {
                cout << "Ar " << surname << " tikrai yra mokinio pavarde? (y/n): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'y') {
                   tmp.setSurame(surname);
                    break;
                } else {
                    cout << "Pavarde: ";
                }
            } else {
                tmp.setSurame(surname);
                break;
            }
        }

        char random;
        cout << "Ar norite sugeneruoti atsitiktinius balus uz namu darbus ir egzamina? (y/n): ";
        cin >> random;
        if(random == 'y') {
            // intitialise random number generator
            srand(time(NULL));

            // generate exam result
            tmp.setExam(1 + rand() % 10);
            
            // ask how many grades to generate
            int n;
            cout << "Kiek norite sugeneruoti namu darbu pazymiu? ";
            while(!(cin >> n)) {
                cout << "Iveskite sveikaji skaiciu \n";
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            vector<int> grades;
            // generate array of random grades
            for(int j = 0; j < n; j++) {
                grades.push_back(1 + rand() % 10);
            }
            tmp.setGrades(grades);

        } else {
            // input and verify exam result
            string exam;
            while(true) {
                cout << "Egzamino rezultatas: ";
                cin >> exam;
                if(!is_grade(exam)) {
                    cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10\n";
                } else {
                    int number = stoi(exam);
                    if(number <= 0 || number > 10) {
                        cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10\n";
                    } else {
                        tmp.setExam(number);
                        break;
                    }
                }
            }

            // input homework grades
            vector<int> grades;
            input_grades(grades);
            tmp.setGrades(grades);
            arr.push_back(tmp);
        }
        i++;
        // add more students or stop
        char add_more;
        cout << "Ar norite prideti dar vieno mokinio duomenis? (y/n): ";
        cin >> add_more;
        if(add_more != 'y') {
            break;
        }
    }
}