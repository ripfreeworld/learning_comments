#include <iostream>

using namespace std;

/*
	Data structure:
		-Eine Menge von Werte + eine Menge von Operation

	Klassisch: aus C
		-array
			
	
	Container Classes:

*/


template <typename T> class TArray {
private:	
	int len;
	T* element;
public:
	TArray(int len) : len(len), elemente(new T[len]) {}
	~TArray() { delete [] elemente;  }
	void AddValue (int n, T value) {
		this->element[n] = value;
	}
	T GetValue (int n) const {
		return this->element[n];
	}
	T& operator [] (int index) const {
		return element[index];
	}
};

template <typename T>
void print(const TArray<T>& arry) {
	for (size_t i = 0; i < arry.len; i++)
	{
		cout << arry[i] << endl;
	}
}

int main() {
	int n = 10;
	
}