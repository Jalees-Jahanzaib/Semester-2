#include<stdio.h>
extern int sum(int n);
int main()
{
    int n;
    scanf("%d",&n);
    int ans=sum(n);
    printf("%d",ans);
    return 0;
}
