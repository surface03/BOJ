#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int mod=1000000007;
const int inf=1000000000;
const ll MOD=1000000007ll;
const ll INF=1000000000000000000ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
int randint(int __L,int __R){return uniform_int_distribution<int>(__L,__R)(rng);}
ll randll(ll __L,ll __R){return uniform_int_distribution<ll>(__L,__R)(rng);}
ll ipow(ll _a,ll _b){ll _ret=1;while(_b){if(_b&1) _ret=_ret*_a % MOD;_a=_a*_a % MOD;_b>>=1;}return _ret;}
ll ipowM(ll _a,ll _b,ll _MM){ll _ret=1%_MM;while(_b){if(_b&1) _ret=_ret*_a % _MM;_a=_a*_a % _MM;_b>>=1;}return _ret;}

#ifdef LOCAL
template <typename T1>
void __printdebug(const char* __str__, T1&& arg1){
    int __i__ = 0;
    while(true){
        if(__str__[__i__] == '\0') break;
        if(__str__[__i__] != ' ') cout << __str__[__i__];
        __i__++;
    }
    cout << " = " << arg1 << "\n";
}
template <typename T1, typename... Types>
void __printdebug(const char* __str__, T1&& arg1, Types&&... args){
    int __i__ = 0;
    while(true){
        if(__str__[__i__] == ',') break;
        if(__str__[__i__] != ' ') cout << __str__[__i__];
        __i__++;
    }
    cout << " = " << arg1 << ", ";
    __printdebug(__str__ + __i__ + 1, args...);
}
#define debug(...) cout<<"[DEBUG] ";__printdebug(#__VA_ARGS__, __VA_ARGS__)
#define debugct(a) cout<<"[DEBUG] ";cout<<#a<<" : ";for(auto&__i:(a))cout<<__i<<" ";cout<<"\n"
#define debugarr(a,n) cout<<"[DEBUG] ";cout<<#a<<" : ";for(int __i=0;__i<(n);__i++)cout<<(a)[__i]<<" ";cout<<"\n"

#else

#define debug(...)
#define debugct(a)
#define debugarr(a,n)
#endif






const int iB=1000;
vector<pair<int,int> > bkt[102];
int arr[100010];

struct point{
    ll x,y;
    int fidx;
    bool operator<(const point&r)const{
        if(x==r.x && y==r.y)return fidx<r.fidx;
        else if(x==r.x) return y<r.y;
        else return x<r.x;
    }
};

vector<point> parr;
vector<point> group[100010];
vector<ll> v,vx;
vector<pair<ll,ll>> tmp;
ll K;

int n,tN,chk[100010];

ll a[100010],b[100010],c[100010],d[100010];

int main(){
    scanf("%d %lld",&n,&K);
    for(int i=0;i<n;i++){
        ll tx,ty;
        scanf("%lld %lld",&tx,&ty);
        a[i]=tx-ty;
        b[i]=tx+ty;
        parr.push_back({a[i],b[i],i});
        vx.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(vx.begin(),vx.end());

    sort(parr.begin(),parr.end());

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());

    tN=(int)v.size();



    for(int i=0;i<n;i++){
        arr[i]=(int)(lower_bound(v.begin(),v.end(),parr[i].y)-v.begin());
        bkt[i/iB].push_back({arr[i],i});
    }


    for(int i=0;i<102;i++) sort(bkt[i].begin(),bkt[i].end());

    int vecidx=0;
    for(int i=0;i<n;i++){
        if(chk[i])continue;

        group[vecidx].push_back(parr[i]);
        bkt[i/iB].erase(lower_bound(bkt[i/iB].begin(),bkt[i/iB].end(),pii(arr[i],i)));
        chk[i]=1;
        arr[i]=9999999;

        for(int j=0;j<(int)group[vecidx].size();j++){
            int hh1=(int)(lower_bound(v.begin(),v.end(),group[vecidx][j].y - K)-v.begin());
            int hh2=(int)(upper_bound(v.begin(),v.end(),group[vecidx][j].y + K)-v.begin())-1;
            int LL=(int)(lower_bound(vx.begin(),vx.end(),group[vecidx][j].x - K)-vx.begin());
            int RR=(int)(upper_bound(vx.begin(),vx.end(),group[vecidx][j].x + K)-vx.begin())-1;

            for(int k=LL;k<=RR;){
                int bidx=k/iB;
                if(k%iB==0 && k+iB<RR){
                    int pos1=lower_bound(bkt[bidx].begin(),bkt[bidx].end(),pii(hh1,-1))-bkt[bidx].begin();
                    int pos2=(int)(upper_bound(bkt[bidx].begin(),bkt[bidx].end(),pii(hh2,89898989))-bkt[bidx].begin())-1;
                    if(pos1>pos2){
                        k+=iB;
                        continue;
                    }
                    for(int ii=pos1;ii<=pos2;ii++){
                        group[vecidx].push_back(parr[bkt[bidx][ii].se]);
                        chk[bkt[bidx][ii].se]=1;
                        arr[bkt[bidx][ii].se]=9999999;
                    }
                    bkt[bidx].erase(bkt[bidx].begin()+pos1, bkt[bidx].begin()+(pos2+1));
                }
                else{
                    if(hh1<= arr[k] && arr[k] <= hh2){
                        bkt[bidx].erase(lower_bound(bkt[bidx].begin(),bkt[bidx].end(),pii(arr[k],k)));
                        group[vecidx].push_back(parr[k]);
                        chk[k]=1;
                        arr[k]=9999999;
                    }
                    k++;
                }
            }

        }


        vecidx++;
    }
    int ans=0;
    for(int i=0;i<vecidx;i++)ans=max(ans,(int)group[i].size());
    printf("%d %d\n", vecidx,ans);
}
