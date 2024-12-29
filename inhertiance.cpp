#include <iostream>

using namespace std;

class person
{
    public:
    string name;
    int age;


    person(string name , int age)
    {
        this->name=name;
        this->age=age;

    }

  /*  void printPerson()
    {
        cout<<"\nname: "<<name;
        cout<<"\nAge: "<<age;
    }
*/
};

class student:protected person
{
    int id;
public:
    student(string name,int age,int id):person(name,age)
    {
        this->id=id;
    }

    void printStudent()
    {
        cout<<"Name: "<<name;
        cout<<"Age: "<<age;
      //  person::printPerson();
        cout<<"\nID: "<<id;

    }

};


int main()
{
     student s1("RAM",25,001);
     s1.printStudent();

    return 0;
}
