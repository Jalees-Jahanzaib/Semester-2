#include<stdio.h>
extern int parityCheck(int n);
int main()
{
    int n;
    scanf("%d",&n);
    if(parityCheck(n))
        printf("odd\n");
    else
        printf("even\n");
    return 0;
}
