#include <bits/stdc++.h>

using namespace std;

class item{
    int itemID;
    string itemName;
    date DOM;
    date DOE;

public:
    float price;
    int check;

    item(){}


    item(int itemID, string itemName, date DOM, date DOE, float price)
    {
        this->itemID=itemID;
        this->itemName=itemName;
        this->DOM=DOM;
        this->DOE=DOE;
        this->price=price;
        check=0;
    }
    void printItem()
    {
        cout<<"\tItem ID: "<<itemID;
        cout<<"\tItem Name: "<<itemName;
        cout<<"\tDOM: ";
        DOM.printDate();
        cout<<"\tDOE: ";
        DOE.printDate();
        cout<<"\tPrice: "<<price<<endl;
    }
};



class food: public item
{
public:
    food(int itemID, string itemName, date DOM, date DOE, float price): item(itemID, itemName, DOM, DOE, price)
    {

    }

    void caltax()
    {
        price+=0.18*price;
    }

    void printFood()
    {
        cout<<"\n\nFood Item Details:\n";
        item::printItem();
        cout<<"\nCost after 18% tax:\t"<<price<<"\n";
    }

};


class packed: public food
{
public:
    packed(int itemID, string itemName, date DOM, date DOE, float price): food(itemID, itemName, DOM, DOE, price)
    {

    }

    void caltax()
    {
        food::caltax();
        price+=0.02*price;
    }

    void printPacked()
    {
        food::printFood();
        cout<<"\nPrice after 2% packing charges:\t"<<price;
    }

};

class unpacked: public food
{
public:
    unpacked(int itemID, string itemName, date DOM, date DOE, float price): food(itemID, itemName, DOM, DOE, price)
    {

    }

    void caltax()
    {
        food::caltax();
        price+=2;
    }

    void printPacked()
    {
        food::printFood();
        cout<<"\nPrice after unpacked food charges:\t"<<price;
    }

};

class detergent: public item
{
public:
    detergent(int itemID, string itemName, date DOM, date DOE, float price): item(itemID, itemName, DOM, DOE, price)
    {

    }

    void caltax()
    {
        price+=0.22*price;
    }

    void printFood()
    {
        cout<<"\n\nDetergent Item Details:\n";
        item::printItem();
        cout<<"\nCost after 22% tax:\t"<<price<<"\n";
    }


};

class glass: public item
{
public:

    glass(int itemID, string itemName, date DOM, date DOE, float price): item(itemID, itemName, DOM, DOE, price)
    {

    }

    void caltax()
    {
        price+=0.2*price;
    }

    void printFood()
    {
        cout<<"\n\nGlass Item Details:\n";
        item::printItem();
        cout<<"\nCost after 20% tax:\t"<<price<<"\n";
    }


};

class customer{
    int custID;
    string custName;
    item items[10];


public:
    static int countItem;
    void getCust()
    {
        cout<<"\nEnter Customer ID:\t";
        cin>>custID;
        cout<<"\nEnter Customer Name:\t";
        cin>>custName;
    }

    int count=0;
    float sump=0;
    void choice(item  it[],customer c[],int chc)
    {
        count=0;
        sump=0;
        int ch;
        while(1)
        {
            cout<<"\nEnter the choice of items you want to buy.\n\n";
            for(int i=0;i<10;i++)
                {
                    cout<<"\n"<<i+1<<".";
                    it[i].printItem();
                }
            cout<<"\n11.\tEXIT\n";
            cout<<"\nEnter your choice: ";
            cin>>ch;

            if(ch==11)
            {
                c[chc-1].printCust();
                printDet();
                cout<<"\nTHANK-YOU!\nPLEASE VISIT AGAIN.\n";
                return;
            }

            if(ch>=1 && ch<=10)
            {
                sump+=it[ch-1].price;
                count++;
                countItem++;
                it[ch-1].check++;

                    items[count-1]=it[ch-1];
                    cout<<"\nItem selected successfully.\n";

            }

            else
                cout<<"\nWrong Choice!\n";
        }
    }

    void printDet()
    {
        cout<<"\n\nItems Selected:\n\n";
        for(int i=0;i<count;i++)
            items[i].printItem();
        cout<<"\nTotal Price:\t"<<sump;
    }

    void printCust()
    {
        cout<<"\nCustomer ID:\t"<<custID;
        cout<<"\nCustomer Name:\t"<<custName;
    }

};
int customer::countItem=0;

class gold: public customer
{
public:
    float disc;
    gold()
    {
        customer::getCust();
    }
    void discount()
    {
        disc=0.1*sump;
        sump-=disc;
    }

    void printGold()
    {
        customer::printCust();
        customer::printDet();
        cout<<"\nDiscount=\t"<<disc;
        cout<<"\nDiscounted Price=\t"<<sump;
    }

};

class silver: public customer
{
public:
    float disc;
    silver()
    {
        customer::getCust();
    }
    void discount()
    {
        disc=0.05*sump;
        sump-=disc;
    }

    void printSilver()
    {
        customer::printCust();
        //customer::printDet();
        cout<<"\nDiscount=\t"<<disc;
        cout<<"\nDiscounted Price=\t"<<sump;
    }

};

class platinum: public customer
{
public:
    int rp=0;
    float disc;
    platinum()
    {
        cout<<"\nGive Platinum Customer Details.\n";
        customer::getCust();
    }
    void discount()
    {
        disc=0.15*sump;
        sump-=disc;
    }

    void reward()
    {
        rp+=(int)sump/100;
    }

    void printPlatinum()
    {
        customer::printCust();
        customer::printDet();
        cout<<"\nDiscount=\t"<<disc;
        cout<<"\nDiscounted Price=\t"<<sump;
        cout<<"\nReward Points=\t"<<rp;
    }

};

class shop{
    int shopID;
    string shopName;
    item items[10];
    customer c[5];

public:
    void getShop(item it[])
    {
        cout<<"\nEnter Shop ID:\t";
        cin>>shopID;
        cout<<"\nEnter Shop Name:\t";
        cin>>shopName;
        for(int i=0;i<10;i++)
            items[i]=it[i];

    }
    void printShop()
    {
        cout<<"\nShop ID:\t"<<shopID;
        cout<<"\nShop Name:\t"<<shopName;
        for(int i=0;i<10;i++)
            items[i].printItem();
        for(int i=0;i<5;i++)
            c[i].printCust();
    }
};



int main()
{
    item it[10];
    int id;
    string name;
    date DOM[10], DOE[10];
    float price;
    float ac=0;

    shop s;

    DOM[0]=date(5,3,2001);
    DOM[1]=date(12,11,2005);
    DOM[2]=date(15,5,2010);
    DOM[3]=date(10,4,2020);
    DOM[4]=date(20,11,2011);
    DOM[5]=date(11,10,2021);
    DOM[6]=date(19,5,2003);
    DOM[7]=date(30,7,2009);
    DOM[8]=date(29,9,2008);
    DOM[9]=date(25,1,2007);

    DOE[0]=date(5,3,2004);
    DOE[1]=date(12,11,2009);
    DOE[2]=date(15,5,2011);
    DOE[3]=date(10,4,2022);
    DOE[4]=date(20,11,2013);
    DOE[5]=date(11,10,2024);
    DOE[6]=date(19,5,2006);
    DOE[7]=date(30,7,2010);
    DOE[8]=date(29,9,2010);
    DOE[9]=date(25,1,2011);

    it[0]=item(000,"ABC",DOM[0],DOE[0],150);
    it[1]=item(111,"HUB",DOM[1],DOE[1],250);
    it[2]=item(222,"HHJ",DOM[2],DOE[2],80);
    it[3]=item(333,"ONU",DOM[3],DOE[3],100);;
    it[4]=item(444,"AUB",DOM[4],DOE[4],50);
    it[5]=item(555,"YHD",DOM[5],DOE[5],200);
    it[6]=item(666,"IJE",DOM[6],DOE[6],180);
    it[7]=item(777,"ATM",DOM[7],DOE[7],130);
    it[8]=item(888,"TCF",DOM[8],DOE[8],120);
    it[9]=item(999,"XYZ",DOM[9],DOE[9],110);


    s.getShop(it);
    customer c[5];
    for(int i=0;i<5;i++)
    {
        cout<<"\nEnter details of customer "<<i+1<<":\n";
        c[i].getCust();
    }

    platinum p;
    p.choice(it,c,0);
    p.discount();
    p.reward();
    p.printPlatinum();

    for(int i=0;i<5;i++)
    {
        cout<<"\n\nShop for customer "<<i+1<<":\n\n";
        c[i].choice(it,c,i+1);
        ac+=c[i].sump;
    }


    cout<<"\nTotal no. of items sold in the shop:\t"<<customer::countItem;
    cout<<"\nTotal amount collected by the shop for 5 customers:\t"<<ac;




    return 0;
}
