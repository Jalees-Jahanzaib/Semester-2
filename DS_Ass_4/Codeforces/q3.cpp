#include<bits/stdc++.h>
using namespace std;
#define intl long long int
struct point{
    intl x;
    intl y;
    intl a;
    intl b;
    intl c;
    intl d;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    intl q;
    cin>>q;
    while(q--){
        intl i,j,n,k;
        intl b,w;
        cin>>b>>w;
        intl max1=max(b,w);
        intl min1=min(b,w);
        if(max1>4*min1)
        cout<<"NO\n";
        else{
            vector<pair<intl> > ar(b+w);
            intl tmp=2e8;
            printf("%lld\n",tmp);
            if(min1==b){
                for(i=0;i<b;i++){
                    ar[i].first=tmp+2*i;
                    ar[i].second=tmp+1;
                }
                for(i=b;i<w+b;i++){
                    ar[i].first=tmp+1
                }
            }
        }
    }
}