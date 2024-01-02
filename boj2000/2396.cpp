#include <bits/stdc++.h>
using namespace std;
int sum,a[200],n,cnt,visit[200],ans;
vector<int> v[200];
void f(int x,int st,int cur){
	if(cur==ans){
		if(x==cnt){
			printf("%d\n", ans);
			exit(0);
		}
		int ncur=0;
		if(!v[x+1].empty()) ncur=v[x+1][0];
		f(x+1,1,ncur);
		return;
	}
	int used=-1;
	for(int i=st;i<=n;i++){
		if(cur+a[i]>ans || visit[i])continue;
		if(used==a[i]) continue;

		used=a[i];
		visit[i]=1;
		v[x].push_back(a[i]);

		f(x,i+1,cur+a[i]);

		v[x].pop_back();
		visit[i]=0;

		//if(st==1)break;
		if(cur+a[i]==ans)break;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=a[1];i<=sum;i++){
		if(sum%i) continue;
		memset(visit,0,sizeof(visit));
		for(int i=0;i<200;i++)v[i].clear();
		ans=i;
		cnt=sum/ans;
		int t=0;
		for(int i=1;i<=n;i++){
			if(a[i]>ans/2){
				v[++t].push_back(a[i]);
				visit[i]=1;
			}
		}
		if(t>cnt)continue;
		f(1,1,a[1]>ans/2?a[1]:0);
	}
}