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

int n,m,cnt,scnt,visited[500010],sccn[500010],dfsn[500010],c[500010],dp[500010],ok[500010],totc[500010];
vector<int> v[500010],w[500010];
stack<int> stk;
vector<vector<int>> scc;
int dfs(int now){
	dfsn[now]=++cnt;
	int ret=dfsn[now];
	stk.push(now);
	for(int i:v[now]){
		if(dfsn[i]==0)ret = min(ret,dfs(i));
		else if(sccn[i]==0)ret = min(ret,dfsn[i]); 
	}
	if(ret == dfsn[now]){
		scnt++;
		vector<int> tmp;
		while(1){
			int t=stk.top();
			stk.pop();
			sccn[t]=scnt;
			tmp.push_back(t);
			totc[scnt]+=c[t];
			if(t==now)break;
		}
		scc.push_back(tmp);
	}
	return ret;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	int S,P;
	scanf("%d %d",&S,&P);
	for(int i=1;i<=n;i++){
		if(!dfsn[i])dfs(i);
	}
	for(int i=1;i<=n;i++){
		for(int j:v[i]){
			if(sccn[i]==sccn[j])continue;
			w[sccn[i]].push_back(sccn[j]);
		}
	}

	memset(dp,-1,sizeof dp);
	for(int i=1;i<=P;i++){
		int x;
		scanf("%d",&x);
		ok[sccn[x]]=1;
	}
	dp[sccn[S]]=totc[sccn[S]];
	int ans=0;
	for(int i=scnt;i>=1;i--){
		if(dp[i]==-1)continue;
		for(int j:w[i]){
			dp[j]=max(dp[j],dp[i]+totc[j]);
		}
	}
	for(int i=1;i<=scnt;i++){
		if(ok[i] && dp[i]>=0){
			ans=max(ans,dp[i]);
		}
	}
	printf("%d\n", ans);
}