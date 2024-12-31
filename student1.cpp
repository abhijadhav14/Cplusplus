#include <iostream>

using namespace std;

class course
{
   string cName;
   string cCode;
   int cCredit;

   public:
    void getCourse()
    {
        cout<<"\nEnter Name of Course: ";
        cin>>cName;
        cout<<"\nEnter Course Code: ";
        cin>>cCode;
        cout<<"\nEnter Course Credit: ";
        cin>>cCredit;
    }

    void putCourse()
    {
        cout<<"\nName of Course: "<<cName;
        cout<<"\nCourse Code: "<<cCode;
        cout<<"\nCourse Credit: "<<cCredit;
    }


};

class student
{
        private:
                char name[20],regd[10],branch[10];
                int sem;
        public:


       void input()
     {
        cout<<"Enter Student Name:";
        cin>>name;
        cout<<"Enter Student Regdno.:";
        cin>>regd;
        cout<<"Enter Branch:";
        cin>>branch;
        cout<<"Enter Sem:";
        cin>>sem;
     }
     void display()
{
        cout<<"\nName:"<<name;
        cout<<"\nRegdno.:"<<regd;
        cout<<"\nBranch:"<<branch;
        cout<<"\nSem:"<<sem;
}

     void SelectCourse()
     {
        cout<<"Select the Any 4 Cources";

     }

};

 /*class name
{
    string Fname;
    string Lname;
    public:
   void getName()
   {
       cout<<"\n Enter the First Name of Student: ";
       cin>>Fname;

       cout<<"\n Enter the Last Name of Student: ";
       cin>>Lname;
   }
   public:
   void putName()
   {
        cout<<"\nFirst Name: "<<Fname;
        cout<<"\nLast Name: "<<Lname;

   }
};
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

class cource
{
    void courcename(string cname)
    {
        this->cname=cname;

    }

    void courcecode(string ccode)
    {
        this->ccode=ccode;
    }

    void courceCredit(int credit)
    {
        this->credit=credit;
    }
};
*/
int main()
{
    student s;
    s.input();
    s.display();

   course c[10];

   for(int i=0;i<10;i++)
   {
       c[i].getCourse();
   }

   for(int i=0;i<10;i++)
   {
       c[i].putCourse();
   }


    return 0;
}
