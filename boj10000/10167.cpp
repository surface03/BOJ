#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const LL INF=(LL)1e18;
struct A{
    LL lm,rm,mv,sum;
}st[400000];
struct gold{
    int x,y;
    LL w;
}G[3010];
vector<int>vx,vy;
vector<pair<int,LL>> v[100010];
typedef pair<A,bool> pdb;

void update(int now,int s,int e,int idx,LL val){
    if(s==e){
        st[now].lm+=val;
        st[now].rm+=val;
        st[now].mv+=val;
        st[now].sum+=val;
        return;
    }
    int lch=now*2,rch=lch+1,m=(s+e)/2;
    if(idx<=m)update(lch,s,m,idx,val);
    else update(rch,m+1,e,idx,val);
    st[now].lm=max(st[lch].lm,st[lch].sum+st[rch].lm);
    st[now].rm=max(st[rch].rm,st[rch].sum+st[lch].rm);
    st[now].mv=max({st[lch].mv,st[rch].mv,st[lch].rm+st[rch].lm});
    st[now].sum=st[lch].sum+st[rch].sum;
}
pdb squery(int now,int s,int e,int fs,int fe){
    if(e<fs||fe<s)return {A{-INF,-INF,-INF,0},false};
    if(fs<=s&&e<=fe)return {st[now],true};
    int lch=now*2,rch=lch+1,m=(s+e)/2;
    pdb L=squery(lch,s,m,fs,fe);
    pdb R=squery(rch,m+1,e,fs,fe);
    if(L.se==false){return R;}
    else if(R.se==false){return L;}
    else{
        A t;
        A ll=L.fi;
        A rr=R.fi;
        t.lm=max(ll.lm,ll.sum+rr.lm);
        t.rm=max(rr.rm,rr.sum+ll.rm);
        t.sum=ll.sum+rr.sum;
        t.mv=max({ll.mv,rr.mv,ll.rm+rr.lm});
        return {t,true};
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %lld",&G[i].x,&G[i].y,&G[i].w);
        vx.push_back(G[i].x);
        vy.push_back(G[i].y);
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    vy.erase(unique(vy.begin(),vy.end()),vy.end());
    int sxcnt=vx.size(),sycnt=vy.size();
    for(int i=0;i<n;i++){
        G[i].x=(int)(lower_bound(vx.begin(),vx.end(),G[i].x)-vx.begin())+1;
        G[i].y=(int)(lower_bound(vy.begin(),vy.end(),G[i].y)-vy.begin())+1;
        v[G[i].y].push_back({G[i].x,G[i].w});
    }
    LL ans=0;
    for(int i=1;i<=sycnt;i++){
        for(int j=i;j<=sycnt;j++){
            for(auto&k:v[j]){
                update(1,1,sxcnt,k.fi,k.se);
            }
            ans=max(ans,squery(1,1,sxcnt,1,sxcnt).fi.mv);
        }
        fill(st,st+12010,A{0,0,0,0});
    }
    printf("%lld\n",ans);
}