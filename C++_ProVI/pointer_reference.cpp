#include <iostream>
using namespace std;

class Point {
private:
	double x;
	double y;
public:
	Point(double x = 0, double y = 0) : x(x), y(y) {
		cout << "Point created" << endl;

	}
	~Point(){
		cout << "Point destroyed" << endl;
	}
	// const method
	// die Methode verspricht die Attribute (i.e. "x", "y") der Klasse nicht zu verändern!
	// Nutzbarkeit: const object and non-const object both can use 
	double getX() const {
		return x;
	}
	double getY() const {
		return y;
	}
};

void print (Point p) {
	cout << "(" << p.getX() << " , " << p.getY() << ")" << endl;
}

void fct(Point p, double x, double y) {
	Point p1{x, y};
	print(p1);
	cout << "..." << endl;
}

int main() {
	Point a{1, 3};
	double b = 3.0, c = 4.0;
	print(a);
	fct(a, b, c);
	fct(Point{5, 7}, 5.0, 9.0);
	return 0;
}