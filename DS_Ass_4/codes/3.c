#include<stdio.h>
extern int fun(int n);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d ",fun(n) );
}