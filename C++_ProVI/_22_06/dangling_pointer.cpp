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
	public:
		double x;
		double y;
	public:
	
		explicit Point(double x = 0 , double y = 0) : x(x), y(y) {//constructor overloading!
			
		}	
		double getX() const { return x;}
		double getY()const {return y;}
		double get()const{
			double summe = this->x + this->y;
			summe += 2.0;
			return summe;
		}
		
		
	
};
void print(const Point& p) {//Lieber call by reference
	cout << "(" << p.x<< " , " << p.y << ")" << endl;
}

void fun(){
	Point* p = new Point(1,3);
	cout <<"p:x = " << p->getX() << endl;
	delete p;
	//Ab hier ist p ein Dangling Pointer! -> error prone!
	p = nullptr;//Jetzt ist p nicht mehr danglich pointer. 
	Point* q = new Point(10,20);//vielleicht q bekommt die gleiche Ort im speicher wie P
	//weil das frei gegeben würde!
	
	//if(p != nullptr)
		if(p){
			cout << "p: x = " << p->x << endl;
			p->x = 100;//mögliche Data corruption, 
			
			cout << "p: x = " << p->x << endl;
		}
		cout << "q:x = " << q->x << endl;
	
	
	
};

int main()
{

	fun();
	int i = 21;
	const int* const ptr = &i;
	int j = 23;
	ptr = &j;//error
	*ptr = 41;//error
	
	return 0;
}