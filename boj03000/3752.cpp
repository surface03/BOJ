#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1000000007;

int p[45010];
vector<int> pr;

int epi(int n){
	int ans=n,nn=n;
	for(int i:pr){
		if(nn%i==0){
			ans/=i;
			ans*=i-1;
			while(nn%i==0) nn/=i;
		}
	}
	if(nn>1){
		ans/=nn;
		ans*=nn-1;
	}
	return ans;
}
int main(){
	for(int i=2;i*i<=45000;i++){
		if(p[i])continue;
		for(int j=i*i;j<=45000;j+=i) p[j]=1;
	}
	for(int i=2;i<=45000;i++){
		if(p[i]==0) pr.push_back(i);
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		ll ret=1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			ret=(ret*epi(x))%MOD;
		}
		printf("%lld\n", ret);
	}

}