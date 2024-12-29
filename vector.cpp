#include <iostream>
#include<stdexcept>
#include<vector>

using namespace std;

int main(void)
{
   std::vector<int>myvector(10);
   try
   {
       myvector.at(17)=100;
   }

   catch(const std::out_of_range&oor)
   {
       std::cerr<<"Out of Range error:"<<oor.what()<<'\n';
   }

    return 0;
}


class vector
{
int i;
string name;

public:
    vector(int i, string name)
    {
        this->i=i;
        this->name=name;
    }


};
