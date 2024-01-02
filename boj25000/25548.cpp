#include <stdio.h>
typedef long long ll;

int n;
ll ans;
ll f(int x){
	ll sum=0;
	int i=0;
	for(i=1;i*i<=x;i++){
		sum+=1ll*x/i;
	}
	sum=2*sum-(i-1)*(i-1);
	return sum;
}
int main(){
	scanf("%d",&n);
	int i;
	for(i=1;i*i<=n;i++){
		ans+=f(n/i);
	}
	for(int j=n/i;j>=1;j--){
		ans+=(n/j-n/(j+1))*f(j);
	}
	printf("%lld\n", ans);
}