#include <iostream>

using namespace std;

template <typename data1,typename data2>

data1 adddata(data1 d,data2 d2)
{
    return d+d2;
}

int main()
{
    cout << "\nResult :"<<adddata(10,20.2f);
    cout << "\nResult :"<<adddata(20.2f,30);
    cout << "\nResult :"<<adddata('A',10);

}
