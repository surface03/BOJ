#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll MOD=1000000007ll;
const ll INF=1e18;

ll ipow(ll _a,ll _b){ll _ret=1;while(_b){if(_b&1) _ret=_ret*_a % MOD;_a=_a*_a % MOD;_b>>=1;}return _ret;}


int main(){
	ll n;
	cin>>n;
	ll ans=(n+1)%MOD*(ipow(2,n)+MOD-1)+(MOD-1)*(n%MOD)%MOD*ipow(2,n-1);
	cout<<ans%MOD;
}