#include<iostream>
using namespace std;

void print_string (ostream& os, const string& s){
	os << s << endl;
	os << "const reference" << endl;
}

void print_string (ostream& os, string& s){
	os << s << endl;
	os << "copied" << endl;
}

/*
// this kind of overloading not allowed
// error: call to 'print_string' is ambiguous
void print_string (ostream& os, string s){
	os << s << endl;
	os << "copied" << endl;
}
*/

int const_func (int n){
	return n;
}

/*
// error: redefinition of 'const_func'. 
// "top-level const has no effect on the objects that can be passed to the function"
// that means it accepts exactly all the same kinds of objects
int const_func (const int n){
	return n;
}
*/

int main(int argc, char const *argv[])
{
	double dVal = 0.0;
	// int& ri = dVal; // error: non-const lvalue reference to type 'int' ''
	// const int i = dVal;
	// const int& ri = i;
	const int& ri = dVal;
	// similarly, string and "const char*" also has this problem
	// cannot use "string& rs = "some text"; "
	const string& rs = "some text"; // const char*

	print_string(cout, "text to show");
 
	return 0;
}
