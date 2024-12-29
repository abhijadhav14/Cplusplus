#include <iostream>

#include<exception>


using namespace std;

class date
{
    int dd, mm, yyyy;
public:

    date()
     {

     }
    date(int dd, int mm, int yyyy)

    {

        this->dd = dd;

        this->mm = mm;

        this->yyyy = yyyy;

    }



    void printDate()

    {
        cout << dd << "/" << mm << "/" << yyyy << endl;
    }

};



class medicine

{

    int medID;

    string medName;

    date DOM;

    date DOE;



public:

    float price;

    int check;



    medicine() {}

    medicine(int medID, string medName, date DOM, date DOE, float price)

    {

        this->medID = medID;

        this->medName = medName;

        this->DOM = DOM;

        this->DOE = DOE;

        this->price = price;

        check = 0;

    }



    void getMedicine() //print medicine details

    {

        cout << "\t\tMedicine ID: " << medID;

        cout << "\t\tMedicine Name: " << medName;

        cout << "\t\tDOM: ";

        DOM.printDate();

        cout << "\t\tDOE: ";

        DOE.printDate();

    }

};



class general : public medicine

{

    float tax = 0.25;



public:

    general(int medID, string medName, date DOM, date DOE, float price) : medicine(medID, medName, DOM, DOE, price)

    {

    }

    void calTax()

    {

        price = price + (tax * price);

    }

    void getGeneral()

    {

        getMedicine();

        cout << "\t\tPrice: " << price << endl;

    }

};



class critical : public medicine

{

    float tax = 0.20;



public:

    critical(int medID, string medName, date DOM, date DOE, float price) : medicine(medID, medName, DOM, DOE, price)

    {

    }

    void calTax()

    {

        price = price + (tax * price);

    }

    void getCritical()

    {

        getMedicine();

        cout << "\t\tPrice: " << price << endl;

    }

};



class lifelong : public medicine

{

    float tax = 0.10;



public:

    lifelong(int medID, string medName, date DOM, date DOE, float price) : medicine(medID, medName, DOM, DOE, price)

    {

    }

    void calTax()

    {

        price = price + (tax * price);

    }

    void getLifelong()

    {

        getMedicine();

        cout << "\t\tPrice: " << price << endl;

    }

};



class pediatric : public general

{

    float tax = 0.03;



public:

    pediatric(int medID, string medName, date DOM, date DOE, float price) : general(medID, medName, DOM, DOE, price)

    {

    }

    void calTax()

    {

        price = price + (tax * price);

    }

    void getPediatric()

    {

        getMedicine();

        cout << "\t\tPrice: " << price << endl;

    }

};



class nonPediatric : public general

{

    float tax = 20;



public:

    nonPediatric(int medID, string medName, date DOM, date DOE, float price) : general(medID, medName, DOM, DOE, price)

    {

    }

    void calTax()

    {

        price = price + (tax * price);

    }

    void getnonPediatric()

    {

        getMedicine();

        cout << "\t\tPrice: " << price << endl;

    }

};



class customer

{

    int custID;

    string custName;



public:

    medicine med[10]; //medicine array for the medicines purchased by customer

    customer()

    {

    }

    customer(int custID, string custName)

    {

        this->custID = custID;

        this->custName = custName;

    }



    static int count;

    float totalP = 0;

    void choice(medicine m[], customer c[], int custNo)

    {

        int ch;

        while (1)

        {

            cout << "\n\tSelect the medicines you want to buy" << endl;

            for (int i = 0; i < 10; i++) //To display medicine list

            {

                cout << "\n"

                     << i + 1 << ".";

                m[i].getMedicine();

            }

            cout << "\n11. EXIT" << endl;

            cout << "\nEnter your choice: ";

            cin >> ch;



            if (ch == 11)

            {

                c[custNo - 1].getCust();

                printDet(custNo);

                cout << "\n\t\t----------THANK YOU----------" << endl;

                return;

            }



            if (ch >= 1 && ch <= 10)

            {

                totalP = totalP + m[ch - 1].price;

                count++;

                m[ch - 1].check++; //Mark as selected

                if (m[ch - 1].check > 1)

                {

                    totalP = totalP - m[ch - 1].price;

                    count--;

                    m[ch - 1].check--;

                    cout << "This medicine is already selected" << endl;

                }

                else

                {

                    med[count - 1] = m[ch - 1];

                    cout << "Medicines selected successfully." << endl;

                }

            }

            else

                cout << "Wrong Choice!" << endl;

        }

    }



    void printDet(int custNo)

    {

        cout << "\n---------- Medicines Selected ----------\n\n";

        for (int i = 0; i < count; i++)

            med[i].getMedicine();

        if (custNo == 0 || custNo == 1)

        {

            totalP = totalP - (0.05 * totalP);

            cout << "Bill for insured customer:\t" << totalP << endl;

        }

        else if (custNo == 2 || custNo == 3)

        {

            totalP = totalP - (0.10 * totalP);

            cout << "Bill for prevelaged customer:\t" << totalP << endl;

        }

        else

        {

            totalP = totalP - (0.20 * totalP);

            cout << "Bill for underPrevelaged customer:\t" << totalP << endl;

        }

        cout << "Total items Purchased: " << count;

    }



    void getCust()

    {

        cout << "\nCustomer ID   :\t" << custID << endl;

        cout << "\nCustomer Name :\t" << custName << endl;

    }

};



int customer::count;



class insured : public customer

{

public:

    float discount = 0.05;

    insured(int custID, string custName) : customer(custID, custName)

    {

    }

    void choice(medicine m[], customer c[], int custNo)

    {

        int ch;

        while (1)

        {

            cout << "\n\tSelect the medicines you want to buy" << endl;

            for (int i = 0; i < 10; i++) //To display medicine list

            {

                cout << "\n"

                     << i + 1 << ".";

                m[i].getMedicine();

            }

            cout << "\n11. EXIT" << endl;

            cout << "\nEnter your choice: ";

            cin >> ch;



            if (ch == 11)

            {

                c[custNo - 1].getCust();

                printDet();

                cout << "\n\t\t----------THANK YOU----------" << endl;

                return;

            }



            if (ch >= 1 && ch <= 10)

            {

                totalP = totalP + m[ch - 1].price;

                count++;

                m[ch - 1].check++; //Mark as selected

                if (m[ch - 1].check > 1)

                {

                    totalP = totalP - m[ch - 1].price;

                    count--;

                    m[ch - 1].check--;

                    cout << "This medicine is already selected" << endl;

                }

                else

                {

                    med[count - 1] = m[ch - 1];

                    cout << "Medicines selected successfully." << endl;

                }

            }

            else

                cout << "Wrong Choice!" << endl;

        }

        cout << "Total items Purchased: " << count;

    }

    void printDet()

    {

        cout << "\n---------- Medicines Selected ----------\n\n";

        for (int i = 0; i < count; i++)

            med[i].getMedicine();

        totalP = totalP - (discount * totalP);

        cout << "Bill for insured customer:\t" << totalP;

    }

};



class prevelaged : public customer

{

public:

    float discount = 0.10;

    prevelaged(int custID, string custName) : customer(custID, custName)

    {

    }

    void choice(medicine m[], customer c[], int custNo)

    {

        int ch;

        while (1)

        {

            cout << "\n\tSelect the medicines you want to buy" << endl;

            for (int i = 0; i < 10; i++) //To display medicine list

            {

                cout << "\n"

                     << i + 1 << ".";

                m[i].getMedicine();

            }

            cout << "\n11. EXIT" << endl;

            cout << "\nEnter your choice: ";

            cin >> ch;



            if (ch == 11)

            {

                c[custNo - 1].getCust();

                printDet();

                cout << "\n\t\t----------THANK YOU----------" << endl;

                return;

            }



            if (ch >= 1 && ch <= 10)

            {

                totalP = totalP + m[ch - 1].price;

                count++;

                m[ch - 1].check++; //Mark as selected

                if (m[ch - 1].check > 1)

                {

                    totalP = totalP - m[ch - 1].price;

                    count--;

                    m[ch - 1].check--;

                    cout << "This medicine is already selected" << endl;

                }

                else

                {

                    med[count - 1] = m[ch - 1];

                    cout << "Medicines selected successfully." << endl;

                }

            }

            else

                cout << "Wrong Choice!" << endl;

        }

        cout << "Total items Purchased: " << count;

    }

    void printDet()

    {

        cout << "\n---------- Medicines Selected ----------\n\n";

        for (int i = 0; i < count; i++)

            med[i].getMedicine();

        totalP = totalP - (discount * totalP);

        cout << "Bill for privelaged customer:\t" << totalP;

    }

};



class underPrevelaged : public customer

{

public:

    float discount = 0.10;

    underPrevelaged(int custID, string custName) : customer(custID, custName)

    {

    }

    void choice(medicine m[], customer c[], int custNo)

    {

        int ch;

        while (1)

        {

            cout << "\n\tSelect the medicines you want to buy" << endl;

            for (int i = 0; i < 10; i++) //To display medicine list

            {

                cout << "\n"

                     << i + 1 << ".";

                m[i].getMedicine();

            }

            cout << "\n11. EXIT" << endl;

            cout << "\nEnter your choice: ";

            cin >> ch;



            if (ch == 11)

            {

                c[custNo - 1].getCust();

                printDet();

                cout << "\n\t\t----------THANK YOU----------" << endl;

                return;

            }



            if (ch >= 1 && ch <= 10)

            {

                totalP = totalP + m[ch - 1].price;

                count++;

                m[ch - 1].check++; //Mark as selected

                if (m[ch - 1].check > 1)

                {

                    totalP = totalP - m[ch - 1].price;

                    count--;

                    m[ch - 1].check--;

                    cout << "This medicine is already selected" << endl;

                }

                else

                {

                    med[count - 1] = m[ch - 1];

                    cout << "Medicines selected successfully." << endl;

                }

            }

            else

                cout << "Wrong Choice!" << endl;

        }

        cout << "Total items Purchased: " << count;

    }

    void printDet()

    {

        cout << "\n---------- Medicines Selected ----------\n\n";

        for (int i = 0; i < count; i++)

            med[i].getMedicine();

        totalP = totalP - (discount * totalP);

        cout << "Bill for under prevelaged customer:\t" << totalP;

    }

};



class shop

{

    int shopID;

    string shopName;

    medicine med[10];

    customer cust[5];



public:

    void putShop(medicine m[])

    {

        cout << "Enter Shop ID  :\t";

        cin >> shopID;

        cout << "Enter Shop Name:\t";

        cin >> shopName;

        for (int i = 0; i < 10; i++)

            med[i] = m[i]; //Transfer all medicines to shop

    }

    void getShop()

    {

        cout << "Shop ID" << shopID << endl;

        cout << "Shop Name" << shopName << endl;

        for (int i = 0; i < 10; i++)

            med[i].getMedicine();

        for (int i = 0; i < 5; i++)

            cust[i].getCust();

    }

};



int main()

{

    date DOM[10], DOE[10];

    medicine m[10];

    customer c[5];

    shop s;



    DOM[0] = date(5, 3, 2001);

    DOM[1] = date(12, 11, 2005);

    DOM[2] = date(15, 5, 2010);

    DOM[3] = date(10, 4, 2020);

    DOM[4] = date(20, 11, 2011);

    DOM[5] = date(11, 10, 2021);

    DOM[6] = date(19, 5, 2003);

    DOM[7] = date(30, 7, 2009);

    DOM[8] = date(29, 9, 2008);

    DOM[9] = date(25, 1, 2007);



    DOE[0] = date(5, 3, 2004);

    DOE[1] = date(12, 11, 2009);

    DOE[2] = date(15, 5, 2011);

    DOE[3] = date(10, 4, 2022);

    DOE[4] = date(20, 11, 2013);

    DOE[5] = date(11, 10, 2024);

    DOE[6] = date(19, 5, 2006);

    DOE[7] = date(30, 7, 2010);

    DOE[8] = date(29, 9, 2010);

    DOE[9] = date(25, 1, 2011);



    m[0] = pediatric(000, "ABC", DOM[0], DOE[0], 150);

    m[1] = pediatric(111, "DEF", DOM[1], DOE[1], 250);

    m[2] = nonPediatric(222, "GHI", DOM[2], DOE[2], 80);

    m[3] = nonPediatric(333, "HJK", DOM[3], DOE[3], 100);

    m[4] = critical(444, "ZXC", DOM[4], DOE[4], 50);

    m[5] = critical(555, "KLJ", DOM[5], DOE[5], 200);

    m[6] = critical(666, "LOA", DOM[6], DOE[6], 180);

    m[7] = lifelong(777, "PLA", DOM[7], DOE[7], 130);

    m[8] = lifelong(888, "FNM", DOM[8], DOE[8], 120);

    m[9] = lifelong(999, "ZAQ", DOM[9], DOE[9], 110);



    s.putShop(m);



    c[0] = insured(10, "Yash");

    c[1] = insured(11, "Raj");

    c[2] = prevelaged(12, "Raja");

    c[3] = prevelaged(13, "Rahul");

    c[4] = underPrevelaged(14, "Kumar");



    int custNo;

    cout << "\nSelect Customer [1,2,3,4,5]:\t";

    cin >> custNo;

    c[custNo - 1].choice(m, c, custNo);

    return 0;

}
