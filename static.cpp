#include <iostream>

using namespace std;

class person
{
    string name;
    int age;
    int id;
    static int countpop;
public:
    person(string name)
    {
        this->name=name;
    }
    void B_certificate(int age)
    {
        cout<<"\nname of person "<<name;
        age=0;
       // this->id=id;
        cout<<"ID=\t"<<id;
        countpop++;
    }

    void D_certificate(int age)
    {
        cout<<"\nname of person  "<<name;
        this->age=age;
        cout<<"\t\tAge :\t"<<age;
        countpop--;
    }

    void printpop()
    {
        cout<<"\nTotal Population: "<<countpop;
    }

};


int person::countpop=0; //this is must for static members to bring the static variables within the scope of class

int main()
{
  //  cout << "Hello world!" << endl;
  person p("xyz"),p1("ABC,"),p2("lmn");
  p.B_certificate(1);
  p1.B_certificate(2);
  p2.B_certificate(3);
  p2.printpop();

  p.D_certificate(75);
  p2.printpop();


    return 0;
}
