#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define dq(x) dq[(x)+100000]
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

using namespace std;
const int iB=1000;

int n,a[200010];
deque<int> dq[200010];
int arr[200010],b[1200];
ll ans;
int bf(int idx){
    return dq(idx).back()-dq(idx).front();
}
struct dat{
    int frq,req;
    bool operator<(const dat&r)const{
        if(req/iB==r.req/iB)return frq<r.frq;
        return req<r.req;
    }
}p[100010];


void solve(){
    ans=0;
    for(int i=0;i<200010;i++)dq[i].clear();
    memset(arr,0,sizeof arr);
    memset(b,0,sizeof b);
    memset(a,0,sizeof a);
    memset(p,0,sizeof p);

    int M;
    scanf("%lld",&n);
    assert(1<=n && n<=100000);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]=a[i]+a[i-1];
    }
    scanf("%lld",&M);
    assert(1<=M && M<=100000);
    for(int i=0;i<M;i++){
        int aii,bii;
        scanf("%lld %lld",&aii,&bii);
        aii--;
        p[i].frq=aii;
        p[i].req=bii;
    }
    sort(p,p+M);

    int fr=0,re=-1;

    for(int i=0;i<M;i++){
        for(int j=re;j>p[i].req;j--){
            arr[bf(a[j])]--;
            b[bf(a[j])/iB]--;
            dq(a[j]).pop_back();
            if(!dq(a[j]).empty()){
                arr[bf(a[j])]++;
                b[bf(a[j])/iB]++;
            }
        }
        for(int j=fr-1;j>=p[i].frq;j--){
            if(!dq(a[j]).empty()){
                arr[bf(a[j])]--;
                b[bf(a[j])/iB]--;
            }
            dq(a[j]).push_front(j);
            arr[bf(a[j])]++;
            b[bf(a[j])/iB]++;
        }
        for(int j=re+1;j<=p[i].req;j++){
            if(!dq(a[j]).empty()){
                arr[bf(a[j])]--;
                b[bf(a[j])/iB]--;
            }
            dq(a[j]).push_back(j);
            arr[bf(a[j])]++;
            b[bf(a[j])/iB]++;
        }
        for(int j=fr;j<p[i].frq;j++){
            arr[bf(a[j])]--;
            b[bf(a[j])/iB]--;
            dq(a[j]).pop_front();
            if(!dq(a[j]).empty()){
                arr[bf(a[j])]++;
                b[bf(a[j])/iB]++;
            }
        }
        int Ans=0;
        for(int j=599;j>=0;j--){
            if(b[j]){
                for(int k=j*iB;k<(j+1)*iB;k++){
                    if(arr[k]>0)Ans=k;
                }
                break;
            }
        }
        ans+=(ll)Ans;
        fr=p[i].frq;
        re=p[i].req;
    }
    printf("%lld ",ans);
}
signed main(){
    int T;
    scanf("%lld",&T);
    assert(1<=T && T<=1000);
    while(T--){
        solve();
    }
}
