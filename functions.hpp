#pragma once

#include "main.hpp"
#include "template_functions.hpp"

bool check_select3(const string);
bool check_select2(const string);
bool is_int(const string);
bool is_grade(const string);
bool check_name(const string);
bool compareBySurname(const Student&, const Student&);

void input_grades(vector<int>&);

void input_data(vector<Student>&);
void input_data(list<Student>&);
void input_data(deque<Student>&);

void generate_data();
void generate(int, int);

void vector_data_input();
void list_data_input();
void deque_data_input();


void vector_student_sorting();
void list_student_sorting();
void deque_student_sorting();

void split_two_new(vector<Student>);
void split_one_new(vector<Student>);

void split_two_new(list<Student>);
void split_one_new(list<Student>);

void split_two_new(deque<Student>);
void split_one_new(deque<Student>);