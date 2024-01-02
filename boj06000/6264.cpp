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


int n,cnt,scnt,visited[100010],sccn[100010],dfsn[100010],visited2[100010];
vector<int> v[100010];
stack<int> stk;
set<int> ans;
vector<vector<int>> scc,w;
map<string,int> mp;
map<int,string> mpb;
int ccnt;
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
			if(t==now)break;
		}
		scc.push_back(tmp);
	}
	return ret;
}
void dfs2(int now){
	visited2[now]=1;
	ans.insert(now);
	for(int i:w[now]){
		if(visited2[i]==0)dfs2(i);
	}
}
int main(){
	while(1){
		while(!stk.empty())stk.pop();
		ans.clear();
		scc.clear();
		w.clear();
		mp.clear();
		mpb.clear();
		scnt=cnt=ccnt=0;
		for(int i=0;i<100010;i++)v[i].clear();
		memset(visited,0,sizeof visited);
		memset(sccn,0,sizeof sccn);
		memset(dfsn,0,sizeof dfsn);
		memset(visited2,0,sizeof visited2);
		cin>>n;
		debug(n);
		if(n==0)break;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			debug(s);
			int nownum=0;
			if(mp.find(s)==mp.end()){
				ccnt++;
				mp[s]=ccnt;
				nownum=ccnt;
				mpb[ccnt]=s;
			}
			else nownum=mp[s];

			getline(cin,s);
			s+=' ';
			debug(s);
			string tmp="";
			for(int i=0;i<(int)s.size();i++){
				if(s[i]==' ' && tmp != ""){
					int tnum=0;
					if(mp.find(tmp)==mp.end()){
						ccnt++;
						mp[tmp]=ccnt;
						tnum=ccnt;
						mpb[ccnt]=tmp;
					}
					else tnum=mp[tmp];
					v[nownum].push_back(tnum);
					tmp="";
				}
				else if(s[i]==' '){
					continue;
				}
				else tmp+=s[i];
			}
		}

		for(int i=1;i<=n;i++){
			if(!dfsn[i])dfs(i);
		}
		w.resize(n+1);
		for(int i=1;i<=n;i++){
			for(int j:v[i]){
				if(sccn[i]!=sccn[j]){
					w[sccn[i]].push_back(sccn[j]);
				}
			}
		}

		for(int i=1;i<=scnt;i++){
			if((int)scc[i-1].size()>=2){
				dfs2(i);
			}
			if((int)w[i].size()==0){
				ans.insert(i);
			}
		}
		set<string> anss;
		for(int i:ans){
			for(int j:scc[i-1]){
				anss.insert(mpb[j]);
			}
		}
		cout<<(int)anss.size()<<endl;
		for(string ss:anss){
			cout<<ss<<" ";
		}
		cout<<endl;
	}
}