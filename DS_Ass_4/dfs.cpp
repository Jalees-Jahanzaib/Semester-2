#include <bits/stdc++.h>
using namespace std;
int arr[10000];
stack<int> stck;
void dfs(vector<list<int>> &ar1, int i){
 if(arr[i]!=0)
  return;
 arr[i]++;
 list<int>::iterator it;
 for(it=ar1[i].begin();it!=ar1[i].end();it++){
  dfs(ar1,*it);
 }
 stck.push(i);
}
int main(){
 itn();
int a,b,c,n,m,v,u;
cin>>n>>m;
vector<list<int> > ar1(n+1);
vector<list<int> > ar2(n+1);
colour[1]=0;
for(int i=0;i<m;i++){
 cin>>u>>v;
 ar1[u].push_back(v);
 //colour[v]=!colour[u];
}
//for(int j=1;j<n;j++){
 //dfs(ar1,j);
//}
 list<int>::iterator it1;
for(int i=1;i<=n;i++){
 for(it1=ar1[i].begin();it1!=ar1[i].end();it1++)
  cout<<*it1<<" ";
 cout<<"\n";
}
}
}
