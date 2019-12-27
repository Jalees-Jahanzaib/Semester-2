#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
while(t--){
int k;
cin>>k;
vector <int> num(k);
for(int i=0;i<k;i++){
cin>>num[i];
}
sort(num.begin(),num.begin()+k);
reverse(num.begin(),num.begin()+k);
int kth;
for(int j=0;j<k-1;j++){
    kth=k-j;
    if(kth-1<=num[0] && kth-1<=num[1]){
    // cout<<kth-2;    
    break;}
    // else if(kth < 0){
    //     cout<<"0";
    // break; 
}
    cout<<kth-2<<"\n";

    }

} 


