#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)
#define inf INT_MAX
using namespace std;
 
void init (bool *a, int n, bool val)
{
	FOR(i,n)
		a[i]=val;
}
void init (int *a,int n,int val){
    FOR(i,n){
        a[i]=val;
    }
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int t;
        cin>>n;
        int a[n][n];
        int s,e;
        cin>>s>>e;
        if(s==e){
            cout<<"0\n"<<s<<"\n";
            continue;}
   bool *visited=new bool[n];
   init(visited,n,false);
   int *d=new int[n];
   init(d,n,inf);  
   int *prev=new int[n];
   init(prev,n,-1);
   d[s]=0;          
FOR(i,n-1)
    }
}