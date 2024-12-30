#include <iostream>
#include <exception>

using namespace std;

class NevBalanceExcp:public exception
{
    public:
    const char * what() const throw()
    {
        return "Balance Underflow\n";
    }
};

class Account
{

    int accno;
    float bal;
public:
    Account(int accno,float bal)
    {
        this->accno=accno;
        if(bal<0)
        {
            NevBalanceExcp nb;
            throw nb;
        }
    }
    Account()
    {

    }
};



class AgeException : public exception
{
public:
    const char * what() const throw()
    {
        return "Age is below 18\n";
    }
};

class customer
{
    string name;
    int age;
    Account a;
public:
    customer(string name,int age,Account a)
    {
        this->name=name;
        this->a=a;
        if(age<18)
        {
            AgeException e;
            throw e;
        }
        else
        {


            this->age=age;
        }
    }

};


int main()
{
    try
    {
        Account a(123,250);
       customer c("RAM",17,a);
    }

    catch(exception &e)
    {
        cout<<e.what();
    }

    /* catch(AgeException e)
    {
        cout<<e.what();
    }

   catch(NevBalanceExcp e)
    {
        cout<<e.what();
    } */
}
