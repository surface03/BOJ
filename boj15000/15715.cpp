#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll MOD=1000000007;

int n,m,a[200010];
vector<int> v,vt;
int now=1;
void f(int cur,int st,int xx){
	if(cur>xx){
		vt.push_back(now);
		return;
	}
	for(int i=st;i<(int)v.size();i++){
		now*=v[i];
		f(cur+1,i+1,xx);
		now/=v[i];
	}
}
ll eul(int x,int y){
	v.clear();
	if(x==1)return y;
	int t=x,ans=y;
	for(int i=2;i*i<=t;i++){
		if(x%i==0){
			while(x%i==0){
				x/=i;
			}
			v.push_back(i);
		}
		
	}
	if(x>1){
		v.push_back(x);
	}
	int sign=-1;
	for(int i=1;i<=(int)v.size();i++){
		vt.clear();
		now=1;
		f(1,0,i);
		for(int j:vt){
			ans+=sign*(y/j);
		}
		sign=-sign;
	}
	return ans;
}
int main(){
	ll ans=1;
	int chk=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		if(a[i-1]%a[i]){
			chk=1;
			break;
		}
		ans=(ans*eul(a[i-1]/a[i],m/a[i]))%MOD;
	}
	if(chk){
		printf("0\n");
	}
	else printf("%lld\n", ans);
}