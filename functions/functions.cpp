#include "../functions.hpp"

bool check_select3(const string s) {
    std::regex reg("[1-3]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool check_select2(const string s) {
    std::regex reg("[1-2]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool is_int(const string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}

bool is_grade(const string s) {
    std::regex reg("[0-9]");
    if(std::regex_match(s, reg) || s == "10")
        return true;
    else
        return false;
}

bool check_name(const string s) {
    std::regex reg("^[A-Z][a-z]*$");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}


void generate(int n, int nd) {
    std::mt19937 mt;
    mt.seed(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 10);

    std::ofstream file(std::to_string(n) + "st_" + std::to_string(nd) + "nd.txt");

    file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 0; i < nd; i++) {
        file << std::right << std::setw(5) << "ND" + std::to_string(i+1);
    }
    file << std::setw(6) << "Egz.\n";

    std::stringstream line;
    for (int i = 0; i < n; i++) {
        line << std::left << std::setw(20) << "Vardas" + std::to_string(i + 1) << std::setw(20) << "Pavarde" + std::to_string(i + 1);
        
        for (int i = 0; i <= nd; i++)
            line << std::right << std::setw(5) << dist(mt);

        if (i + 1 != n)
            line << "\n";

        if (i % 1000 == 0) {
            file << line.rdbuf();
            line.clear();
        }
    }

    file << line.rdbuf();
    file.close();
}

void input_grades(vector<int>& grades) {
    cout << "Iveskite namu darbu rezultatus, norint baigti, iveskite 0: " << "\n";
    string input;
    int number = 10;
    while(true) {
        // input and verify grade
        cout << grades.size() + 1 << " pazymys: ";
        if(cin >> input) {
            if(!is_grade(input)) {
                cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << "\n";
            } else {
                number = stoi(input);
                if(number < 0 || number > 10) {
                    cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << "\n";
                } else {
                    // if input is 0 break the loop 
                    // else add grade to an array
                    if(number == 0)
                        break;
                    grades.push_back(number);
                }
            }
        }
    };
}