#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,n) for(ll i=0; i<n; i++)
#define inf INT_MAX
#define pi pair<ll ,ll>
void dks(arr,x){
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    pq.push_back(make_pair(0,x));
    while(!pq.empty()){
        pi temp=pq.top();
        pq.pop();
        if(visit[temp.second]==1)
        continue;
        visit[temp.second]=1;
        for(auto it=ar[temp.second].begin();it!=r[temp.second].end();it++){
            if(visit[*it].first==1)
            continue;
            if()

        }
    }
}
int main(){

ll n;
cin>>n;
cin>>x;

    vector<list<pair<ll,ll> > > arr(n+1);
    FOR(0,x){
      arr[a].push_back(make_pair(b,c));
      dks(arr,x);  
    }

}