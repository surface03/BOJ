#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int N;

struct node{
	int val;
	node *l,*r;
	node() : val(0), l(NULL), r(NULL) {}
};
node *tree[100010];

void init(node* now,int s,int e){
	if(s==e){
		now->val=0;
		return;
	}
	int m=(s+e)/2;
	now->l=new node();
	now->r=new node();
	init(now->l,s,m);
	init(now->r,m+1,e);
	now->val=0;
}

void upd(node* pre, node* now, int s,int e,int idx){
	if(s==e){
		now->val=pre->val + 1;
		return;
	}
	int m=(s+e)/2;
	if(idx<=m){
		now->l=new node();
		now->r=pre->r;
		upd(pre->l,now->l,s,m,idx);
	}
	else{
		now->l=pre->l;
		now->r = new node();
		upd(pre->r,now->r,m+1,e,idx);
	}
	now->val = now->l->val + now->r->val;
}

int kth(node *A,node *B,node *C,node *D,int s,int e,int k){
	if(s==e){
		return s;
	}
	int m=(s+e)/2;
	if(A->l->val + B->l->val - C->l->val - D->l->val >= k)return kth(A->l,B->l,C->l,D->l,s,m,k);
	else return kth(A->r,B->r,C->r,D->r,m+1,e,k-(A->l->val + B->l->val - C->l->val - D->l->val));
}

vector<int> v[100010],tmp;
int dep[100010],par[100010][50],visited[100010],c[100010];

void dfs(int now,int d){
	visited[now]=1;
	dep[now]=d;
	upd(tree[par[now][0]],tree[now],1,100000,lower_bound(tmp.begin(),tmp.end(),c[now])-tmp.begin() + 1);
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

int main(){
	int Q;
	for(int i=0;i<=100000;i++)tree[i]=new node();
	init(tree[0],1,100000);
	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;i++){
		scanf("%d",&c[i]);
		tmp.push_back(c[i]);
	}
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	for(int i=1;i<N;i++){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		v[ui].push_back(vi);
		v[vi].push_back(ui);
	}

	dfs(1,0);

	for(int j=1;j<=25;j++){
		for(int i=1;i<=N;i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	
	while(Q--){
		int ui,vi,k;
		scanf("%d %d %d",&ui,&vi,&k);
		printf("%d\n", tmp[kth(tree[ui],tree[vi],tree[lca(ui,vi)],tree[par[lca(ui,vi)][0]],1,100000,k)-1]);
	}
}