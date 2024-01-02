#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int iB=330;
int a[100010],n,ans[100010],th[100010];
int cnt[100010],bcnt[100010],anscnt,m;
int abcnt[510][510];

struct dat{
	int s,e,qn;
	bool operator<(const dat&r)const{
		if(e/iB == r.e/iB) return s<r.s;
		return e<r.e;
	}
}q[100010];

void add(int x){
	bcnt[cnt[x]]--;
	abcnt[x/iB][cnt[x]]--;
	cnt[x]++;
	bcnt[cnt[x]]++;
	abcnt[x/iB][cnt[x]]++;

	anscnt=max(anscnt,cnt[x]);
}

void del(int x){
	bcnt[cnt[x]]--;
	abcnt[x/iB][cnt[x]]--;
	if(cnt[x]==anscnt && bcnt[cnt[x]]==0) anscnt--;
	cnt[x]--;
	bcnt[cnt[x]]++;
	abcnt[x/iB][cnt[x]]++;


}

int getans(){
	for(int i=m/iB;i>=0;i--){
		if(abcnt[i][anscnt]>0){
			for(int j=i*iB+iB-1;j>=i*iB;j--){
				if(cnt[j]==anscnt)return th[j];
			}
		}
	}
	return 0;
}

int main(){
	bcnt[0]=100000;
	for(int i=0;i<300;i++)abcnt[i][0]=100000;
	int Q;
	scanf("%d %d",&n,&Q);
	vector<int> v;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	m=(int)v.size();
	for(int i=1;i<=n;i++){
		int x=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		th[x]=a[i];
		a[i]=x;
	}
	for(int i=0;i<Q;i++){
		scanf("%d %d",&q[i].s,&q[i].e);
		q[i].qn=i;
	}
	sort(q,q+Q);
	int fr=1,re=0;
	for(int i=0;i<Q;i++){
		while(q[i].e>re) add(a[++re]);
		while(q[i].s<fr) add(a[--fr]);
		while(q[i].s>fr) del(a[fr++]);
		while(q[i].e<re) del(a[re--]);
		ans[q[i].qn]=getans();
	}
	for(int i=0;i<Q;i++) printf("%d\n", ans[i]);
}