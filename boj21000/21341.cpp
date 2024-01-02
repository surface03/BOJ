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




set<pii> s;

int n,ax,ay,bx,by;
bool go(int x,int y,int xx,int yy){
	if(make_pair(x,y) == make_pair(xx,yy))return true;
	for(auto i:s){
		if(make_pair(x+i.fi,y+i.se) == make_pair(xx,yy))return true;

		if((x+i.fi)<=0 || (x+i.fi)>n || (y+i.se)<=0 || (y+i.se)>n)continue;

		if(s.find({xx-(x+i.fi),yy-(y+i.se)})!=s.end())return true;
	}
	return false;
}
int main(){
	scanf("%d %d %d %d %d",&n,&ax,&ay,&bx,&by);
	for(int i=0;i<n;i++){
		int xxx,yyy;
		scanf("%d %d",&xxx,&yyy);
		s.insert(make_pair(xxx,yyy));
	}
	if(go(ax,ay,bx,by))return !printf("Alice wins\n");
	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!go(bx,by,i,j))return !printf("tie %d %d\n", i,j);
			}
		}
		printf("Bob wins\n");
		return 0;
	}
	while(1){
		ll nx=randll(1,n);
		ll ny=randll(1,n);
		if(!go(bx,by,nx,ny))return !printf("tie %d %d\n", nx,ny);
	}
}