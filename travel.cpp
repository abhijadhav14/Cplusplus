#include <iostream>

using namespace std;


class TravelAgency
{

    int TAid;
    string TAname;

public:

    TravelAgency()
    {

    }

   TravelAgency(int TAid,string TAname)
    {
        this->TAid=TAid;
        this->TAname=TAname;
    }



    void getTA()
    {
        cout<<"Travel Agency : "<<TAname;
        cout<<"\nTravel Agency id: "<<TAid;
    }

};

class car
{
    int carid;
    string carname;
    string cartype;

public:

    car()
    {

    }

    car(int carid, string carname,string cartype)
    {
        this->carid=carid;
        this->carname=carname;
        this->cartype=cartype;
    }



    void carDetail()
    {
        cout<<"\nCAR id:"<<carid;
        cout<<"\nCAR NAME:"<<carname;
        cout<<"\nCAR TYPE: "<<cartype;
    }

};

class Bus
{
    int busid;
    string busname;

    static string Bustype="Public Transport"

public:
    Bus(int busid, string busname)
    {
        this->busid=busid;
        this->busname=busname;

    }



    void busDetail()
    {
        cout<<"\nBUS id:"<<busid;
        cout<<"\nBUS NAME:"<<busname;
        cout<<"\nBUS TYPE: "<<Bustype;

    }

};

class rent:public car
{
public:

    int rentid;
    int rentdays;
    car::carid;

    void rentdetail()
    {
        cout<<"\n RENT ID:"
        cout<<"\n RENT DAYS:"
    }
};


int main()
{
    TravelAgency t;
    t=TravelAgency(4,'ola')
    t.getTA();

    car c;
    c.carDetail(56,'swift');

    bus b;
    b.busDetail(89,'vijaynagar');

    rent r;
    r.rentdetail(12,'4');
}
