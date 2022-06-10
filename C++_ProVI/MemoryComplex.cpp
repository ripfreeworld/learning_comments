#include <iostream>

using namespace std;

class Point {
	double x;
	double y;
public:
	Point(double x, double y) : x(x), y(y) {
		cout << "Point constructed" << endl;
	}
	~Point () {
		cout << "Point destucted" << endl;
	}
};

class Shape {
public:
	Shape() { cout << "Shape constructed" << endl; }
	~Shape() { cout << "Point constructed" << endl;}
	virtual double area() = 0;
};