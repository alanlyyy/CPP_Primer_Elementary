#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void _ex_cstrings() {
	char ca[] = { 'C' ,'+', '+' };	//not null terminated
	//cout << strlen(ca) << endl;	//disaster: ca ism't null terminated 
									//-- strlen is undefined, strlen will look through memory for \0 or null char.

	string s1 = "A string example";
	string s2 = "A different string";
	//if (s1 < s2) -- false: s2 is less than s1 s in string comes after d in different

	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	//if (ca1 < ca2) --undefined: compares two unrelated addresses, 
						// ca1 = &ca1[0] and ca2 = &ca2[0] both objects point to different objects therefore we have undefined condition

	//same effect as string comparison s1 < s2
	if (strcmp(ca1, ca2) < 0)
	{
		cout << strcmp(ca1, ca2) << endl;
	}

	//initialize largeStr as a concatenation of s1, a space and s2
	string largeStr = s1 + " " + s2;

	//strcpy(largeStr, ca1);
	//strcat(largeStr, " ");
	//strcat(largeStr, ca2);

	string s("Hello World");	//s holds hello world

	//char* str = s; //error cant initialize a char* from a string
	const char* are = s.c_str(); //convert string to a c style character string

	int int_arr[] = { 0,1,2,3,4,5 };

	//ivec has six elements; each is a copy of the corresponding element in int_arr
	vector<int> ivec(int_arr, int_arr + 6);

	for (int i : ivec) {
		cout << i << endl;
	}
	//copies three elements  int_arr[1], int_arr[2], int_arr[3]
	vector<int> subVec(int_arr + 1, int_arr + 4);

	for (int i : subVec) {
		cout << i << endl;
	}
}

void ex_3_5_5() {
	int arr[] = { 0,1,2,3,4,5 };
	int arrB[6];

	//c_vec is a copy of arr[] initialized as a vector 
	vector<int> c_vec(arr, arr + 6);

	//copy vector ints into array of ints

	//iterate through entire vector
	for (int num = 0; num < 6; ++num)
	{

		//take each element and append to arrB array
		*(arrB + num) = c_vec[num];


	}

	for (int index : arrB)
		cout << index << endl;
}

int main11(){
	//_ex_cstrings();

	ex_3_5_5();
	return 0;
	}