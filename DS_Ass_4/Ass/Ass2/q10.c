#include<stdio.h>
#define ll int
extern ll binarysearch(ll *arr,ll n,ll key);
    int main()
{
    ll n;scanf("%d",&n);
    ll arr[n];
    for(ll i=0;i<n;i++)
        scanf("%d",&arr[i]);
    ll key;
    scanf("%d",&key);
    if(binarysearch(&arr[0],n,key)==1)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
