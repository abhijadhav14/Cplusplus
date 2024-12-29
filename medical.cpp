#include<iostream>
using namespace std;
class date
{
    int dd;
    int mm;
    int yyyy;
    public:
    void getdate(int dd,int mm,int yyyy)
    {
        this->dd=dd;
        this->mm=mm;
        this->yyyy=yyyy;
    }
    void printdate()
    {
        cout<<dd<<"/"<<mm<<"/"<<yyyy;
    }
};
class med
{
    int item_id;
    string itme_name;
    date dom;
    date doe;
    float price;
    int mg;
    public:
    med(int id,string name,int ddm,int mmm,int yym,int dde,int mme,int yye,float price,int mg)
    {
        this->item_id = id;
        this->itme_name = name;
        this->price = price;
        this->mg = mg;
        dom.getdate(ddm,mmm,yym);
        doe.getdate(dde,mme,yye);
    }
    void printmed()
    {
        cout<<"\n\nMedicine Id:"<<item_id<<"\nMedicine Name:"<<itme_name<<"\nPrice:"<<price<<"\nMg's:"<<mg;
        cout<<"\nDate of Manufacture:";
        dom.printdate();
        cout<<"\nDate of Expiry:";
        doe.printdate();
    }
    med(){}
    int Mg ()
    {
        return mg;
    }
    int id()
    {
        return item_id;
    }
};
class customer
{
    int cust_id;
    string cust_name;
    med medicines[3];
    public:
    void getcust(int id,string name,med medicine[])
    {
        int counter[3];
        int flag = 0;
        int medicineMgSum = 0;
        this->cust_id=id;
        this->cust_name=name;
        cout<<"\n\nThe available meds are";
        for(int i=0;i<5;i++)
        {
         medicine[i].printmed();
        }
        cout<<"\n\n\n Enter the med id of the medicines :\n";
        for(int i = 0;i<3;i++)
        {
            cin>>counter[i];
            medicineMgSum = medicineMgSum + medicine[counter[i]].Mg();
        }
        if(medicineMgSum<=300)
        {
            flag=1;
        }
        int j = 0;
        if(flag==0)
        {
            cout<<"Sorry wrong choice your medicine dosage cant be more than 300";
            exit(0);
        }
        else
        {
               for(int i =0;i<5;i++)
            {
                if(counter[i]==medicine[i].id())
                {
                    medicines[j]=medicine[i];
                    j++;
                }
            }
        }
    }
    void putcust()
    {
        cout<<"\n customer id: ";
        cout<<cust_id;
        cout<<"\ncustomer name: ";
        cout<<cust_name;
        cout<<"Meds customer has taken are";
        for(int i =0;i<3;i++)
        {
            medicines[i].printmed();
        }
    }
};



class shop
{
    int shop_id;
    string shop_name;
    med medicine[5];
    customer cust[2];
    public:



    void getshop(int id,string name,med medicineDeatils[],customer custDeatials[])
    {
        this->shop_id=id;
        this->shop_name=name;
        for(int i=0;i<5;i++)
        {
            this->medicine[i]=medicineDeatils[i];
        }
        for(int i=0;i<2;i++)
        {
            this->cust[i]=custDeatials[i];
        }
    }
    void printshop()
    {
        cout<<"\nShop Id : "<<shop_id<<"\nShop Name : "<<shop_name;
        cout<<"\nMedicines in the shop : ";
        for(int i=0;i<5;i++)
        {
            medicine[i].printmed();
        }
        cout<<"\nCustomers in the shop\n";
        for(int i=0;i<3;i++)
        {
            cust[i].putcust();
        }
    }
};

class shop1
{
    int shopid;
    string shopname;

public:

     void getsh(int id, string name)
    {
        this->shopid=id;
        this->shopname=name;
    }

    void putsh()
    {
        cout<<"\nShop ID: "<<shopid;
        cout<<"\nShop Name: "<<shopname;
    }
};

int main()
{
    shop1 s;
    s.getsh(1,"MedStop");
    s.putsh();

    shop s1;





    med m1(1,"painkiller",12,12,1900,1,1,2000,100,90),m2(2,"cold",12,12,1900,1,1,2000,400,70),m3(3,"cough",12,12,1900,1,1,2000,500,60),m4(4,"acid",12,12,1900,1,1,2000,600,150),m5(5,"dolo",12,12,1900,1,1,2000,1000,300);
   med m[4];

    m[0]=m1;
    m[1]=m2;
    m[2]=m3;
    m[3]=m4;
    m[4]=m5;
   customer c[2];
 c[0].getcust(1,"Adam",m);
    c[1].getcust(2,"John",m);
    s1.getshop(1,"Medicos",m,c);
    s1.printshop();
    return 0;
}
