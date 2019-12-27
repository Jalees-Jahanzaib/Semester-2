#include<stdio.h>
extern int  fib(int n)
{
   int p1=0,p2=1,third=p1+p2;
   for(int i=1;i<n;i++)
   {
       third=p1+p2;
       p1=p2;
       p2=third;
   }
   return p1;
}
