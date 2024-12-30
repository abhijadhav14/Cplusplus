#include <iostream>

using namespace std;

class Alpha
{
private:
    int data1;

    void show()
    {
        cout<<"Friend Class: "<<data1<<endl;
    }

public:
    Alpha()
    {
        data1=10;
    }

    friend class Beta;
};

class Beta
{
public:
    void printData()
    {
        Alpha a;
        a.show();

    }

    void printData(Alpha a)
    {
        a.data1=100;
        a.show();

    }
};



int main()
{
    Beta b;
    b.printData();
    Alpha aa;
    b.printData(aa);
    return 0;
}
