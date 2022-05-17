#pragma once

#include "main.hpp"

template <typename container>
void read_data(container& arr, string filename) {
    try {
        auto start = std::chrono::high_resolution_clock::now();
        std::stringstream buffer;
        // open file
        std::ifstream file(filename);
        if (!file) {
            throw(1);
        }
        buffer << file.rdbuf();

        file.close();
        auto stop = hrClock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "Failo skaitymas uztruko: " << duration.count() * 1e-9 << "s\n";

        start = hrClock::now();
        int lines_count = 0;
        string line;
        while (getline(buffer, line)) {
            lines_count++;
        }

        if (lines_count == 0) {
            throw(3);
        }

        buffer.clear();
        buffer.seekg(0, std::ios::beg);

        // read file header
        deque<string> header;
        while (buffer.peek() != '\n') {
            string data;
            buffer >> data;
            header.push_back(data);
        }

        // get homework count
        int homework_count = header.size() - 3;
        header.clear();

        // read data
        while (!buffer.eof()) {
            int i = 0, exam;
            string name, surname;
            vector<int> grades;
            buffer >> name >> surname;
            for (int j = 0; j < homework_count; j++) {
                grades.push_back(int());
                buffer >> grades[j];
            }
            buffer >> exam;
            arr.push_back(Student(name, surname, grades, exam));
            if (i > lines_count) {
                throw(2);
            }
            i++;
        }
        stop = hrClock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "Duomenu paruosimas programos naudojimui uztruko: " << duration.count() * 1e-9 << "s\n";
    }
    catch (int err) {
        switch (err) {
        case 1:
            cout << "Failas neegzistuoja\n";
            break;
        case 2:
            arr.clear();
            cout << "Faile yra klaida\n";
            break;
        case 3:
            cout << "Failas yra tuscias\n";
            break;
        }
    }
}

template <typename container>
void print(const container& arr, const int s) {
    // print header line
    cout << "\n";
    cout << std::left << std::setw(15) << "Vardas" 
        << std::left << std::setw(15) << " Pavarde";
    // print based on s value
    switch(s) {
        case 1:
            cout << std::left << std::setw(15) << " Galutinis (vid.)\n";
            cout << std::string(45, '-') << "\n";
            break;
        case 2:
            cout << std::left <<std:: setw(15) << " Galutinis (med.)\n";
            cout << std::string(45, '-') << "\n";
            break;
        case 3:
            cout << std::left << std::setw(15) << " Galutinis (vid.)" << std::left << std::setw(15) << " Galutinis (med.)\n";
            cout << std::string(60, '-') << "\n";
            break;
    }
    // print all elements of an array
    for(auto i:arr) {
        cout << std::left << std::setw(15) << i.name() << " " 
            << std::left << std::setw(15) << i.surname() << " ";
            // calculate final grade using average or median based on s value
            switch(s) {
                case 1:
                    cout << std::left << std::setw(20) << std::setprecision(3) << i.finalGrade() << "\n";
                    break;
                case 2:
                    cout << std::left << std::setw(20) << std::setprecision(3) << i.finalGrade(median) << "\n";
                    break;
                case 3:
                    cout << std::left << std::setw(20) << std::setprecision(3) << i.finalGrade() 
                        << std::left << std::setw(20) << std::setprecision(3) << i.finalGrade(median) << "\n";
                    break;
            }
    }
}

template <typename container>
void write_students(const string filename, const container& arr) {
    // write student name, surname and final grade to stringstream
    std::stringstream line;
    for(auto student:arr)
        line << student << '\n';
    
    std::ofstream file (filename);

    // write header line
    file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis balas" << std::endl;

    // write stringstream to file
    file << line.rdbuf();

    file.close();
}