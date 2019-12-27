#include<bits/stdc++.h>
using namespace std;
int n,p;
deque<int> dq;
void bfs(vector<list<pair<int,int> > >&ar,int x,int j){
	int dist1[n+1];
	for(int i=1;i<=n;i++)
		dist1[i]=100000005;
	dist1[x]=0;
	dq.push_back(x);
	while(!dq.empty()){
		int y=dq.front();
		dq.pop_front();
		list<pair<int,int> >::iterator it;
		for(it=ar[y].begin();it!=ar[y].end();it++){
			int m1=(*it).first;
			int m2=(*it).second;
			if(dist1[m1] > m2+dist1[y]){
				dist1[m1]=m2+dist1[y];
				if(m2==0)
					dq.push_front(m1);
				else
					dq.push_back(m1);
			}
		}
	}
	int a;
	if(dist1[j]==100000005)
			printf("-1\n");
	else{
		a=dist1[j];
		printf("%d\n",a*p);
	}
}
int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int i,j,m,k,l,x,y;
	scanf("%d %d %d",&n,&m,&p);
	vector<list<pair<int,int> > > arr(n+1);
	int u,v,w;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		arr[u].push_back(make_pair(v,(w+1)%2));
		arr[v].push_back(make_pair(u,(w+1)%2));
	}
	 scanf("%d %d",&x,&y);
	 bfs(arr,x,y);
}