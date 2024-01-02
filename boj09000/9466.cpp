#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[100010];
int visit[100010],visit2[100010];
int dfs2(int now,int p){
	if(now==p)return 1;
	visit2[now]=1;
	for(int i:v[now]){
		if(visit2[i])continue;
		return dfs2(i,p)+1;
	}
}
int dfs(int x){
	visit[x]=2;
	int k=0;
	for(int i:v[x]){
		if(visit[i]==1)break;
		else if(visit[i]==2){
			k+=dfs2(i,x);
		}
		else{
			k+=dfs(i);
		}
	}
	visit[x]=1;
	return k;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int val;
			scanf("%d",&val);
			v[i].push_back(val);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!visit[i]) ans+=dfs(i);
		}
		printf("%d\n", n-ans);
		for(int i=1;i<=n;i++)v[i].clear();
		memset(visit,0,4*n+4);
		memset(visit2,0,sizeof 4*n+4);
	}
}