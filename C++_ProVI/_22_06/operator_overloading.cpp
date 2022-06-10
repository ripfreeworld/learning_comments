#include <iostream>
using namespace std;

/**

Overloading:
			-function, constructor, methode, operator
			
operator overloading:
					-mindestens eine der Operanden muss ein user-defined data type sein!
					-Anzahl der Parameter änder sich nicht
					-Precedence ändert sich nicht
					-man kann keine neue Operatoren einführen
					-Es gibt Ausnahmen: 
						-es gibt Operatoren, die sich nicht überladen lassen
								-technisch unmöglich
								-semantisch macht es keinen Sinn
Achtung:
			-man soll für eine Klasse nur solche Operaten überladen, die auch
			semantisch sinn machen:
			
			Date d1 = 19.1.1981
			Date d2 = 15.1.1987
			Duration d = d2 - d1 --- es macht sinn
			auto d = d2 + d1 eher zu sehr FantasiE --- vermeide!
			Date d = d1 + Duration --- Es macht sinn
			
			->Bitte die Semantik des Operators beibehalten, zum Beispiel 
			Kommutativität, Chaining verhalten
			
Overload Resolution:
					->Die Ermittelung der richtigen Version einer überladenn Funktion 
					(operator, constructor, methode) mittels Argumente
					->Falls mindestens eine der Operanden ein user-defined data type ist, erkennt
					das System, dass es um unsere Überladung sich handelt.
*/
class Point{
	private:
		double x;
		double y;
	public:
	
		 explicit Point(double x = 0 , double y = 0) : x(x), y(y) {//constructor overloading!
			//cout << "Point constructed " << endl;
		}	
		double getX() const { return x;}
		double getY()const {return y;}
		double get()const{
			double summe = this->x + this->y;
			summe += 2.0;
			return summe;
		}
		~Point(){
			//cout << "Point destroyeded" << endl;
		}
		friend void print(const Point& p);
		friend Point operator+( const Point& p1, const Point& p2);
		friend Point operator+(double d, const Point& p);
		friend Point operator+( const Point& p,double d);
	
};
void print(const Point& p) {//Lieber call by reference
	cout << "(" << p.x<< " , " << p.y << ")" << endl;
}
 Point operator+(const Point& p1, const Point& p2)
 {
	return Point{p1.x + p2.x, p1.y + p2.y};
 }
 
 Point operator+(double d, const Point& p){
	return Point(d,d) + p;//Aufruf der obigen Überladung
	// return Point{d + p.x, d + p.y};
 }
 Point operator+(const Point& p,double d){
	return  d + p;//Aufruf der obigen Überladung 
	
 }
  
class Date{
	private:
		int tag;
		int monat;
		int year;
	public:
		Date() : tag(1), monat(1), year(1970) {} //->parameterloser constructor
		Date(int tag) : tag(tag), monat(1), year(1970) {}//conversion constructor
		
		//friend double operator+(int x, double y); bereits eingebaute: redefnition!!
};


int main()
{
	

	Point p{3,4};
	Point q{1,2};
	
	Point sum1 = p + q ;//operator+(Point, Point) -->user defined overloading
	Point sum2 = 3.4 + p;//operator+(double, Point)-->user defined overloading
	Point sum3 = p + 3.4;//operator+(Point, double)
	print(sum1);
	print(sum2);
	
	p + q;
	// 3 + 5 + 7 + 9
	Point r{7.8};
	p + q + r;

	print(p + q);	
	
	
	return  0;
}