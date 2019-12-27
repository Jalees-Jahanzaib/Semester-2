#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int t;
cin>>t;
int flag=0;
vector <int> v(t);
for(int i=0;i<t;i++){
    cin>>v[i];
}
for(int i=1;i<t-1;i++){
    if(v[i+1]> v[i] && v[i-1]>v[i] )
    flag=1; 
}
if (flag==1){
    cout<<"NO";
    }
else{
    cout<<"YES";

}}    
