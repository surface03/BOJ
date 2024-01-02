#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> v[100010];
int dep[100010],par[100010][50],visited[100010],n;
void dfs(int now,int d){
	visited[now]=1;
	dep[now]=d;
	for(int i:v[now]){
		if(visited[i])continue;
		par[i][0]=now;
		dfs(i,d+1);
	}
}

int lca(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	int val = dep[a]-dep[b];
	for(int i=0;i<=25;i++){
		if(val&(1<<i)){
			a=par[a][i];
		}
	}
	if(a==b) return a;
	for(int i=25;i>=0;i--){
		if(par[a][i]!=par[b][i]){
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}

int dis(int a,int b){
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int xx,yy;
		scanf("%d %d",&xx,&yy);
		v[xx].push_back(yy);
		v[yy].push_back(xx);
	}
	dfs(1,0);

	for(int j=1;j<=25;j++){
		for(int i=1;i<=n;i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	
	int m;
	scanf("%d",&m);
	while(m--){
		int x,y,a,b,k;
		scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
		int v1=dis(a,b),v2=dis(a,x)+1+dis(y,b),v3=dis(a,y)+1+dis(x,b);
		if(v1<=k && (k-v1)%2==0) puts("YES");
		else if(v2<=k && (k-v2)%2==0) puts("YES");
		else if(v3<=k && (k-v3)%2==0) puts("YES");
		else puts("NO");
	}
}