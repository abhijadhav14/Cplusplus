#include <iostream>
#include<stdio.h>

using namespace std;

class stk{
    int a[10];

    public:

    int top;



   void init()
   {
       top=-1;
   }

   void push(int x)
   {
       a[++top]=x;
   }

   void pop()
   {
       top--;
   }

   void peek()
   {
       printf("%d\n",a[top]);
   }

};


int main()
{
    class stk s;
    s.init();
    s.push(39);
    s.peek();
    s.push(10);
    s.peek();
    s.push(17);

    s.push(5);
    s.pop();
    s.peek();
    s.top=-1;
    return 0;
}
