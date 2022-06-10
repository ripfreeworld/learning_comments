#include <iostream>
using namespace std;

class Shape {
public:
	Shape() {
		cout << "Shape object created" << endl;
	}
	~Shape() {
		cout << "Shape object destroyed" << endl;
	}
};

class Circle : public Shape {
public:
	Circle() {
		cout << "Circle object created" << endl;
	}
	~Circle() {
		cout << "Circle object destroyed" << endl;
	}
};

int add_sub_mult (int x, int y, int* s, int* m)
{
	int res = x + y;
	return res;
}
