
#include <iostream>
#include <cmath>
using namespace std;
class Point{
	private:
		double x;
		double y;
	public:
		Point(double x, double y) : x(x), y(y){cout << "Point constructed" << endl;}
		~Point(){cout << "Point destructed" << endl;}
	//definiere eine Methode, die den Abstand zwischen zwei Punkten berechnet zurückgibt
	double distance(const Point& other){
		//other.x = 21;cheating! Data corruption
		return sqrt(pow(this->x - other.getX(), 2) + pow(this->y -other.getY(), 2));
	}
	double getX() const{
		return x;
	}
	double getY() const{
		return y;
	}
};
class Shape{
	public:
		Shape() {cout << "Shape constructed" << endl;}
		virtual ~Shape() {cout << "Shape destructed" << endl;}
		 virtual double area()  = 0;
};

class Circle : public Shape{
	private:
		 Point center;
		 double radius;
	public:
		Circle(double x, double y, double radius) :Shape{}, center(x,y), radius(radius)
		{
			cout << "circle constructed" << endl;
		}
		~Circle() 
		{
			cout << "circle destructed" << endl;
		}
		 double area() {return 3.14 * radius * radius;}
};
class Rectangle : public Shape{
	private:
		double width;
		double length;
	public:
			Rectangle(double width, double length) : width(width), length(length)
			{
			}
		double area() override { return length * width;}
				
};

class RightAngledTriangle : public Shape{
	private:
		double a;
		double b;
	public:
		RightAngledTriangle(double a, double b) : a(a), b(b) {}
		double area() override { return a * b * .5;}
};

double calcTotalArea(Shape** s, int n)
{
	double res = 0;
	while (n > 0)
	{
		res += s[n]->area();
		n--;
	}
	return res;
}


//Aufgabe: Definiere eine Funktion, die den Flächeninhalt eines beliebigen Shape-Objekt 
//berechnet und zurückgibt
double cf(Shape* s){
	return s->area();
}
int main()
{
	Point p{1,7};
	Point a{3,4};
	//Point b{10,20};
	double d = p.distance(a);//Point& other = a, no copy, it is just an alias!!
	cout << "d = " << d << endl;
	
	Circle c{1,2,3};
	Rectangle r{3,4};
	RightAngledTriangle t{3,4};
	cout << cf(&c) << endl;//Shape& s = c; Polymorphie
	cout << cf(&r) << endl;
	
	Shape** shapes = new Shape*[3];
	shapes[0] = &c;
	shapes[1] = &r;
	shapes[2] = new RightAngledTriangle{3,4};

	//test Aufruf der Methode calcTotalArea:
	calcTotalArea(shapes, 3);

	delete shapes[2];
	delete [] shapes;
}