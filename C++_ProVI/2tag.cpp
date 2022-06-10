#include <iostream>

using namespace std;

/*
	constexpr: only for compile time constants
	const: Der Wert muss nicht zur Kompilierungszeitpunkt bekannt sein



lvalue vs rvalue:
	lvalue:
		Linke Seite einer Zuweisung (kann)
		muss eine Adresse haben (ein Objekt im Speicher mit Adresse)
			e.g. &3 ist falsch zu haben

	rvalue:
		Identifieziert zwar ein Objekt (Wert), hat aber keine Adresse
		hat kürzer Lebensdauer (only expression time)
			e.g.	int i = 1 + 1;
					int j = i + 2;	// i ist noch lvalue

*/

int main()
{
	int i = 0;
	const int j = 3;
	const int k = i;				// k nimmt den Wert von i, als const, nicht als const expression
	constexpr int ci = i;			// error: i ist nicht const
	constexpr int cj = j;			// ok: j zur Kompilierungszeitpunkt schon bekannt
	constexpr int ck = k;			// error: constness von k ist noch nicht bekannt
	constexpr int c = 2 * i + 1;	// error: i ist nicht const
	constexpr int c2 = 2 * j + 1;
	constexpr int c3 = 2 * cj + 1;
}