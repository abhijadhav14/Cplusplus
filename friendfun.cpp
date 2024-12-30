#include <iostream>

using namespace std;

class Beta;

class Alpha
{
private:
    int data;
public:
    Alpha()
    {
        data=10;
    }

    friend int friFun(Alpha,Beta);
};

class Beta
{
private:
    int data;
public:
    Beta()
    {
        data=100;
    }

    friend int friFun(Alpha,Beta);
};


int friFun(Alpha a,Beta b)
{
    return a.data+b.data;
}


int main()
{
    Alpha aa;
    Beta bb;
    cout << "Data: " <<friFun(aa,bb);
    return 0;
}
