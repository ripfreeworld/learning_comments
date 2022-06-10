#include <iostream>
#include <string>
using namespace std;

/**

const Methode:
				-Syntax:
					return type name(parameterliste) const {}
				->Semantic:
					Die Methode verspricht die Attribute der Klasse nicht zu verändern!!!
					read-only access auf Attribute
				-Achtung:
						const ist nur für Methoden
				->nicht für Funktionen!!
const reference:
				Die Notwendigkeit bei Parameter
				const reference and rvalue 
				Lebensdauer von rvalue
				
call by reference, by adress und value- klar!

retrurn by adress:

return by reference:
					-Bitte kein Reference auf ein lokales Objekt (is lost)
					->Nutze return by Pointer (Free Store Objekt)
	

				
						
						
*/
class Point{
	private:
		double x;
		double y;
	public:
	
		explicit Point(double x = 0 , double y = 0) : x(x), y(y) {//constructor overloading!
			cout << "Point constructed " << endl;
		}	
		double getX() const { return x;}
		double getY()const {return y;}
		double get()const{
			double summe = this->x + this->y;
			summe += 2.0;
			return summe;
		}
		~Point(){cout << "Point destroyeded" << endl;}
		friend void print(Point p);
	
};
void print(const Point& p) {//Lieber call by reference
	cout << "(" << p.x<< " , " << p.y << ")" << endl;
}
void fct(const Point& p, double x, double y){//p lieber call by reference
	Point p1{x,y};
	print(p1);
	print(p);
	cout << "..." << endl;
	
}
class Date{
	private:
		int tag;
		int monat;
		int year;
	public:
		Date() : tag(1), monat(1), year(1970) {} //->parameterloser constructor
		Date(int tag) : tag(tag), monat(1), year(1970) {}//conversion constructor
		
};

void h(){
	cout << "..." << endl;
	const Point& p = Point{};//ops
	cout << "+++" << endl;
}//




class Person{
	private:
		string name;
		int weight;
	public:
		Person(const string& name, int weight) : name(name), weight(weight) {}
};

Point& returnReference(Point& p){
	//work with p (write and read - operations)
	return p;//Kein lokales Objekt
}
/**
	return: Array or Pointer of single Object
*/
Point* returnPointer(double x, double y){
	Point* p = new Point(x,y);
	//work with p (write and read - operations) 
	//delete p;
	return  p;//dangling Pointer
}

void caller(){
	Point* ptr = returnPointer(1,10);
	delete  ptr;
	//ptr->x = 21;//danger!
	ptr = nullptr;
	/**
	falls hier die Funktion weiter was macht
	*/
}
int main()
{
	h();
	/*
	Point a{1,3};//Stack a ->explicit constructor
	double b = 3.0, c = 4.0;
	print(a);
	fct(a, b,c);
	fct(Point{5,7}, 5.0, 9.0);//Wann wird das argument obj gelöscht
	*/
	/*
	 Point po {10,20};
	cout << po.getX() << endl;//ok
	
	 Point obj{7,8};//
	cout << obj.get() << endl;//
	

	
	Point* ptr1 = new Point();//x = 0, y = 0
	Point* ptr2 = new Point(2);//x = 2, y = 0; -> consversion constructor
	Point* ptr = new Point(1, 3);// x =, y = 3
	//copy constructor, der existiert implizit
	Point pc = obj;
	//Point pone = 3.0;//Point = int: type missmatch?
	Point pone = Point(3.0);
	//conversion constructor: One-Argument constructor, verwirend, sollte vermieden werden!
	//Man deklariert den "one-arg constructor" mittels key word : explicit
	print(pone);
	*/
	//string n = "chen";
	//int w= 65;
	Person("chen", 65);//string& name = "chen"
	return 0;
}