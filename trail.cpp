#include<iostream>
#include<fstream>
#include<windows.h>
#include<direct.h>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<exception>
using namespace std;

int layspr,maggipr,sdpr;
int laysqty,maggiqty,sdqty;
void billpage();
void empjump();
void billjump();
void handlecust();

class login;
class store;
class employee;
class myexception;
class order;
class billing;

class myexception: public exception
{
public:
string error_msg;
myexception(string msg)
{
error_msg=msg;
}
void login_error()
{
cout<<endl<<error_msg<<endl;
}
};

class store
{
    public:
        string item;
        string name;
        int amt;
        int ch;
        int rate;
        int qty=0;
        void mnginvt();
        void storepageswitch();
        void price();
        void viewinvt();
        void quantity();
        void storepage()
        {
            storepageswitch();
        }
};

void store::storepageswitch()
{

    cout<<"     PLEASE UPDATE THE PRICE AND QUANTITY OF"<<endl;
    cout<<"     ITEMS IN MANAGE INVENTORY BEFORE PROCEEDING"<<endl<<endl;
    cout<<"     1. MANAGE INVENTORY"<<endl;
    cout<<"     2. VIEW INVENTORY"<<endl;
    cout<<"     3. TAKE ORDER"<<endl;
    cout<<"     4. VIEW SALES RECORD"<<endl;
    cout<<"     5. EXIT"<<endl<<endl;
    cout<<"     ENTER CHOICE"<<endl;
    cout<<"     ";cin>>ch;
    while(ch!=1||ch!=2||ch!=3)
    {
        switch(ch)
        {
            case 1:
                mnginvt();
                break;
            case 2:
                viewinvt();
                break;
            case 3:
                handlecust();
                break;

            case 5:
                exit(0);
            default:
                cout<<endl<<"     INVALID CHOICE"<<endl<<endl;
                cout<<"     ENTER CHOICE"<<endl<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void store::mnginvt()
{

    cout<<"     1. EDIT PRICE"<<endl;
    cout<<"     2. ENTER QUANTITY"<<endl<<endl;
    cout<<"     ENTER CHOICE"<<endl;
    cout<<"     ";cin>>ch;
    while(ch!=1||ch!=2)
    {
        switch(ch)
        {
            case 1:
                price();
                break;
            case 2:
                quantity();
                break;
            default:
                cout<<endl<<"     INVALID CHOICE"<<endl<<endl;
                cout<<"     ENTER CHOICE"<<endl<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void store::price()
{

    cout<<"     CURRENT INVENTORY"<<endl;
    ifstream currprice("PRICE.txt");
    cout<<"     "<<"ITEM"<<" - "<<"PRICE(Rs)"<<endl;
    cout<<"     ------------"<<endl;
    while(currprice>>item>>rate)
    {
        cout<<"     "<<item<<" - "<<rate<<endl;
    }
    currprice.close();
    remove("PRICE.txt");
    fstream editprice("PRICE.txt",ios::app);
    cout<<endl<<"     ENTER PRICE OF LAYS"<<endl;
    cout<<"     ";cin>>layspr;cout<<endl;
    editprice<<"LAYS"<<' '<<layspr<<endl;
    cout<<"     ENTER PRICE OF MAGGI"<<endl;
    cout<<"     ";cin>>maggipr;cout<<endl;
    editprice<<"MAGGI"<<' '<<maggipr<<endl;
    cout<<"     ENTER PRICE OF SOFT DRINK"<<endl;
    cout<<"     ";cin>>sdpr;cout<<endl;
    editprice<<"SOFTDRINK"<<' '<<sdpr<<endl;;
    editprice.close();


    cout<<"     NEW INVENTORY"<<endl;
    ifstream viewprice("PRICE.txt");
    cout<<"     "<<"ITEM"<<" - "<<"PRICE(Rs)"<<endl;
    cout<<"     ------------"<<endl;
    while(viewprice>>item>>rate)
    {
        cout<<"     "<<item<<" - "<<rate<<endl;
    }
    viewprice.close();
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";getch();
    storepage();
}
void store::quantity()
{
    cout<<"     CURRENT INVENTORY"<<endl;
    ifstream currqty("QUANTITY.txt");
    cout<<"     "<<"ITEM"<<" - "<<"QUANTITY"<<endl;
    cout<<"     ---------------"<<endl;
    while(currqty>>item>>qty)
    {
        cout<<"     "<<item<<" - "<<qty<<endl;
    }
    currqty.close();
    remove("QUANTITY.txt");
    fstream editqty("QUANTITY.txt",ios::app);
    cout<<endl<<"     ENTER QUANTITY OF LAYS"<<endl;
    cout<<"     ";cin>>laysqty;cout<<endl;
    editqty<<"LAYS"<<' '<<laysqty<<endl;
    cout<<"     ENTER QUANTITY OF MAGGI"<<endl;
    cout<<"     ";cin>>maggiqty;cout<<endl;
    editqty<<"MAGGI"<<' '<<maggiqty<<endl;
    cout<<"     ENTER QUANTITY OF SOFT DRINK"<<endl;
    cout<<"     ";cin>>sdqty;cout<<endl;
    editqty<<"SOFTDRINK"<<' '<<sdqty<<endl;
    editqty.close();

    cout<<"     NEW INVENTORY"<<endl;
    cout<<"     "<<"ITEM"<<" - "<<"QUANTITY"<<endl;
    cout<<"     --------------------"<<endl;
    ifstream viewqty("QUANTITY.txt");
    while(viewqty>>item>>qty)
    {
        cout<<"     ";cout<<item<<" - "<<qty<<endl;
    }
    viewqty.close();
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";getch();
    storepage();
}
void store::viewinvt()
{
    cout<<"     PRICE OF ITEMS IN CANTEEN"<<endl;
    cout<<"     ITEM - PRICE(Rs)"<<endl;
    cout<<"     ------------"<<endl;
    ifstream vwpr("PRICE.txt");
    while(vwpr>>item>>rate)
    {
        cout<<"     ";cout<<item<<" - "<<rate<<endl;
    }
    vwpr.close();
    cout<<endl<<"     QUANTITY OF ITEMS IN CANTEEN"<<endl;
    cout<<"     ITEM - QUANTITY"<<endl;
    cout<<"     ---------------"<<endl;
    ifstream vwqt("QUANTITY.txt");
    while(vwqt>>item>>rate)
    {
        cout<<"     ";cout<<item<<" - "<<rate<<endl;
    }
    vwqt.close();
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";getch();
    storepage();
}
class billing
{
    public:
        string name;
        int cost1,cost2,cost3,qty,totalcost;
        store s;
        int amt;
        char dec;
        void viewstat();
        void clearstat();
        billing()
        {
            cost1=0;
            cost2=0;
            cost3=0;
        }
        void bill1(int qty)
        {
            cost1=0;
            cost1=layspr*qty;
        }
        void bill2(int qty)
        {
            cost2=0;
            cost2=maggipr*qty;
        }
        void bill3(int qty)
        {
            cost3=0;
            cost3=sdpr*qty;
        }
        void bill()
        {

            totalcost=cost1+cost2+cost3;
            cout<<"     ENTER NAME OF CUSTOMER"<<endl;
            cout<<"     ";cin>>name;cout<<endl;

            cout<<"     BILL : PAY FOLLOWING AMOUNT "<<endl;
            cout<<"     CUSTOMER NAME : "<<name<<endl;
            cout<<"     TOTAL COST IS : "<<"Rs"<<totalcost<<endl;;
            cout<<"     THANK YOU"<<endl;
            fstream billmod("SALESRECORD.txt",ios::app);
            billmod<<name<<' '<<totalcost<<endl;
            billmod.close();
            cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
            cout<<"     ";getch();

        }
};
void billing::viewstat()
{

    ifstream viewsr("SALESRECORD.txt");
    cout<<"     NAME - AMOUNT"<<endl;
    cout<<"     -------------"<<endl;
    while(viewsr>>name>>amt)
    {
        cout<<"     "<<name<<" - "<<"Rs"<<amt<<endl;
    }
    viewsr.close();
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";getch();
    s.storepage();
}
void billing::clearstat()
{

    cout<<"     CLEAR SALES RECORD [Y]"<<endl;
    cout<<"     ";cin>>dec;
    if(dec=='Y')
    {
        remove("SALESRECORD.txt");
        cout<<endl<<"     SALES RECORD CLEARED"<<endl;
        cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
        cout<<"     ";getch();
        remove("EMPLOYEE.txt");
        ifstream newsr("EMPLOYEE.txt");
        newsr.close();
        empjump();
    }
    else
    {
        cout<<endl<<"     SALES RECORD ARE NOT CLEARED"<<endl;
        cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
        cout<<"     ";getch();
        empjump();

    }
}
class order
{
    public:
        int tqty;
        string titem;
        billing b;
        int invtqty;
        string invtitem;
        char dec;
        int ch;
        int qty;
        void orderitem1();
        void orderitem2();
        void orderitem3();
        void orderpageswitch();
        void orderpage()
        {

            cout<<"     1. LAYS"<<endl;
            cout<<"     2. MAGGI"<<endl;
            cout<<"     3. SOFT DRINK"<<endl;
            cout<<"     4. EXIT"<<endl<<endl;
            cout<<"     ENTER ITEM TO ORDER"<<endl;
            cout<<"     ";cin>>ch;
            orderpageswitch();
        }
};
void order::orderpageswitch()
{
    while(ch!=1||ch!=2||ch!=3||ch!=4)
    {
        switch(ch)
        {
            case 1:
                orderitem1();
                break;
            case 2:
                orderitem2();
                break;
            case 3:
                orderitem3();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<endl<<"     INVALID CHOICE"<<endl;
                cout<<"     ENTER CHOICE"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void order::orderitem1()
{
    cout<<"     ENTER QUANTITY"<<endl;
    cout<<"     ";cin>>qty;cout<<endl;
    if(laysqty>=qty)
    {
        laysqty=laysqty-qty;
        ofstream temp1("temp1.txt");
        ifstream snackorder("QUANTITY.txt");
        while(snackorder>>titem>>tqty)
        {
            if(titem!="LAYS")
            {
                temp1<<titem<<' '<<tqty<<endl;
            }
            else
            {
                temp1<<"LAYS"<<' '<<laysqty<<endl;
            }
        }
        temp1.close();
        snackorder.close();
        remove("QUANTITY.TXT");
        rename("temp1.txt","QUANTITY.txt");
        b.bill1(qty);
        cout<<"     ORDER ANOTHER ITEM [Y]"<<endl;
        cout<<"     ";cin>>dec;
        if(dec=='Y')
        {
            orderpage();
        }
        else
        {
            b.bill();
        }
    }
    else
    {
        cout<<endl<<"     NOT AVAILABLE"<<endl;
        cout<<"     SELECT ANOTHER ITEM"<<endl;
        cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
        cout<<"     ";getch();

        ifstream orderout("QUANTITY.txt");
        cout<<"     ITEM - QUANTITY"<<endl;
        cout<<"     ---------------"<<endl;
        while(orderout>>invtitem>>invtqty)
        {
            cout<<"     "<<invtitem<<" - "<<invtqty<<endl;
        }
        orderout.close();
        cout<<endl<<"     PRESS ANY KEY FOR NEW ORDER"<<endl;
        cout<<"     ";getch();
        orderpage();
    }
}
void order::orderitem2()
{
    cout<<"     ENTER QUANTITY"<<endl;
    cout<<"     ";cin>>qty;cout<<endl;
    if(maggiqty>=qty)
    {
        maggiqty=maggiqty-qty;
        ofstream temp2("temp2.txt");
        ifstream maggiorder("QUANTITY.txt");
        while(maggiorder>>titem>>tqty)
        {
            if(titem!="MAGGI")
            {
                temp2<<titem<<' '<<tqty<<endl;
            }
            else
            {
                temp2<<"MAGGI"<<' '<<maggiqty<<endl;
            }
        }
        temp2.close();
        maggiorder.close();
        remove("QUANTITY.TXT");
        rename("temp2.txt","QUANTITY.txt");
        b.bill2(qty);
        cout<<"     ORDER ANOTHER ITEM [Y]"<<endl;
        cout<<"     ";cin>>dec;
        if(dec=='Y')
        {
            orderpage();
        }
        else
        {
            b.bill();
        }
    }
    else
    {
        cout<<endl<<"     NOT AVAILABLE"<<endl;
        cout<<"     SELECT ANOTHER ITEM"<<endl;
        cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
        cout<<"     ";getch();

        ifstream orderout("QUANTITY.txt");
        cout<<"     ITEM - QUANTITY"<<endl;
        cout<<"     ---------------"<<endl;
        while(orderout>>invtitem>>invtqty)
        {
            cout<<"     "<<invtitem<<" - "<<invtqty<<endl;
        }
        orderout.close();
        cout<<endl<<"     PRESS ANY KEY FOR NEW ORDER"<<endl;
        cout<<"     ";getch();
        orderpage();
    }
}
void order::orderitem3()
{
    cout<<"     ENTER QUANTITY"<<endl;
    cout<<"     ";cin>>qty;cout<<endl;
    if(sdqty>=qty)
    {
        sdqty=sdqty-qty;
        ofstream temp3("temp3.txt");
        ifstream sdorder("QUANTITY.txt");
        while(sdorder>>titem>>tqty)
        {
            if(titem!="SOFTDRINK")
            {
                temp3<<titem<<' '<<tqty<<endl;
            }
            else
            {
                temp3<<"SOFTDRINK"<<' '<<sdqty<<endl;
            }
        }
        temp3.close();
        sdorder.close();
        remove("QUANTITY.TXT");
        rename("temp3.txt","QUANTITY.txt");
        b.bill3(qty);
        cout<<"     ORDER ANOTHER ITEM [Y]"<<endl;
        cout<<"     ";cin>>dec;
        if(dec=='Y')
        {
            orderpage();
        }
        else
        {
            b.bill();
        }
    }
    else
    {
        cout<<endl<<"     NOT AVIALABLE"<<endl;
        cout<<"     SELECT ANOTHER ITEM"<<endl;
        cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
        cout<<"     ";getch();

        ifstream orderout("QUANTITY.txt");
        cout<<"     ITEM - QUANTITY"<<endl;
        cout<<"     ---------------"<<endl;
        while(orderout>>invtitem>>invtqty)
        {
            cout<<"     "<<invtitem<<" - "<<invtqty<<endl;
        }
        orderout.close();
        cout<<endl<<"     PRESS ANY KEY FOR NEW ORDER"<<endl;
        cout<<"     ";getch();
        orderpage();
    }
}
class employee
{
    public:
        int ch,age;
        char name[50];
        long int sal;
        void addemp();
        void displayemp();
        void removeemp();
        void editemp();
        void emppageswitch();
        void emppage()
        {

            cout<<" 1. DISPLAY ALL EMPLOYEE DETAILS"<<endl;
            cout<<"     2. ADD NEW EMPLOYEE DETAILS"<<endl;
            cout<<"     3. REMOVE OLD EMPLOYEE DETAILS"<<endl;
            cout<<"     4. VIEW SALES RECORD"<<endl;
            cout<<"     5. CLEAR SALES RECORD"<<endl;
            cout<<"     6. STOREPAGE"<<endl;
            cout<<"     7. EXIT"<<endl<<endl;
            cout<<"     ENTER CHOICE"<<endl;
            cout<<"     ";cin>>ch;
            emppageswitch();
        }
};
void employee::emppageswitch()
{
    while(ch!=1||ch!=2||ch!=3||ch!=4||ch!=5)
    {
        switch(ch)
        {
            case 1:
                displayemp();
                break;
            case 2:
                addemp();
                break;
            case 3:
                removeemp();
                break;
            case 4:
                {
                    billing b1;
                    b1.viewstat();
                }
                break;
            case 5:
                {
                    billing b2;
                    b2.clearstat();
                }
            case 6:
                {
                    store s;
                    s.storepage();
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<endl<<"     INVALID CHOICE"<<endl;
                cout<<"     ENTER CHOICE"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void employee::addemp()
{

    ofstream newemployee("EMPLOYEE.txt",ios::app);
    cout<<"     ENTER NAME OF EMPLOYEE"<<endl;
    cout<<"     ";cin>>name;
    cin.sync();
    cout<<"     ENTER AGE OF EMPLOYEE"<<endl;
    cout<<"     ";cin>>age;
    cout<<"     ENTER SALARY OF EMPLOYEE(Rs)"<<endl;
    cout<<"     ";cin>>sal;
    newemployee<<name<<' '<<age<<' '<<sal<<endl;
    newemployee.close();
    cout<<endl<<"     EMPLOYEE ADDED"<<endl;
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE";
    cout<<"     ";getch();
    emppage();
}
void employee::displayemp()
{

    ifstream employee("EMPLOYEE.txt");
    cout<<"     EMPLOYEE - AGE - SALARY(Rs)"<<endl;
    cout<<"     -----------------------"<<endl;
    while (employee>>name>>age>>sal)
    {
        cout<<"     "<<name<<" - "<<age<<" - "<<sal<<endl ;
    }
    employee.close();
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";getch();
    emppage();
}
void employee::removeemp()
{

    char tname[50];
    ifstream emp1("EMPLOYEE.txt");
    ofstream emp2("temp.txt");
    cout<<"     ENTER THE NAME OF EMPLOYEE WISH TO REMOVE"<<endl;
    cout<<"     ";cin>>tname;
    while(emp1>>name>>age>>sal)
    {
        if(strcmp(name,tname)!=0)
        {
            emp2<<name<<' '<<age<<' '<<sal<<endl;
        }
    }
    emp1.close();
    emp2.close();
    remove("EMPLOYEE.txt");
    rename("temp.txt","EMPLOYEE.txt");
    cout<<endl<<"     EMPLOYEE REMOVED"<<endl;
    cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
    cout<<"     ";getch();
    emppage();
}
class login
{
  public:
      string pass="";
      int ch;
      char c;
      void loginpageswitch();
      void homepageswitch();
      void employeelogin();
      void ownerlogin();
      void emp();
      void own();
      void homepage()
      {

          cout<<"     1. LOGIN"<<endl;
          cout<<"     2. EXIT"<<endl<<endl;
          cout<<"     ENTER CHOICE"<<endl;
          cout<<"     ";cin>>ch;
          homepageswitch();
      }
      void loginpage()
      {

          cout<<"     1. OWNER LOGIN"<<endl;
          cout<<"     2. EMPLOYEE LOGIN"<<endl;
          cout<<"     3. EXIT"<<endl<<endl;
          cout<<"     ENTER CHOICE"<<endl;
          cout<<"     ";cin>>ch;
          loginpageswitch();
      }
};


void login::homepageswitch()
{
    while(ch!=1||ch!=2)
    {
        switch(ch)
        {
        case 1:
            loginpage();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout<<endl<<"     INVALID CHOICE"<<endl;
            cout<<"     ENTER CHOICE"<<endl;
            cout<<"     ";cin>>ch;
        }
    }
}
void login::loginpageswitch()
{
    while(ch!=1||ch!=2||ch!=3)
    {
        switch(ch)
        {
            case 1:
                ownerlogin();
                break;
            case 2:
                employeelogin();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<endl<<"     INVALID CHOICE"<<endl;
                cout<<"     ENTER CHOICE"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void login::ownerlogin()
{
    while(pass!="admin")
    {
        pass="";
        cout<<endl<<"     ENTER OWNER PASSWORD"<<endl;
        cout<<"     ";c=_getch();
        while(c!=13)
        {
            pass.push_back(c);
            cout<<"*";
            c=getch();
        }
        if(pass=="admin")
         {
             cout<<endl<<"     OWNER ACCESS GRANTED"<<endl;
             cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
             cout<<"     ";getch();
             own();
         }
 else
 {
      try

         {

            throw myexception("YOU HAVE ENTERED INCORRECT PASSWORD............");

         }

              catch (myexception q)

               {

                  q.login_error();

                  return;

               }
 }
    }
}
void login::employeelogin()
{
    while(pass!="employee")
    {
        pass="";
        cout<<"     ENTER EMPLOYEE PASSWORD"<<endl;
        cout<<"     ";c=_getch();
        while(c!=13)
        {
            pass.push_back(c);
            cout<<"*";
            c=getch();
        }
        if(pass=="employee")
        {
            cout<<endl<<"     EMPLOYEE ACCESS GRANTED"<<endl;
            cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
            cout<<"     ";getch();
            emp();
        }
        else
        {
            try
         {
            throw myexception("YOU HAVE ENTERED INCORRECT PASSWORD............");
        }
           catch (myexception q)
           {
               q.login_error();
               return;

            }
        }
    }
}
void login::emp()
{
    store s;
    s.storepage();
}
void login::own()
{
    employee e;
    e.emppage();
}


void handlecust()
{
    order o;
    o.orderpage();
}

void empjump()
{
    employee e;
    e.emppage();
}
int main()
{
  cout<<"\n\t  ========================  SOCIETY MANAGEMENT SYSTEM ========================  "<<endl;
cout<<"\n\t ========================  LOGIN PAGE  ========================  "<<endl<<endl;
login l;
 l.homepage();
return 0;
}
