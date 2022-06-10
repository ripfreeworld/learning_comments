#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
protected:
    // these basic information should never be modified
    const string firstname;
    const string surname;
    const int birthdate;
    // the restHolidays will
    int restHolidays;

public:
    Employee() = default;
    Employee(const string fname, const string sname, const int bdate) :
        firstname(fname),
        surname(sname),
        birthdate(bdate)
    {
        restHolidays = ((2021 - bdate / 10000) > 50) ? 32 : 30;
    }
    
    string getInfo(){
        cout << this->restHolidays << endl;
        return firstname + " " + surname + " " + to_string(birthdate);

    }
    
    string getFirstname(){
        return firstname;
    }
    
    string getSurname(){
        return surname;
    }
    
    int getBirthdate(){
        return birthdate;
    }
};

// use polymorphism to manage different kinds of employees
class EmployeeSystem {
private:
    vector<Employee*> employeeVec; // max of 500 employees

public:
    // constructor: initially empty, i.e. nullptr
    EmployeeSystem() {}
    ~EmployeeSystem(){
        delete[] employeeVec;
    }

    // add to vector
    void AddEmployee(Employee* _pEmployee)
    {
        employeeVec.push_back(_pEmployee);
    }
    // remove from vector
    void RemoveEmployee(Employee* _employee)
    {
        employeeVec.pop_back(_pEmployee);
    }


};


int main(){
    while (getline(cin, line))
    {

    }


    Employee employee("yiting", "tseng", 19931102);

    
    assert(employee.getFirstname() == "yiting");
    assert(employee.getSurname() == "tseng");
    assert(employee.getBirthdate() == 19931102);
    cout << employee.getInfo();
    assert(employee.getInfo() == "yiting tseng 19931102");
    
    
    
    return 0;
}
