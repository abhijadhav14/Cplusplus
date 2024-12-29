#include <iostream>

using namespace std;

class date
{
    int dd;
    int mm;
    int yyyy;
public:
    void getDate(int dd,int mm,int yyyy)
    {
        this->dd=dd;
        this->mm=mm;
        this->yyyy=yyyy;
    }

    void printDate()
    {
        cout<<"\n"<<dd<<"/"<<mm<<"/"<<yyyy<<"\n";
    }
};

class person
{
    string name;
    int age;
    int id;
    date DOB;
    date DOD;


public:
    static int countpop;

    person(string name)
    {
        this->name=name;
    }
    void B_certificate(int id,int dd,int mm, int yyyy)
    {
        cout<<"\nname of person: "<<name;
        age=0;
        this->id=id;
        cout<<"\nID=\t"<<id;
        countpop++;

        DOB.getDate(dd,mm,yyyy);

        cout<<"\nDOB:  ";
        DOB.printDate();
    }

    void D_certificate(int age,int dd,int mm,int yyyy)
    {
        cout<<"\nname of person:  "<<name;
        this->age=age;
        cout<<"\nAge :\t"<<age;
        countpop--;

        DOD.getDate(dd,mm,yyyy);
        DOD.printDate();
    }

    void printpop()
    {
        cout<<"\nTotal Population: "<<countpop;
    }

};


int person::countpop=0; //this is must for static members to bring the static variables within the scope of class

int main()
{
 
  person p("xyz"),p1("ABC,"),p2("lmn");
  p.B_certificate(1,01,02,1990);
  p1.B_certificate(2,20,11,1992);
  p2.B_certificate(3,14,04,1991);
  p2.printpop();

  p.D_certificate(75,01,02,2075);
  p2.printpop();


    return 0;
}
