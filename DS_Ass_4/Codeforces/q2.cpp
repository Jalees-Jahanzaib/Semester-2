#include<bits/stdc++.h>
using namespace std;
#define intl long long int
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    intl q;
    cin>>q;
    while(q--){
        intl n,i,j,k;
        cin>>n>>k;
        vector<intl> arr(n);
        intl tot=0;
        for(i=0;i<n;i++){
            cin>>arr[i];
            tot+=arr[i];
        }
            vector<int> ar(n);
            j=0;
            for(i=0;i<n;i++){
                if(arr[i]%2!=0){
                    // j++;
                    ar[j++]=i+1;
                }
            }
           if(j<k)
           cout<<"NO\n";
           else{
               if(j%2==0 && k%2!=0)
               cout<<"NO\n";
               else if(j%2!=0 && k%2==0)
               cout<<"NO\n";
               else{
                   cout<<"YES\n";
                   for(i=j-k;i<j-1;i++)
                   cout<<ar[i]<<" ";
                   cout<<n;
                   cout<<"\n";
               }
        }
    }
}