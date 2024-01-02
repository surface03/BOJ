#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1e18;
int n,m,idx[1000000],K;
LL d[2600010];
struct node{
    int s;
    LL cost;
    bool operator<(const node&r)const{
        return cost>r.cost;
    }
};
priority_queue<node> pq;
vector<node> v[2600010];
void build(int now,int s,int e){
    if(s==e){
        idx[s]=now;
        return;
    }
    int nl=2*now,nr=2*now+1,m=(s+e)/2;
    build(nl,s,m);
    build(nr,m+1,e);
    v[nl].push_back({now,0});
    v[nr].push_back({now,0});
    v[now+4*n].push_back({nl+4*n,0});
    v[now+4*n].push_back({nr+4*n,0});
}
void query(int now,int s,int e,int qs,int qe,int dnode){
    if(e<qs||qe<s)return;
    if(qs<=s&&e<=qe){
        v[now].push_back({dnode,0});
        return;
    }
    int nl=2*now,nr=2*now+1,m=(s+e)/2;
    query(nl,s,m,qs,qe,dnode);
    query(nr,m+1,e,qs,qe,dnode);
}
void query2(int now,int s,int e,int qs,int qe,int dnode){
    if(e<qs||qe<s)return;
    if(qs<=s&&e<=qe){
        v[dnode].push_back({now+4*n,0});
        return;
    }
    int nl=2*now,nr=2*now+1,m=(s+e)/2;
    query2(nl,s,m,qs,qe,dnode);
    query2(nr,m+1,e,qs,qe,dnode);
}
int main(){
    scanf("%d %d %d",&n,&m,&K);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        LL A;
        int B,C,D,E;
        scanf("%lld %d %d %d %d",&A,&B,&C,&D,&E);
        query(1,1,n,B,C,8*n+2*i);
        query2(1,1,n,D,E,8*n+2*i+1);
        v[8*n+2*i].push_back({8*n+2*i+1,A});
    }
    for(int i=1;i<=n;i++){
        v[idx[i]+4*n].push_back({idx[i],0});
    }
    for(int i=0;i<2600010;i++)d[i]=INF;
    d[idx[K]]=0;
    pq.push({idx[K],0});
    while(!pq.empty()){
        node t=pq.top();
        pq.pop();
        if(d[t.s]<t.cost)continue;
        d[t.s]=t.cost;
        for(node i:v[t.s]){
            if(d[i.s]>d[t.s]+i.cost){
                d[i.s]=d[t.s]+i.cost;
                pq.push({i.s,d[i.s]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[idx[i]]!=INF)printf("%lld ",d[idx[i]]);
        else printf("-1 ");
    }
}
