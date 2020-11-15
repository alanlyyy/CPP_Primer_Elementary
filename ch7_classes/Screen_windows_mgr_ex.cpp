#include <iostream>
#include <string>
#include <vector>


class Screen {
	
	//window_mgr members can access the private parts of class Screen
	friend class Window_mgr;
	
	//if instead of making entire Window_mgr class a friend, we can make a member function of Window_mgr a friend.
	//friend void Window_mgr::clear(ScreenIndex);
	public:

		typedef std::string::size_type pos;
		//alternative way to declare type member using type alias
		//using pos = std::string::size_type;

		Screen() = default;	//needed because Screen has another constructor

		//cursor initialized to 0 by its in class initializer
		Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}


		//Overloading the get method:
		//get the character at the cursor
		char get() const {
			return contents[cursor]; //implicitly inline
		}

		inline char get(pos ht, pos wd) const;	//explicitly inline

		Screen& move(pos r, pos c);	//can be made inline later.
		Screen move2(pos r, pos c);	//can be made inline later.

		void some_member() const;


		//overloaded display with different set of paramenters
		Screen& set(char);
		Screen& set(pos, pos, char);

		Screen set2(char);
		Screen set2(pos, pos, char);

		//display overloaded on whether the object is of type const
		Screen& display(std::ostream& os) { 
			do_display(os); 
			return *this; 
		}
		
		const Screen &display(std::ostream &os) const 
		{
			do_display(os); 
			return *this;
		}

		//display overloaded on whether the object is of type const
		Screen display2(std::ostream& os) {
			do_display(os);
			return *this;
		}

		const Screen display2(std::ostream& os) const
		{
			do_display(os);
			return *this;
		}

		//function declared for exercise 7.33
		pos size() const;

		//bkground refers to the static member declared later in the class definition
		Screen& clear(char = bkground);


	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;

		mutable size_t access_ctr;	//may change even in a const object

		static const char bkground;

		//functions to do the work of displaying a Screen.
		void do_display(std::ostream& os) const {
			os << contents;
		}
};

inline Screen& Screen::set(char c) {
	contents[cursor] = c;	//set the new value at the current cursor location
	return *this;			//return this object as an lvalue
}

inline Screen& Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;	//set specified location to given value

	return *this; // return this object as an lvalue
}
inline Screen Screen::set2(char c) {
	contents[cursor] = c;	//set the new value at the current cursor location
	return *this;			//return this object as an lvalue
}

inline Screen Screen::set2(pos r, pos col, char ch) {
	contents[r * width + col] = ch;	//set specified location to given value

	return *this; // return this object as an lvalue
}
//specify inline on definition outside class explicitly
inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;	//compute row location
	cursor = row + c;		//move cursor to the column within that row
	return *this;			//return this object as an lvalue
}
//specify inline on definition outside class explicitly
inline Screen Screen::move2(pos r, pos c) {
	pos row = r * width;	//compute row location
	cursor = row + c;		//move cursor to the column within that row
	return *this;			//return this object as an lvalue
}
//declared as inline in the class
char Screen::get(pos r, pos c) const {
	
	pos row = r * width;	//compute row location
	return contents[row + c];	//return character at the given column
}

void Screen::some_member() const
{
	++access_ctr;	//keep count of the calls to any member function
}

//function defined for exercise 7.4
Screen::pos Screen::size() const {
	return height * width;
}

class Window_mgr {

public:
	//location ID for each screen on the window
	using ScreenIndex = std::vector<Screen>::size_type;

	//reset the screen at the given position to all blanks
	void clear(ScreenIndex); //equivalent to  clear(std::vector<Screen>::size_type)

	std::vector<Screen>& get_window() {
		return screens;
	}

	//add a screen to the window and return its index
	ScreenIndex addScreen(const Screen&);

private:
	//Screens this window_mgr is tracking

	//by default, a window_mgr has one standard sized blank screen
	std::vector<Screen> screens{ Screen(24,80,' ') };
};

//return type, ScreenIndex, is seen before we're in the scope of Window_mgr
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s) {
	//add a screen to the vector
	screens.push_back(s);
	return screens.size() - 1;
}

void Window_mgr::clear(ScreenIndex i) {
	//s is a reference to the screen we want to clear
	Screen& s = screens[i];

	//reset the contents of the Screen to all blanks 
	s.contents = std::string(s.height * s.width, ' ');
}
void ex_7_3_2() {
	Screen myScreen(5, 5, 'X');

	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << "\n";
	myScreen.display(std::cout);
	std::cout << "\n";

	//7.29
	Screen myScreen2(5, 5, 'X');

	myScreen2.move2(4, 0).set2('#').display2(std::cout);
	std::cout << "\n";
	myScreen2.display2(std::cout);
	std::cout << "\n";

	Window_mgr program = Window_mgr();

	//add screens to the window as a copy
	program.get_window().push_back(myScreen);
	program.get_window().push_back(myScreen2);

	//clear the screen
	program.clear(1);
	program.clear(2);

	//displaay the screen after clearing
	program.get_window()[1].display(std::cout);
	std::cout << std::endl;
	program.get_window()[2].display(std::cout);
	std::cout << std::endl;

	std::cout << myScreen.size() << " " << myScreen2.size();
}

int main5() {
	ex_7_3_2();
	return 0;
}