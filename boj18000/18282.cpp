#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

vector<int> v[1000010];
pair<int,int> p[1000010];
int visit[1000010];
int ans[1000010];
void dfs(int x,int col){
	ans[x]=col;
	visit[x]=1;
	for(int i:v[x]){
		if(visit[i])continue;
		dfs(i,1-col);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	

	for(int i=1;i<=n;i++){
		scanf("%d %d",&p[i].fi,&p[i].se);
		v[p[i].fi].push_back(p[i].se);
		v[p[i].se].push_back(p[i].fi);
	}

	for(int i=1;i<=2*n;i+=2){
		v[i].push_back(i+1);
		v[i+1].push_back(i);
	}
	for(int i=1;i<=2*n;i++){
		if(visit[i])continue;
		dfs(i,1);
	}
	for(int i=1;i<=2*n;i++){
		printf("%c", (char)ans[i]+'A');
	}
}