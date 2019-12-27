#include<stdio.h>
extern int fun(int n);
int main(){
int t;
scanf("%d",&t);
int h=fun(t);
printf("%d",h);
return 0;
}