#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int text_size() {
	return 5;
}

void ex_3_5_1() {
	
	//ex_3.27
	unsigned buf_size = 1024;

	//int ia[buf_size];	//buf_size must be a const value to be valid

	int ia[4 * 7 - 14];

	//int ia[text_size()];	//text_size must be type const value to be valid.

	//char st[11] = "fundamental";	//cant initalize a string of 12 characters in an array of 11 characters + invisible end line char.

	//ex3.28
	string sa[10];	// 10 elements of empty string
	int ib[10];		// 10 elements of 0
}

void arrays_ex() {
	unsigned scores[11] = {};	//11 buckets, all value initiated to 0
	unsigned grade;

	while (cin >> grade) {
		if (grade <= 100)
			++scores[grade / 10];	//increment counter for current cluster
	}
}

void ex_3_5_2() {

	//ex3.31
	unsigned const size_ = 10;
	unsigned nums[size_];
	unsigned nums2[size_];
	vector<unsigned> nums_vec(10);

	//for each position from 1-10 add that position to corresponding index of array.
	for (unsigned i = 0; i < size_; ++i)
		nums[i] = i;

	//ex3.32
	// copy array into another array
	for (auto i : nums)
	{
		nums2[i] = i;
		nums_vec[i] = i;
	}

	for (auto i : nums_vec)
	{
		cout << i << " " << nums[i] << " " << nums2[i] << " "<< endl;
	}
}
void ex_arr_1() {

	unsigned cnt = 42;			// not a constant expression
	constexpr unsigned sz = 42; //constant expression


	int arr[10];				//array of 10 ints

	int* parr[sz];				// array of 42 pointers to int
	//string bad[cnt];			//error : cnt is not a constant expression

	//string strs[get_size()];	//ok if get_size is constexpr, error otherwise

	//sz = 3;

	int ia1[sz] = { 0,1,2 };	//array of three ints with values 0,1,2
	int a2[] = { 0,1,2 };		//array of dimension 3
	int a3[5] = { 0,1,2 };		// equivalent to a3[] = {0,1,2,0,0}

	string a4[3] = { "hi" , "bye" };	//a4[] = {"hi", "bye", ""}
	//int a5[2] = { 0,1,2 };			//error: too many initializers

	char aL[] = { 'C', '+', '+' };		//list initialization, no null (Dim 3)
	char aM[] = { 'C', '+', '+', '\0' };	//list initialization, explicit null (Dim 4)
	char aN[] = "C++";						//null terminator added automatically (Dim 4)
	//const char aP[6] = "Daniel";		//error - no space for the null

	int b[] = { 0,1,2 };	//array of 3 ints
	//int c[] = b;			//error cannot initializae one array with another
	//c = b;					//error: cannot assign one array to another

	int* ptrs[10];		//ptrs is an array of ten pointers to int
	//int& refs[10] = b; //error no arrays of references
	int(*Parray)[10] = &arr;	//Parray points to an array of 10 ints, the value of (Parray is arr)
	int(&arrRef)[10] = arr;		//arrRef is bound to an array, arr, of ten ints

	int* (&arry)[10] = ptrs;		//arry is bound to an array of ten pointers

	string nums[] = { "one", "two", "three" };	//array of strings
	string* p = &nums[0]; //p points to the first element in nums
	cout << " address: " << p << " dereferenced value " << *p << endl;

	string* p2 = nums;	//equivalent to *p2 = &nums[0]

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 }; //ia is an array of 10 ints
	auto ia2(ia); //ia2 is an int* that points to the first element in ia
	// ia2 = 42; //ia2 is a pointer ,we cant assign an int to a pointer
	*ia2 = 42;	//dereference ia2 which points to ia[0], change the value to 42
	auto ia5(&ia[0]);	//ia5 is an int pointer, which points to ia[0]

	decltype(ia) ia3 = { 0,1,2,3,4,5,6,7,8,9 };	//ia3 is an array of ten ints
	//ia3 = p;	//error: can't assign an int* to an array
	ia3[4] = 77;		//assigns the value of element 4 to 77.

	int arrB[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* pb = arrB;	//p points to &arrB[0]
	++pb;	//pb now points to &arrB[1]

	int* e = &arrB[10];	//e is a pointer that points past the last element in array

	//iterate through entire array using pointers 
	for (int* b = arrB; b != e; ++b)
		cout << *b << endl;


	// in new libbrary new functions begin and end are included.
	int ic[] = { 0,1,2,3,4,5,6,7,8,9 };	//ic is array of ten ints
	//int* beg = begin(ic);	//pointer to the first element in ic
	//int* last = end(ic);	//pointer to one past the last element in ic


	//adding pointers
	constexpr size_t sC = 5;
	int arrC[sC] = { 1,2,3,4,5 };

	int* ip10 = arrC;	//equivalent to int *ip =&arrC[0], points to first element
	int* ip20 = ip10 + 4; //equivalent to ip2 points to arr[4], the last element in arrC

	int* ip11 = arrC + sz; //use caution -- do not dereference, ip11 undefined value, because ip11 points to &arrC[5] or one past size of arrC
	//int* ip21 = arrC + 10; // error arr has only 5 elements; ip21 has undefined value

	cout << *ip10 << " " << *ip20 << endl;

	//subtracting pointers
	auto n = &arrC[5] - &arrC[0];	// n is 5, the number of elemens in arrC 

	cout << "Distance between 2 pointers: " << n << " " << endl;

	int* de = arrC, * ed = arrC + sC;

	while (de < ed) {

		//print the dereference value of the pointer
		cout << *de << endl;

		//update the iterator to move to next element
		++de;
	}

	//undefined p and e unrelated types; comparison is meaningless
	int io = 0, sD = 42;
	int* start_ = &io, * end_ = &sD;
	//while (start_ < end_)
		//do something
		//cout << " ";

	int idd[] = { 0,2,4,6,8 };
	int last = *(idd + 4);	//last is the dereferenced value of pointer pointing to &idd[4], value is 8
	cout << last << endl;

	last = *idd + 4;		//last which points to &idd[0] contains a value = 0, 0 +4 = 4

	int ipp = idd[2];	//ipp is converted to a pointer to the 1st element,0th position in idd
						//idd[2] fetches the element to which (idd +2) points

	int *ipp2 = idd;	//ipp2 points to &idd[0], the first element in the array idd

	ipp = *(ipp2 + 2);	//equivalent to ipp = idd[2]
						//ipp2+2 points to &idd[2], the 3rd element in the array idd, we dereference &idd[2] to get the value of 4

	cout << "ipp: " << ipp << " ipp2: " << *ipp2 << " last:  " << last << endl;

	int* k = &idd[2];	//k points to the element indexed by 2,
	int j = k[1];		// k[1] is equivalent to *(k+1), or idd[3]
	int m = k[-2];		//k[-2] is the same element as idd[0] 
	
	cout << "j: " << j << " k: " << *k << " m: " << m << endl;

}

void ex_3_5_3() {
	//ex 3_35
	int idd[] = { 0,2,4,6,8 };
	int* first = idd, * last = &idd[5];	//first = &idd[0], last = &idd[5] or one after the last element in idd

	while (first < last)
	{
		//change each value of each element to 0 in idd
		*first = 0;

		//update pointer to next element
		++first;
	}

	//reset the pointer to first element
	first = idd;
	while (first < last)
	{
		//change each value of each element to 0 in idd
		cout << *first << endl;
		++first;
	}
	
	int ipp[] = { 0,2,4,6,8 };
	int icc[] = { 0,2,4,6,8 };

	//get the size of the array
	cout << sizeof(ipp) / sizeof(ipp[0]);
	
	int* first_arr1 = ipp;
	int* last_arr1 = &ipp[sizeof(ipp) / sizeof(ipp[0])];

	int* first_arr2 = icc;
	int* last_arr2 = &icc[sizeof(icc) / sizeof(icc[0])];

	int flag = 1;
	//iterate over array until last element is reached
	while ((first_arr1 < last_arr1) && (first_arr2 < last_arr2))
	{
		//if both elements in the array for the same index is equal move onto the next element
		if (*first_arr1 == *first_arr2) {

			cout << *first_arr1 << " " << first_arr2 << endl;
			++first_arr1;
			++first_arr2;
		}
		else
		{
			//if both elements are not equal break out of loop set flag to 0
			flag = 0;
			break;
		}

		//for comparing different size arrays
		//if the current element is equal to the last element for any array
			//compare the last element of one array to the last element to the other array
			//if the last element of one array is not equal to the current element of other array
				//set flag to 0
		if ((first_arr1 == last_arr1) || (first_arr2 == last_arr2))
		{
			if ((*(first_arr1 - 1) != *(last_arr2 - 1)) ||
				(*(first_arr2 - 1) != *(last_arr1 - 1)))
			{
				flag = 0;
			}
		}
	}
	cout <<"Are arrays equal? " <<  flag << endl;



}
int main10() {

	//ex_3_5_2();
	//ex_arr_1();
	ex_3_5_3();
	return 0;
}