#include "../functions.hpp"

void split_two_new(deque<Student> arr) {
    auto start = hrClock::now();
    // calculate final grade and split students
    deque<Student> vargsiukai, kietiakai;
    for(auto student:arr) {
        if (student.finalGrade() < 5)
            vargsiukai.push_back(student);
        else
            kietiakai.push_back(student);
    }
    arr.clear();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";

    auto start5 = std::chrono::high_resolution_clock::now();

    std::sort(kietiakai.begin(), kietiakai.end());
    std::sort(vargsiukai.begin(), vargsiukai.end());

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

void split_one_new(deque<Student> kietiakai) {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::stable_partition(kietiakai.begin(), kietiakai.end(), [](Student& stud){ return stud.finalGrade() < 5; });
    auto it = std::find_if(kietiakai.begin(), kietiakai.end(), [](Student& stud){ return stud.finalGrade() > 5; });
    deque<Student> vargsiukai(kietiakai.begin(), it);
    
    it = kietiakai.begin();
    while(it != kietiakai.end()) {
        if ((*it).finalGrade() < 5) {
            std::iter_swap(it, kietiakai.end() - 1);
            kietiakai.pop_back();
        } else
            it++;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";

    auto start5 = std::chrono::high_resolution_clock::now();

    std::sort(kietiakai.begin(), kietiakai.end());
    std::sort(vargsiukai.begin(), vargsiukai.end());

    auto stop5 = std::chrono::high_resolution_clock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop5 - start5);
    cout << "Studentu rusiavimas pagal vardus uztruko: " << duration5.count() * 1e-9 << " \n";
    
    start = std::chrono::high_resolution_clock::now();
    write_students("kietiakai.txt", kietiakai);
    kietiakai.clear();
    write_students("vargsiukai.txt", vargsiukai);
    vargsiukai.clear();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Vargsiuku ir kietiaku rasymas i failus uztruko: " << duration.count() * 1e-9 << "s\n";
    // cout << "Studentai surusiuoti i falus kietiakai.txt ir vargsiukai.txt\n";
}

void input_data(deque<Student>& arr) {
    int i = 0;
    while (true) {
        // add new element to an array
        arr.push_back(Student());

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
                    arr[i].setName(name);
                    break;
                } else {
                    cout << "Vardas: ";
                }
            } else {
                arr[i].setName(name);
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
                    arr[i].setSurame(surname);
                    break;
                } else {
                    cout << "Pavarde: ";
                }
            } else {
                arr[i].setSurame(surname);
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
            arr[i].setExam(1 + rand() % 10);
            
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
            arr[i].setGrades(grades);

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
                        arr[i].setExam(number);
                        break;
                    }
                }
            }

            // input homework grades
            vector<int> grades;
            input_grades(grades);
            arr[i].setGrades(grades);
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