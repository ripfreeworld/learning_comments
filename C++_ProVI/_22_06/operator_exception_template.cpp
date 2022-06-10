/**
	Data structure:
					-Eine Menege von Werte + Eine Menge von Operation
	Klassich (aus C):
						-array
						      -Performance (arbeitet näher an Maschine, *, [], new, delete)
						Nachteile:
									-unterstütz wenige Operation, in der Regel statisch
									(Anzahl der Elemente muss im voraus bekannt sein!)
									-index operator
	Container classes:
						-dynamisch bzgl. Größe
						-Memory Management ist automatisch
						-unterstütz viele Operatoren und Methoden
						
*/
#include <iostream>
using namespace std;

class IntArray{
	private:
			int len;
			int* elemente;
			
	public:
			//bool error = false;
			IntArray(int len) : len(len), elemente{new int[len]} {}
			~IntArray(){delete [] elemente;}
			//There exceptional situation: index < 0 oder index >= len
			void add(int index, int value){
				if(index >= len || index < 0)
						throw index;
				
				elemente[index] = value;
			}
			//There exceptional situation: index < 0 oder index >= len
			int get(int index) const{
				if(index >= 0 && index < len)
						return elemente[index];
				else	
				{
					//error = true;//Caller auf Ausnahme Situation signalisieren
					//return 0;//Das ist ein Fehler und ist kein sonderwert
					throw index;
				}
			}
			int size() const {
				return len;
			}
			 int& operator[]( int index) const{
				 if(index >= len || index < 0)
						throw index;
				
				return elemente[index];
			}
};

void print(const IntArray& ia){
	for(int i = 0; i < ia.size(); i++){
		cout << ia.get(i) << " ";
	}
	cout << endl;
}

int fakul(int n){
	if(n < 0)
			return -1;//Fehler signalisieren durch einen Sonderwert!
	if(n == 0 || n == 1)
			return 1;
	else 
		return n * fakul(n - 1);
	}
int main()
{
	 IntArray a{3};
	for(int i = 0; i<=3; i++)
		try{
			a.add(i, 2 * i +1);//i = 3 >= len
		}catch(int ex){
			//Behandlung
			cout << "Du hast versucht mehr Elemente hinzuzufügen, als es Platz gibt: " << ex <<endl; 
			}
	print(a);
	
	//cout << a.get(3) << endl;
	for(int i = 0; i<=3; i++)
	try{
		a[i] = 2*i + 1;//error: operator[] ist für die Klase IntArray nicht überladen
	}
	catch(int ex){
			//Behandlung
			cout << "Du hast versucht mehr Elemente hinzuzufügen, als es Platz gibt: " << ex <<endl; 
			}
	//cout << a << endl;//error: operator<< ist für die Klasse IntArray nicht überladen
	
	

return 0;
}