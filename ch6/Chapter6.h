#ifndef ch6_H
// we're here only if ch6_H has not yet been defined 
//file holds function declarations used in factMain.cpp
#define ch6_H
#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
size_t count_calls();

float abs_num(float num);

void call_fact();

int fact(int val);
int factorial(int val);
int ex_my_func(string c, int d);

void swap(int* num1, int* num2);
void swap_ref(int& num1, int& num2);

bool isShorter(const string& s1, const string& s2);

string::size_type find_char(const string& s, char c, string::size_type& occurs);

void reset(int& num);



//bool compare(matrix& cl, matrix& cl2);

//vector<int>::iterator change_val(int p, vector<int>::iterator);
#endif