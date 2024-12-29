#include<iostream>

using namespace std;
class Student
{
    int roll_num;//data members
    string name;
    void setData(int x,string y)//member functions
    {
        roll_num=x;
        name=y;
    }
    void showdata()
    {
        cout<<"Roll_number:"<<roll_num<<"Name:"<<name<<endl;
    }
};

int main()
{
    Student s;
    s.setData(1,"abc");
    s.showdata();
    return 0;
}
