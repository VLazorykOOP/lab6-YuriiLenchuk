#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;
namespace SpaceExample3 {
    class Employee {
    protected:
        string name;
        int employeeID;

    public:
        Employee(const string& empName, int empID) : name(empName), employeeID(empID) {}

        virtual ~Employee() {}

        virtual void displayInfo() const {
            cout << "Employee Name: " << name << endl;
            cout << "Employee ID: " << employeeID << endl;
        }

        friend ostream& operator<<(ostream& os, const Employee& employee);
        friend istream& operator>>(istream& is, Employee& employee);
    };
    ostream& operator<<(ostream& os, const Employee& employee) {
        os << "Employee Name: " << employee.name << endl;
        os << "Employee ID: " << employee.employeeID << endl;
        return os;
    }

    istream& operator>>(istream& is, Employee& employee) {
        cout << "Enter Employee Name: ";
        is >> employee.name;
        cout << "Enter Employee ID: ";
        is >> employee.employeeID;
        return is;
    }

    class Parent {
    protected:
        string parentName;
        int age;

    public:
        Parent(const string& pName, int pAge) : parentName(pName), age(pAge) {}

        virtual ~Parent() {}

        virtual void displayInfo() const {
            cout << "Parent Name: " << parentName << endl;
            cout << "Age: " << age << endl;
        }

        friend ostream& operator<<(ostream& os, const Parent& parent);
        friend istream& operator>>(istream& is, Parent& parent);
    };
    ostream& operator<<(ostream& os, const Parent& parent) {
        os << "Parent Name: " << parent.parentName << endl;
        os << "Age: " << parent.age << endl;
        return os;
    }

    istream& operator>>(istream& is, Parent& parent) {
        cout << "Enter Parent Name: ";
        is >> parent.parentName;
        cout << "Enter Age: ";
        is >> parent.age;
        return is;
    }

    class Employee_Parent : public Employee, public Parent {
    private:
        string companyName;

    public:
        Employee_Parent(const string& empName, int empID, const string& pName, int pAge, const string& company)
            : Employee(empName, empID), Parent(pName, pAge), companyName(company) {}
        void displayInfo() const override {
            Employee::displayInfo();
            Parent::displayInfo();
            cout << "Company Name: " << companyName << endl;
        }

        friend ostream& operator<<(ostream& os, const Employee_Parent& employeeParent);
        friend istream& operator>>(istream& is, Employee_Parent& employeeParent);
    };

    ostream& operator<<(ostream& os, const Employee_Parent& employeeParent) {
        os << static_cast<const Employee&>(employeeParent);
        os << static_cast<const Parent&>(employeeParent);
        os << "Company Name: " << employeeParent.companyName << endl;
        return os;
    }
    istream& operator>>(istream& is, Employee_Parent& employeeParent) {
        is >> static_cast<Employee&>(employeeParent);
        is >> static_cast<Parent&>(employeeParent);
        cout << "Enter Company Name: ";
        is >> employeeParent.companyName;
        return is;
    }

    int mainExample3()
    {
        Employee_Parent empParent("John Doe", 1234, "Jane Smith", 35, "ABC Company");
        empParent.displayInfo();
        cout << endl;
        cout << empParent << endl;
        cin >> empParent;
        cout << endl;
        empParent.displayInfo();

        return 0;
    }


}