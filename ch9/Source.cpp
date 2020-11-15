#include <list>
#include <deque>
#include <forward_list>
#include <vector>
#include <array>
#include <string>
#include <iostream>

using std::vector;
using std::list;
using std::forward_list;
using std::array;
using std::deque;
using std::string;

void ex() {
	//each container has 3 elements initializerd from given initializers
	list<string> authors = { "Milton", "Shakespeare", "Austen" };

	vector<const char*> articles = { "a", "an", "the" };

	list<string> list2(authors);	//ok type match, list2 is a copy of authors list

	//deque<string> authList(authors);	//error container types dont match
	//vector<string> words(articles);	//error element types dont match

	forward_list<string> words(articles.begin(), articles.end());	//converts const char* elements to string

	auto it= authors.begin()++;
	deque<string> authList(authors.begin(), it);	//copies up to but not including th element denoted by it.

	//list initialization container with 3 elements
	//vector<const char*> articles= { "a", "an", "the" };

	vector<int> ivec(10, -1);	//ten int elements, each initialized to -1

	list<string> svec(10, "hi!");	//ten strings; each element is "hi!"

	forward_list<int> ivec2(10);		// ten elements each initialized to 0
	deque<string> svec2(10);			// ten elements each an empty string

	array<int, 42>;		//type is array that holds 42 ints
	array<string, 10>;	//type is array that holds 10 strings
	array<int, 10>::size_type i;	//array type incudes element type and size
	//array<int>::size_type j;		//error array<int> is not a type

	array<int, 10> ia1;	//ten default initialized ints to 0
	array<int, 10> ia2 = { 0,1,2,3,4,5,6,7,8,9 };	//list initialization
	array<int, 10> ia3 = { 42 };	//ia[0] = 42 remaining elements are initialized to 0

	list<string> names;
	vector<const char*> oldstyle;

	//names = oldstyle;	//error container types dont match
	names.assign(oldstyle.cbegin(), oldstyle.cend());	//can convert from const char* to string

	//equivalent to slist1.clear();
	//followed by slist1.insert(slist1.begin(),10,"Hiya!");
	list<string> slist1(1);	//one element, which is the empty string
	slist1.assign(10, "Hiya!");	//ten elements; each one is a Hiya!

	vector<string> svec3(10);
	vector<string> svec4(24);
	swap(svec3, svec4);	//svec3 contains 24 elements, svec4 contains 10 elements.
	
	std::cout << svec3.size() << " " << svec4.size();

	list<int> lst23 = { 0,1,2,3,4,5,6,7,8,9 };
	list<int>::iterator it2 = lst23.begin();
	
	//while (it2 != lst23.end()) {
	//	if (*it2 % 2) {	//f element is odd 
	//		it2 = lst23.erase(it2);	//erase it 
	//		std::cout << *it2 << std::endl;
	//	}
	//	else {
	//		++it2;
	//	}
	//}

}

void even_odd() {
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> del_evens;
	list<int>	del_odds;

	//add nums into even and odds list
	for (int num : ia) {
		del_evens.push_back(num);
		del_odds.push_back(num);
	}

		auto num2 = del_evens.begin(); 

		while(num2 != del_evens.end()) {
			if (((*num2) % 2) == 0) {
				std::cout << *num2 << std::endl;
				num2=del_evens.erase(num2);
				}
			else {
				num2++;
			}
			}

		auto num = del_odds.begin(); 
		
		while (num != del_odds.end()) {

			//if odd delete num, and update num with return reference to one pass deleted current num
			if ( ((*num) % 2) != 0) {
				std::cout << *num << std::endl;
				num=del_odds.erase(num);
			}
			else {
				num++;
			}
		}

	std::cout << std::endl;
	for (auto num : del_odds) {
		std::cout << num << " " << std::endl;
	}
	std::cout <<std::endl;
	for (auto num : del_evens) {
		std::cout << num << " " << std::endl;
	}

}

void pluralize(size_t cnt, string& word)
{
	//adds s to the word
	if (cnt > 1) {
		word.push_back('s');	//same as word += 's'
	}
}
void ex_9_2_4() {
	vector<double> myd = { 2,3,4,5 };

	list<int> myc(myd.begin(), myd.end());
	vector<int> myv(myd.begin(), myd.end());

	for (int index = 0; index < 4; index++) {

		std::cout << myd[index] << " " << myv[index] << std::endl;
	}

	for (auto it = myc.begin(); it != myc.end(); ++it) {

		std::cout << *it << std::endl;
	}
}

void ex_9_2_5() {
	list<char*> point_to_char(10);
	vector<string> vec_str(point_to_char.begin(), point_to_char.end());

}

bool comp_vec(vector<int> a, vector<int> b) {
	return a == b;
}

bool comp_vec(vector<int> a, list<int> b) {

	int count = 0;
	vector<int> temp;

	//add all elements from list into temp vector
	for (auto it = b.begin(); it != b.end(); it++)
	{
		temp.push_back(*it);
	}

	//use built in vector comparison
	return (temp == a);
}

void ex9_3_1() {
	deque<string> str_holder;
	string word;
	bool choice = 1;
	int len = 0;
	while (len != 5) {

		getline(std::cin, word);

		str_holder.insert(str_holder.begin(), word);

		len++;
	}

	for (auto it = str_holder.begin(); it != str_holder.end(); it++) {
		std::cout << *it << std::endl;
	}

}

void ex9_3_1_list() {
	list<string> str_holder;
	string word;
	bool choice = 1;
	int len = 0;
	while (len != 5) {

		getline(std::cin, word);

		str_holder.insert(str_holder.begin(), word);

		len++;
	}

	for (auto it = str_holder.begin(); it != str_holder.end(); it++) {
		std::cout << *it << std::endl;
	}

}

void ex_9_3_1() {

	//ex 9.2
	list<int> nums = { 1,2,3,4,5,6,7,8,9 };

	deque<int> num_even, num_odd;

	for (auto it = nums.begin(); it != nums.end(); it++) {
		if ((*it) % 2 == 0) {
			num_even.push_back(*it);
		}
		else {
			num_odd.push_back(*it);
		}
	}
	//ex 9.21
	vector<int> c;
	//check that there are elements before dereferencing an iterator or calling front or back.
	if (!c.empty()){
	//val and val2 are copies of the value of the first element in c
	auto val = *c.begin(), val2 = c.front();
	//val3 and val4 are copies of the last element in c
	auto last = c.end();
	auto val3 = *(--last);	//can't decrement forward list iterators
	auto val4 = c.back();	//not supported by forward list.
}
}

void ex_9_3_2() {
	vector<int> c = { 1,2,3,4,5,6 }; //run time error when c is empty
	std::cout << c.at(0) << " " << c.front() << " " << *(c.begin()) << std::endl;
}

void ex_fwlist() {
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin(); //denotes element off the start of flst
	auto curr = flst.begin();	//denotes first element of flst
	while (curr != flst.end()) {
		//while there are still elements to process
		if (*curr % 2) {	//if element is odd
			curr = flst.erase_after(prev);//erase it and move curr to next element
		}
		else {
			prev = curr;	//move iterators to denote the next
			++curr;			//element and one before the next element
		}
	}
}

void ex_9_2_8(forward_list<string> flist, string word1, string word2) {

	auto cursor = flist.begin();
	bool flag = false;

	auto last_elem = flist.end();

	while ( cursor  != flist.end() ) {

		//does cursor match the word
		if ( (*cursor) == word1) {

			//insert new word after current word
			flist.insert_after(cursor, word2);

			//did we insert new word?
			flag = true;
		}
		++cursor;
	}

	std::cout << flag << std::endl;

	//insert to end of list, which is before the first element that is inserted.
	if (flag == false) {
		flist.insert_after(flist.before_begin(), word2);
	}

	//QC check the list
	for (auto num : flist) {
		std::cout << num << std::endl;
	}
}
void test_fw_lst(forward_list<string> flist) {

	auto cursor = flist.begin();
	std::cout << *(flist.begin()) << std::endl;
	flist.insert_after(cursor, "ccc");
	std::cout << *(++cursor) << std::endl;
	std::cout << *(flist.end()) << std::endl;
	//std::cout << &(flist+1) << std::endl;
}
void ex_9_3_4() {
	forward_list<int> flst = { 1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin(); //denotes element off the start of flst
	auto curr = flst.begin();	//denotes first element of flst
	while (curr != flst.end()) {
		//while there are still elements to process
		if ((*curr % 2) != 0) {	//if element is odd
			curr = flst.erase_after(prev);//erase it and move curr to next element
		}
		else {
			prev = curr;	//move iterators to denote the next
			++curr;			//element and one before the next element
		}
	}

	for (int num : flst) {
		std::cout << num << std::endl;
	}

	forward_list<string> words = { "aaa","bbb", "ccc", "ddd", "eee" };
	string word1 = "ccc";
	string word2 = "zzz";
	string word3 = "cat";
	ex_9_2_8(words,word2,word3);

	//test_fw_lst(words);
}

void ex_container_resize() {
	list<int> ilist(10, 42);	//ten ints each has value of 42
	ilist.resize(15);	//adds five elements of value 0 to the back of ilist
	ilist.resize(25, -1);	//add ten elements of value -1 to the back of the ilist
	ilist.resize(5);		//erases 20 elements from back of ilist
}

void ex_9_3_6() {
	//infinite loop
	vector<int> vi = { 1,2,3,4,5,6,7,8,9 };
	vector<int>::iterator iter = vi.begin();
	while (iter != vi.end()) {

		//if odd
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
		}
		std::cout << *iter << std::endl;
		++iter;
	}
	
	for (auto num : vi) {
		std::cout << num << std::endl;
	}
}
int main2() {
	//ex_9_2_4();

	//ex9_3_1_list();

	//ex_9_3_2();

	//even_odd();

	//ex();

	//ex_fwlist();
	ex_9_3_4();


	return 0;
}