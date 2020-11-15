#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void pt1() {
	//int ia[3][4]; // array of size 3; each element is an array of ints of size 4

	//arrays of size 10; each element is a 20 element array whose elements are arrays of 30 ints
	int arr[10][20][30] = { 0 }; //all elements initialized to 0

						
	int ia[3][4] = {			//three elements; each element is an array of size 4
					{0,1,2,3},	//initializers for the row indexed by 0
					{4,5,6,7},	//initializers for the row indexed by 1
					{8,9,10,11}	//initializers for the row indexed by 2
				};
	//row three is value initialized to {0,0,0,0}

	//equivalent initialization without nested braces for each row
	int ib[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	int ic[3][4] = { {0 }, {4}, {8} };	//explicitly initialize only element 0 in each row

	int ix[3][4] = { 0,3, 6, 9 };	//explicitly initialize row 0; the remaining elements in all other rows are value initialized to 0

	//ia[2][3] = arr[0][0][0];	//assigns the first element of arr to the last element in the last row of ia

	int(&row)[4] = ia[1];	//row is an (int array) reference of *size 4* bound to the row indexed by 1 of ia. 



	//processing multidim arrays using for loop
	constexpr size_t rowCnt = 3, colCnt = 4;

	int id[rowCnt][colCnt];	//12 uninitializerd elements

	//for each row 
	for (size_t i = 0; i != rowCnt; ++i)
	{
		//for each column within the row
		for (size_t j = 0; j != colCnt; ++j) {
			id[i][j] = i * colCnt + j;
		}
	}

	//using range for in multi dim arrays
	size_t cnt = 0;
	for (auto& row : id) {			//for each element in the outer array, row starts with &ia[0]
		for (auto& col : row) {		//for every element in the inner array col starts with &ia[0][0]
			col = cnt;				//give the element the next value
			++cnt;					//increment cnt
		}
	}

	for (const auto& row : id)		//for every element in the outer array
	{
		for (auto col : row)		//for every element in the inner array
		{
			cout << col << endl;
		}
	}

	int iv[3][4];		//array of size 3; each element is an array of ints of size 4
	int	(*p)[4] = iv;	//p points to an array of 4 ints
	p = &iv[2];			//p now points to the last row in ia, which is an array of size 4


	//print the value of each element in ia, with each inner array on its own line
	//b points to an arry of four ints (row) b = &ia[0]
	for (auto b = ia; b != ia + 3; ++b)
	{
		//q points to the first element of an array of four ints; that is, q points to an int (column)
		//q = &ia[0][0], pointer to an array gives you the first index of the array
		for (auto q = *b; q != *b + 4; ++q)
		{
			cout << *q << ' ';
		}
	}

	//p points to the first array in ia
	for (auto h = &ia[0]; h != &ia[3]; ++h)
	{
		cout << endl;
		//h points to the first element in an inner array
		for (auto j = *h; j != *h + 4; ++j)
		{
			cout << *j << " ";	//prints the dereferenced value to which j points to.
		}
		cout << endl;
	}

	using int_array = int[4];	// new style type alias declaration

	typedef int int_array[4];	// equivalent typedef declaration

	//print the value of each element in ia, with each inner array on its own line
	for (int_array* k = ia; k != ia + 3; ++k)	//p is a pointer to each row  p = &ia[0]
	{
		for (int* q = *k; q != *k + 4; ++q)		//q = &ia[0][0]
		{
			cout << *q << ' ';
		}
		cout << endl;
	}
}
void ex_3_6() {
	int ia[3][4] = {			//three elements; each element is an array of size 4
				{0,1,2,3},	//initializers for the row indexed by 0
				{4,5,6,7},	//initializers for the row indexed by 1
				{8,9,10,11}	//initializers for the row indexed by 2
	};

	//range for iteration
	for (int (&row)[4] : ia) {	//row is an int array of size 4 reference to &ia[0]
		for (int (&col) : row) {	//col is an int reference to &ia[0][0]
			cout << col << ' ';	
		}
		cout << endl; 
	}

	//array subscript iteration
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << ia[i][j] << ' ';
		}
		cout << endl;
	}

	//pointer version 
	for (int(*row)[4] = ia; row != ia + 3; ++row)	//row is an int array pointer of size 4, which starts at &ia[0]
	{
		for (int* col = *row; col != *row + 4; ++col) //col is an int pointer which points to each element of row, starting at &ia[0][0]
		{
			cout << *col << ' ';//derefence value of col and print it.
		}
		cout << endl;
	}
}
int main() {
	//pt1();
	ex_3_6();
	return 0;
}