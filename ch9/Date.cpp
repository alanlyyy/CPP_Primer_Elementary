#include <string>
#include <iostream>
#include <vector>

struct Date {

	Date(std::string s) {

	//format 1: January 1 1900 , currently handles format 1
	//format 2: 1/1/1900
	//format 3: Jan 1, 1900

	int start = 0;
	int current = start;

	std::vector<std::string> months_abrv = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct" ,"Nov", "Dec" };

	int date_tracker = 0;

	while (current != s.size()){

		if (isspace(s[current])) {
			
			//current - start is length of substring between white space
			std::string substring =  s.substr(start, current-start);

			std::cout << s << " "<< substring << " " << start << " " << current << std::endl;

			//must be a integer if size of substring > 2
			if (substring.size() > 2) {

				for (auto m = 0; m != months_abrv.size(); m++) {

					if (substring.find(months_abrv[m]) != std::string::npos) {
						month = m + 1;
					}
				}
			}
			else {
				day = stoi(s.substr(start, current));
			}

			//start marks the place of the last white space
			start = current+1;
		}

		if (s[current] == '/' || s[current] == '-') {
			//for format month/day/year and month-day-year

			++date_tracker;//trackes the number of '/' and '-' marks, 1 == month, 2== day

			//current - start is length of substring between white space
			std::string substring = s.substr(start, current - start);

			//must be a integer if size of substring > 2

			if (date_tracker == 1) {
				if (substring.size() > 2) {

					for (auto m = 0; m != months_abrv.size(); m++) {

						if (substring.find(months_abrv[m]) != std::string::npos) {
							month = m + 1;
						}
					}
				}
				else {
					month = stoi(substring);
				}
			}
			else{
				day = stoi(substring);
			}

			//start marks the place of the last white space
			start = current+1;

		}

		current++;
	}

	year = stoi(s.substr(start, current));

	}

	unsigned year;
	unsigned month;
	unsigned day;
};

int main() {
	Date D1 = Date("Nov 21 2020");
	Date D2 = Date("11/21/2020");
	Date D3 = Date("11-21-2020");
	Date D4 = Date("November 21 2020");
	Date D5 = Date("Nov-21-2020");


	std::cout << D1.month << " " << D1.day << " " << D1.year << std::endl;
	std::cout << D2.month << " " << D2.day << " " << D2.year << std::endl;
	std::cout << D3.month << " " << D3.day << " " << D3.year << std::endl;
	std::cout << D4.month << " " << D4.day << " " << D4.year << std::endl;
	std::cout << D5.month << " " << D5.day << " " << D5.year << std::endl;
	return 0;
}