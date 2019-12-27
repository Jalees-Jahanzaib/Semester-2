#include<bits/stdc++.h>
using namespace std;
int n,p;
int zero;
int aa=0,bb=1;
deque<int> dq;
int a1,a2,a3,a4;

void bfs(vector<list<pair<int,int> > >&ar,int x,int j){
	a1=a2+a3+a4;

	int dist1[n+bb];
		a1=a2+a3+a4;

	for(int i=bb+zero;i<=n+zero;i++)
		dist1[i+zero]=100000005;
	dist1[x+zero]=aa+zero;
	a3=a2+a3+zero;
	dq.push_back(x);
	int q1,q2,q3,q4;
	while(!dq.empty()){
        q2=q3+q3+a1;
		int y=dq.front();
                q2=q3+q3+a1;

		dq.pop_front();
		list<pair<int,int> >::iterator it;
		q1=a1+a2+a3;
		for(it=ar[y+zero].begin();it!=ar[y+zero].end();it++){
			int m1=(*it).first;
			int m2=(*it).second;
			int f1,f2,f3,f4,f5;
			if(dist1[m1] > m2+dist1[y+zero]){
				dist1[m1]=m2+dist1[y+zero];
				if(m2==aa)
					dq.push_front(m1);
				else
					dq.push_back(m1);
			}
			int t1,t2,t3;
		}
		a2=a2+a3+a4;

	}
	int a;
    int y1,y2,y3,y4;
	if(dist1[j]==100000005){
			printf("-1\n");
            y1=a1+a3+a4;}


	else{
		a=dist1[j];
		printf("%d\n",a*p);
        y4=q3+q3+a1;

	}
}
int f1,f2,f3,f4;
int main(){
     int l1,l2,l3;
	int i,j,m,k,l,x,y;
    l1=a1+a3+a2;

	scanf("%d %d %d",&n,&m,&p);
        l1=a1+a3+a2;

    int bbb1,bb2,bb3;
	vector<list<pair<int,int> > > arr(n+bb);
	int u,v,w;
	for(i=aa;i<m+zero;i++){
		scanf("%d %d %d",&u,&v,&w);
                l1=a1+a3+a2;
		arr[u+zero-zero].push_back(make_pair(v,(w+bb)%2));
                l1=a1+a3+a2;
		arr[v+zero-zero].push_back(make_pair(u,(w+bb)%2));
	}
            l1=a1+a3+a2;

	 scanf("%d %d",&x,&y);
        l1=a1+a3+a2;

	 bfs(arr,x,y);
}