#include <iostream>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<string, int> ump;
	unordered_set<string> uset;
	ll i,j,k,l,n;
	cin>>n;
	for(i=0;i<n;i++){
		string str;
		cin>>str;
		ump[str]++;
	}
	cin>>l;
	for(i=0;i<l;i++){
		string str;
		cin>>str;
		uset=unordered_set<string>(0);
		k=str.length();
		ll x=0;
		ll arr[3];
		for(j=0;j<k;j++){
			if(str[j]=='?'){
				arr[x++]=j;	
			}
		}
		ll sum=0;
		if(x==0){
			cout<<ump[str]<< "\n";
		}
		else if(x==1){
			for(j=0;j<6;j++){
				if(j==5){
					str.erase(arr[0],1);
					//cout<<str<<" z\n";
					sum+=ump[str];
				}
				else{
					str[arr[0]]='a'+j;
					//cout<<str<<" w\n";
					sum+=ump[str];
				}
			}
			cout<< sum << "\n";
		}
		else if(x==2){
			for(j=0;j<6;j++){
				for(ll y=0;y<6;y++){	
					if(j==5){
						string st1=str;
						st1.erase(arr[0],1);
						if(y==5){
							string st=st1;
							st.erase(arr[1]-1,1);
						//	cout<<st<<" v\n";
							if(uset.find(st)==uset.end()){
								uset.insert(st);
								sum+=ump[st];
							}
						}		
						else{
							st1[arr[1]-1]='a'+y;
						//	cout<<st1<<" u\n";
							if(uset.find(st1)==uset.end()){
								uset.insert(st1);
								sum+=ump[st1];
							}
						}
					}	
					else{
						str[arr[0]]='a'+j;
						if(y==5){
							string st=str;
							st.erase(arr[1],1);
						//	cout<<st<<" t\n";
							if(uset.find(st)==uset.end()){
								uset.insert(st);
								sum+=ump[st];
							}
						}
						else{
							str[arr[1]]='a'+y;
						//	cout<<str<<" s\n";
							if(uset.find(str)==uset.end()){
								uset.insert(str);
								sum+=ump[str];
							}
						}
					}
				}
			}
			cout<< sum << "\n";
		}
		else{
			for(ll z=0;z<6;z++){
				for(j=0;j<6;j++){
					for(ll y=0;y<6;y++){
						if(z==5){
							string st2=str;
							st2.erase(arr[0],1);
						//	cout<< "mayank"<<st2<<"\n";
							if(j==5){
								string st1=st2;
								st1.erase(arr[1]-1,1);
								if(y==5){
									string st=st1;
									st.erase(arr[2]-2,1);
						//			cout<<st<<" r\n";
									if(uset.find(st)==uset.end()){
										uset.insert(st);
										sum+=ump[st];
									}
								}
								else{
									st1[arr[2]-2]='a'+y;
						//			cout<<st1<<" q\n";
									if(uset.find(st1)==uset.end()){
										uset.insert(st1);
										sum+=ump[st1];
									}
								}
							}
							else{
								st2[arr[1]-1]='a'+j;
								if(y==5){
									string st=st2;
									st.erase(arr[2]-1,1);
							//		cout<<st<<" p\n";
									if(uset.find(st)==uset.end()){
										uset.insert(st);
										sum+=ump[st];
									}
								}
								else{
									st2[arr[2]-1]='a'+y;
								//	cout<<st2<<" o\n";
									if(uset.find(st2)==uset.end()){
										uset.insert(st2);
										sum+=ump[st2];
									}
								}
							}
						}
						else{
							string st3=str;
							st3[arr[0]]='a'+z;
							if(j==5){
								string st1=st3;
								st1.erase(arr[1],1);
								if(y==5){
									string st=st1;
									st.erase(arr[2]-1,1);
								//	cout<<st<<" n\n";
									if(uset.find(st)==uset.end()){
										uset.insert(st);
										sum+=ump[st];
									}
								}
								else{
									st1[arr[2]-1]='a'+y;
								//	cout<<st1<<" m\n";
									if(uset.find(st1)==uset.end()){
										uset.insert(st1);
										sum+=ump[st1];
									}
								}
							}
							else{
								st3[arr[1]]='a'+j;
								if(y==5){
									string st=st3;
									st.erase(arr[2],1);
								//	cout<<st<<" l\n";
									if(uset.find(st)==uset.end()){
										uset.insert(st);
										sum+=ump[st];
									}
								}
								else{
									st3[arr[2]]='a'+y;
								//	cout<<st3<<" k\n";
									if(uset.find(st3)==uset.end()){
										uset.insert(st3);
										sum+=ump[st3];
									}
								}
							}
						}
					}
				}
			}
			cout<< sum << "\n";
		}
	}
}				

