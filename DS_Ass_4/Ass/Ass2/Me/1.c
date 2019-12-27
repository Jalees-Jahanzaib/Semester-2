#include<stdio.h>
#define ll int
extern  ll sum (ll *a,ll n,ll m);
int main(){
    ll n,m;
    scanf("%d%d",&n,&m);
    ll arr[n][m];
    for(ll i=0;i<n;i++){
         for(ll j=0;i<m;j++)
         scanf("%d",&arr[i][j]);
}
ll a11=sum(&arr[0][0],n,m);
             printf("%d ",a11);
return 0;
}
