#include<stdio.h>
extern int merge(int *arr,int n,int *arr2,int m);
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
   int a[2*n+m];
   int b[m];
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    merge(a,n,b,m);
    for(int i=n;i<2*n+m;i++)
        printf("%d ",a[i]);
    return 0;
}
