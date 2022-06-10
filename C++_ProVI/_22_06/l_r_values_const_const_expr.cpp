#include <iostream>
#include <cmath> 
using namespace std;
/**
Important Points:
					const vs constexpr
					lvalue vs rvalue
					const reference 
					
const vs constexpr:
					-constexpr gab bis c++98 nicht!
					-Both are for constants
					-constexpr: only for compile time constants 
					-const: Der Wert muss nicht unbedingt zur Kompilierungszeitpunkt bekannt sein
Motivation:
			-constexpr is new C++ Feature, it enhances Performance of the programm
			-Evalutation happens at compile-time!
			
lvalue vs rvalue:
				-left value , right value
				-left side of an assignment statement, right side of an assignement statement
lvalue:
		-Linke Seite einer Zuweisung (kann)
		-hat eine Adresse (Ein Objekt im Speicher mit Adresse)
		-Beispiele:
					int i = 3;, i ist eine lvalue
					int j = i;
					i = j + 1;
					cout << &i << &j << endl;//i und j haben Adressen -> lvalues
					cout << &3 << endl; //error: Literal 3 hat keine Adresse im Speicher -> rvalue
rvalue:
		-Identifiziert zwar ein Objekt (Wert), hat aber keine Adresse 
		-hat kurze Lebensdauer (only expression time)
		int i = 2 * 5 + 1;
		int j = 2 * i +1;
		
Achtung:
			Normalerweise, Funktionsaufrufe sind rvalue, es sei denn die Funktion ist
			return by reference, dann ist der Funktionsaufruf ein lvalue
*/
class Point{
	private:
		double x;
		double y;
		
};

//return by reference - bad implementation!!!

int& fct(int x){
	int s = 2 + x +1;
	return s;
}
// 
//s gets destroyed!automatisch!, Lokale Variable auf dem Stack

//return by reference - the right way to do it!!!
int& gct(int& x)
{
	x = 2 * x +1;
	return x;
}
int main()
{
	int i = 0;
	/**
	cin >> i;
	*/
	const int j = 3;
	const int k = i;//
	//constexpr int ci = i;//error
	constexpr int cj = j;//ok
	//constexpr int ck = k;//error
	//constexpr int c = 2 * i + 1;//error
	constexpr int c2 = 2 * j + 1;//ok
	constexpr int c3 = 2 * cj + 1;//ok
	cout << i << j << k << c2 << c3 << endl;
	
	int v = 3;
	
	v = i;
	//v = fct(i);
	cout << &v << endl; //ok
	cout << &i << endl; //ok
	//cout << &fct(i) << endl;//error
	int t = 23;
	cout << "&t = " << &t << endl;//420
	int t2 = gct(t);//int& x = t; x ist ein andere name von t
	cout << "&t = " << &t << endl;//420
	cout << "&gct(t) = " << &gct(t) << endl;//420
	cout << "t2 = " << t2 << endl;
	//int x = 2;
	//sqrt(144) = x;//sqrt(144) ist kein lvalue -> error
//	x = sqrt(144); //ok
	gct(t) = 100;//ok
	cout << "t = " << t << endl; //100
	fct(t);
	
	return 0;
}