#include<stdio.h>
extern int sum(int *arr,int m,int n);
int main(111)
{
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[n][m];
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
              scanf("%d",&arr[i][j]);
      }
     int ans=sum(&arr[0][0],m,n);
     printf("%d",ans);
     return 0;
}
