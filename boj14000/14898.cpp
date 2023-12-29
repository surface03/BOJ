#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct node{
	int val;
	int l,r;
	node() : val(0), l(0), r(0) {}
}tree[40000000];
int pos[1000010],a[1000010],curpos;

void init(node &now,int s,int e){
	if(s==e){
		now.val=0;
		return;
	}
	int m=(s+e)/2;
	now.l =++curpos;
	now.r=++curpos;
	init(tree[now.l],s,m);
	init(tree[now.r],m+1,e);
	now.val=0;
}

void upd(node &pre, node &now, int s,int e,int idx,bool vaal){
	if(s==e){
		now.val=vaal;
		return;
	}
	int m=(s+e)/2;
	if(idx<=m){
		if(now.l == 0)now.l=++curpos;
		else if(now.l == pre.l)now.l = ++curpos;

		if(now.r == 0)now.r=pre.r;

		upd(tree[pre.l],tree[now.l],s,m,idx,vaal);
	}
	else{
		if(now.l == 0)now.l=pre.l;

		if(now.r == 0)now.r=++curpos;
		else if(now.r == pre.r) now.r = ++curpos;

		upd(tree[pre.r],tree[now.r],m+1,e,idx,vaal);
	}
	now.val = tree[now.l].val + tree[now.r].val;
}

int Qu(node &now,int s,int e,int qs,int qe){
	if(qs<= s && e<=qe)return now.val;
	if(e<qs || qe<s)return 0;
	int m=(s+e)/2;
	return Qu(tree[now.l],s,m,qs,qe) + Qu(tree[now.r],m+1,e,qs,qe);
}

vector<int> v;
int main(){
	int N,Q;
	scanf("%d",&N);
	v.resize(N);
	curpos=N;
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		v[i-1]=a[i];
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=N;i++) a[i]=(int)(lower_bound(v.begin(),v.end(),a[i])-v.begin())+1;

	init(tree[0],1,N);
	for(int i=1;i<=N;i++){
		upd(tree[i-1],tree[i],1,N,i,1);

		if(pos[a[i]]!=0)upd(tree[i-1],tree[i],1,N,pos[a[i]],0);
		pos[a[i]]=i;
	}
	int ans=0;
	scanf("%d",&Q);
	while(Q--){
		int L,R;
		scanf("%d %d",&L,&R);
		L+=ans;
		printf("%d\n", ans=Qu(tree[R],1,N,L,R));
	}
}