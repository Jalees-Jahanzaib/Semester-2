#include<stdio.h>
extern int isPrime(int n);
int main()
{
    int n;
    scanf("%d",&n);
    if(isPrime(n))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
