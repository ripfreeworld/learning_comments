#include <stdio.h>
#include <iostream>

using namespace std;



class Employee {
protected:
    string surname;
    string firstname;
    int birthdate;
    int takendays;
    int employeeType;
    int holidays;
    static int counter;
    
public:
    void create(){
        cout << "Please enter the employee's data." << endl;
        cout << "First Name: " << endl;
        cin >> firstname;
        cout << endl;
        cout << "Surname: " << endl;
        cin >> surname;
        cout << endl;
        cout << "Birthday in YYYYMMDD: " << endl;
        cin >> birthdate;
        cout << endl;
        cout << "What type of employee? [0] Hourly Employee, [1] Salaried Employee, [2] Manager" << endl;
        cin >> employeeType;
        counter++;
    }
    
    void remove(){
        counter--;
    }
    
    void search(){
        
    }
    
    void takeHolidays(){
        int offDays;
        cout << "How many days you want to take for holidays?" << endl;
        cin >> offDays;
        cout << "Now you have " << holidays - offDays << " days left." << endl;
    }
    
    // Set today is 2022.01.01 (YYYY.MM.DD)
    void checkBirthday(){
        if (birthdate > 19720101 && birthdate <= 20040101)  //the person have to be over 18 years old to be able to work.
            holidays = 30;
        else if (birthdate <= 19720101 && birthdate >= 19470101) //the oldest employement age should not older than 75 years old.
            holidays = 32;
        else
            cout << "Check the Birthday date again! (The person is either too young or too old or the birthday date is not valid.)" << endl;
    }
    
};

class HourlyEmployee : public Employee {
private:
    float HourlyWage;
    float WorkHours;

    
public:
    void setHourlyWage(){
        cout << "What is the hourly wage (in Euro)?" << endl;
        cin >> HourlyWage;
    }
    
    void setWorkHours(){
        cout << "How many hours does he/she works?" << endl;
        cin >> WorkHours;
    }
    
    void totalWage(){
        cout << "The total wage is: " << HourlyWage * WorkHours << endl;
    }
    
    void display(){
        creating();
        if (employeeType ==  0)
            setHourlyWage();
            setWorkHours();
            totalWage();
        
//        cout << "First Name: " << firstname << endl;
//        cout << "Surname: " << surname << endl;
//        cout << "Birthday (DDMMYYYY): " << birthdate << endl;
//        cout << "Type of Employee ([0] Hourly Employee, [1] Salaried Employee, [2] Manager): " << employeeType << endl;
//        cout << "The total wage is: " << HourlyWage * WorkHours << endl;
//        cout << "The remaning holiday days: " << holidays << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    float AnnualSalary;
    
public:
    void setAnnualSalary(){
        cout << "What is the annual salary?" << endl;
        cin >> AnnualSalary;
    }
    
    void getAnnualSalary(){
        cout << "The annual salary is: " << AnnualSalary << endl;
    }
    
    void display(){
        creating();
        if (employeeType ==  1)
            setAnnualSalary();
            getAnnualSalary();
//        cout << "First Name: " << firstname << endl;
//        cout << "Surname: " << surname << endl;
//        cout << "Birthday (DDMMYYYY): " << birthdate << endl;
//        cout << "Type of Employee ([0] Hourly Employee, [1] Salaried Employee, [2] Manager): " << employeeType << endl;
//        cout << "The Annual Salary is: " << AnnualSalary << endl;
//        cout << "The remaning holiday days: " << holidays << endl;
    }
};

class Manager : public Employee {
private:
    float ProfitSharing;
    
public:
    void display(){
        creating();
        if (employeeType ==  2)
            cout << "The profit sharing is: " << ProfitSharing << endl;
//        cout << "First Name: " << firstname << endl;
//        cout << "Surname: " << surname << endl;
//        cout << "Birthday (DDMMYYYY): " << birthdate << endl;
//        cout << "Type of Employee ([0] Hourly Employee, [1] Salaried Employee, [2] Manager): " << employeeType << endl;
//        cout << "The profit sharing is: " << ProfitSharing << endl;
//        cout << "The remaning holiday days: " << holidays << endl;
    }
};



int Employee :: counter = 0;

int main(){
    
    int input;
    Employee employee[500];
    
    cout << "Welcome to the Staff Management System." << endl << endl << "Please select a task from the menu..." << endl << endl << endl;
    
    do {
        cout << "[1] Add New Employee" << endl;
        cout << "[2] Delete Employee" << endl;
        cout << "[3] Take Holidays" << endl;
        cout << "[4] Search Employee" << endl;
        cout << "[5] See All Employees" << endl;
        
        cout << "[0] Exit" << endl;
        cout << "Make a selection: ";
        
        cin >> input;
        
        switch (input) {
            case 1:
                employee[500].creating();
                break;
            
            case 2:
                break;
                
            case 3:
                break;
                
            default:
                break;
        }
        
    } while (input != 0);
    
    
    return 0;
}
