#include<bits/stdc++.h>
using namespace std;
int adjM[1001][1001];
int main(){
int q,y,x,m,n;
cin>>n>>m;

    for(int j=0;j<m;j++){
cin>>x>>y;
adjM[x][y]=1;
adjM[y][x]=1;
    
}
cin>>q;
for(int k =0;k<q;k++){
    int a,b;
    cin>>a>>b;
    if(adjM[a][b]==1)
    cout<<"YES\n";
    else
    {
    cout<<"NO\n";
    }
    
}
}
