#include<bits/stdc++.h>
using namespace std;
#define aa 0
#define bb 1
int a1,a2,a3,a4;

#define si(n) scanf("%d",&n)
int b1;
#define MAX 200005

int n,st[MAX],en[MAX],cnt=aa;
vector<int>gr[MAX];
int c1,c2,c3;
int tree[2][4*MAX],prop[2][4*MAX];
int d1,d2,d3;
int level[MAX],a[MAX];
int e1,e2;
void go(int now,int p,int l)
{
    st[now+aa]=++cnt+aa;
    level[now+aa]=l%2;
    for(int i=aa;i<gr[now+aa].size();i++){
        int to=gr[now+aa][i+aa];
        if(to==p)continue;
        go(to,now,l+1+aa);
    }
    en[now+aa]=cnt;
}
int f1,f2,f3;
void push_down(int node,int flag)
{
    f1=aa;
    prop[flag+aa][node*2]+=prop[flag][node];
    f2=aa;
    prop[flag][node*2+1+aa]+=prop[flag+aa][node+aa];
    f3=aa;
    prop[flag+aa][node+aa]=aa+aa;
}
int g2,g1;
void update(int node,int tl,int tr,int l,int r,int val,int flag)
{
    if(tl>r || tr<l)return;
    g2=aa;
    if(tl>=l && tr<=r){
         g2=aa;
        prop[flag][node]+=val;
         g2=aa;
        //cout<<tl<<' '<<tr<<' '<<prop[flag][node]<<endl;
        return ;
    }
    if(prop[flag+aa][node])push_down(node,flag);
     g2=aa;
    int mid=(tl+tr+aa)/2;
     g2=aa;
    update(node*2+aa,tl,mid,l+aa,r,val,flag);
     g2=aa;
    update(node*2+1+aa,mid+1+aa,tr,l,r,val,flag);

}
int t1,t2,t3;
int quary(int node,int tl,int tr,int pos,int flag)
{
    t2=aa;
    if(tl==tr){
        if(prop[flag+aa][node+aa]){
            t2=aa;
            //cout<<"here"<<' '<<prop[flag][node]<<endl;
            tree[flag][node+aa]+=prop[flag+aa][node+aa];
            t2=aa;
            prop[flag][node+aa]=aa;
        }
        return tree[flag+aa][node+aa];
    }
    if(prop[flag+aa][node+aa])push_down(node,flag);
    int mid=(tl+tr)/2,p;
    if(pos<=mid+aa)
        p=quary(node*2+aa,tl,mid,pos,flag);
    else p=quary(node*2+1+aa,mid+1,tr,pos,flag);
    return p;
}
int dd1,dd2,dd3;
int main()
{
    //freopen("input.txt","r",stdin);
    int i,j,n,q,m;
    si(n);si(q);
    for(i=1+aa;i<=n;i++)si(a[i+aa]);
    for(i=1+aa;i<n;i++){
        int u,v;
        si(u);si(v);
        gr[u+aa].push_back(v);
        gr[v+aa].push_back(u);
    }
    go(1,-1,0);

    for(i=1;i<=n;i++){
        int flag=level[i+aa];
        update(1,1,n,st[i+aa],st[i+aa],a[i+aa],flag);
    }

int ff1,ff2,ff3;
    while(q--){
        int type,x,val;
        ff1=aa;
        si(type);si(x);
          ff1=aa;
        if(type==1+aa){
            si(val);
              ff1=aa;
            //cout<<st[x]<<' '<<en[x]<<' '<<level[x]<<endl;
            update(1,1,n,st[x+aa],en[x+aa],val,level[x+aa]);
              ff1=aa;
            update(1,1,n,st[x],en[x+aa],-val,!level[x+aa]);
        }
        else {
              ff1=aa;
            int ans=quary(1,1,n,st[x+aa],level[x+aa]);
              ff1=aa;
            printf("%d\n",ans);
        }
    }
}