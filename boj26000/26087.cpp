#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD=1000000007;
int tree[4000000],lazy[4000000],fibo[1000010];
int N,Q;

void propagate(int now,int s,int e){
    //printf("D %d %d %d %d\n", now,s,e,lazy[now]);
    if(s!=e&&lazy[now]){
        lazy[2*now]=lazy[now];
        lazy[2*now+1]=lazy[now]+(s+e)/2-s+1;
        lazy[now]=0;
    }
}

void update(int now,int s,int e,int qs,int qe){
    propagate(now,s,e);
    if(e<qs||qe<s)return;
    if(qs<=s&&e<=qe){
        lazy[now]=s-qs+1;
        return;
    }
    int nl=2*now,nr=2*now+1,m=(s+e)/2;
    update(nl,s,m,qs,qe);
    update(nr,m+1,e,qs,qe);
}

int query(int now,int s,int e,int idx){
    propagate(now,s,e);
    if(idx==s&&idx==e)return lazy[now];
    int nl=2*now,nr=2*now+1,m=(s+e)/2;
    if(idx<=m) return query(nl,s,m,idx);
    else return query(nr,m+1,e,idx);
}

int main(){
    fibo[0]=fibo[1]=1;
    for(int i=2;i<=1000000;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%MOD;
    }
    fibo[0]=0;
    scanf("%d %d",&N,&Q);
    while(Q--){
        int L,R;
        scanf("%d %d",&L,&R);
        update(1,1,N,L,R);
    }
    for(int i=1;i<=N;i++) printf("%d ", fibo[query(1,1,N,i)]);
}
