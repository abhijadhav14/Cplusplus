#include <iostream>

using namespace std;

class Doc
{
    string name;
    int id;
    float sal;
    static int countDoc;
public:
    void getDoc()
    {
        cout<<"\nEnter Name of Doctor: ";
        cin>>name;
        cout<<"\nEnter Doctor ID: ";
        cin>>id;
        cout<<"\nEnter Doctors Salary: ";
        cin>>sal;
    }

    void putDoc()
    {
        cout<<"\nName of Doctor: "<<name;
        cout<<"\nDoctor ID: "<<id;
        cout<<"\nDoctor's Salary: "<<sal;
    }
};


class Dept
{
    string Deptname;
    int Deptid;
    Doc D[2];
public:
    void getDept()

    {
        cout<<"\nEnter Dept Name: ";
        cin>>Deptname;
        cout<<"\nEnter Dept id: ";
        cin>>Deptid;
        for(int i=0;i<2;i++)
         {
           D[i].getDoc();

         }

    }

    void putdept()
    {
        cout<<"\nDept Name: "<<Deptname;

        cout<<"\nDept id: "<<Deptid;
        for(int i=0;i<5;i++)
         {
           D[i].putDoc();

         }

    }
};


class hospital
{
    string Hname;
    int Hid;
    Dept D[2];
public:
    void getHospital()
    {
        cout<<"\nEnter the Name of Hospital: ";
        cin>>Hname;
        cout<<"\nEnter Hospital id: ";
        cin>>Hid;
        for(int i=0;i<2;i++)
        {
            D[i].getDept();
        }
    }

    void putHospital()
    {
        cout<<"\nName of Hospital: "<<Hname;

        cout<<"\nHospital id: "<<Hid;

        for(int i=0;i<2;i++)
        {
            D[i].putdept();
        }
    }
};

int Doc::countDoc=0;

int main()
{
   hospital h[2];
   for(int i=0;i<2;i++)
   {
      h[i].getHospital();
   }

   for(int i=0;i<2;i++)
   {
      h[i].putHospital();
   }



    return 0;
}
