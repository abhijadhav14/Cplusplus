#include <iostream>

using namespace std;

class student
{

    string name;

public:

     int marks;

    student(string name)
    {
        this->name=name;

    }

   virtual  void calmarks()=0;
   /* {
        cout<<"\nThis is Baseclass";
    } */

    void display()
    {
        cout<<"\nName: "<<name;
        cout<<"\nMarks: "<<marks;
    }
};

class schoolStudent:public student
{
    int rollno;
public:
    schoolStudent(string name,int rollno):student(name)
    {
        this->rollno=rollno;
    }

    void calmarks()
    {
        int m1,m2,m3;

        cout<<"Enter 3 Marks\n";
        cin>>m1;
        cin>>m2;
        cin>>m3;

        marks=m1+m2+m3;
        cout<<"\nI am School Student";
    }

    void display()
    {
        student::display();
        cout<<"\nRoll no: "<<rollno;

    }
};

class ugstudent:public student
{
    int sem;
public:

    ugstudent(string name,int sem):student(name)
    {
        this->sem=sem;
    }


    void calmarks()
    {
        int t1,t2,l1,l2;

        cout<<"\nEnter 2 theory marks:\n";
        cin>>t1;
        cin>>t2;

        cout<<"\nEnter 2 lab marks:\n";
        cin>>l1;
        cin>>l2;

        marks=t1+t2+l1+l2;
        cout<<"\nI am UG Student";

    }
};

int main()
{
    student *s ;
    schoolStudent ss("Freg",120);
    ugstudent us("Jack",3);

    s=&ss;

    s=&us;

    s->calmarks();

    s->display();


    return 0;
}
