#include <iostream>

class B{
public:	
	B(int* _pn){	
		b = _pn;	
	}
	void set_b_value(int _n){	*b = _n;	}
private:
	int* b;
};

class A{
public:
	A():pb(new B(&a)) {}
	B* pb;
	int GetA(){	return a;	}
private:
	int a = 0;
};


	
int main(int argc, char const *argv[])
{
	A a_obj;
	a_obj.pb->set_b_value(5);

	std::cout << a_obj.GetA() << std::endl;
	/* code */
	return 0;
}