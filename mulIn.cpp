#include <iostream>

using namespace std;

class mamle
{
public:
    void printMamel()
    {
        cout<<"I am Mamel";

    }
};


class fly
{
public:
    void printfly()
    {
        cout<<"\nI can FLY";

    }
};

class bat:public mamle,public fly
{
public:
    void printbat()
    {
        mamle::printMamel();
        fly::printfly();
        cout<<"\nI am a BAT";
    }

};


int main()
{
    bat b1;
    b1.printbat();
}
