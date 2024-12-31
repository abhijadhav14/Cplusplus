#include <iostream>
#include <new>

using namespace std;

int main()
{
   try
   {
       int* myarray=new int[10000];
   }
   catch(std::bad_alloc&ba)
   {
       std::cerr<<"bad_alloc caught:"<<ba.what()<<'\n';
   }
    return 0;
}
