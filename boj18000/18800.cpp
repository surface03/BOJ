#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#import <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int iB=500;
int n,k,Q,cur[200010];
LL a[200010],ans[200010],cans,gans[200010],mcnt[200010];
vector<vector<LL> > cnt,cnt2;
vector<LL> v;

struct data{
	int fr,re,qnum;
	bool operator<(const data&r)const{
		if(re/iB==r.re/iB)return fr<r.fr;
        return re<r.re;
	}
}q[100010];

void add(int pos,LL val){
	cnt2[pos][cnt[pos][val]]--;
	cnt[pos][val]++;
	cnt2[pos][cnt[pos][val]]++;
	mcnt[pos] = max(mcnt[pos],cnt[pos][val]);
}

void del(int pos,LL val){
	cnt2[pos][cnt[pos][val]]--;
	if(cnt2[pos][cnt[pos][val]]==0 && mcnt[pos]==cnt[pos][val]){
		mcnt[pos]--;
	}
	cnt[pos][val]--;
	cnt2[pos][cnt[pos][val]]++;
}

LL ncnt(int pos,int l,int r){
	int L,R;
	L=l/k;
	if(l%k > pos)L++;

	R=r/k;
	if(r%k >= pos)R++;
	return (LL)(R-L);
}

void updans(int pos,int l,int r){
	cans -= gans[pos];
	LL A=(LL)ncnt(pos,l,r) - cnt[pos][cur[pos]];
	A = min(A, (LL)ncnt(pos,l,r) - mcnt[pos] + 1);
	gans[pos] = A;
	cans += gans[pos];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k>>Q;
	cnt.resize(k+5);
	cnt2.resize(k+5);
	for(int i=0;i<k;i++){
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>a[k+i];
	}
	n += k;
	for(int i=n-1;i>0;i--){
		a[i]-=a[i-1];
	}
	for(int i=k;i<n;i++){
		a[i]+=a[i-k];
	}
	
	
	for(int i=0;i<k;i++){
		v.clear();
		for(int j=i;j<n;j+=k){
			v.push_back(a[j]);
		}
		cnt2[i].resize((int)v.size()+3, 0ll);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int j=i;j<n;j+=k){
			a[j] = lower_bound(v.begin(), v.end(), a[j]) - v.begin();
		}
		cnt[i].resize((int)v.size()+2, 0);
		cur[i] = a[i];
	}

	for(int i=0;i<Q;i++){
		int s,e;
		cin>>s>>e;
		s+=k;
		e+=k;
		e--;
		q[i].qnum = i;
		q[i].fr = s;
		q[i].re = e;
	}
	sort(q, q+Q);
	int s=k+1,e=k;
	cur[0]=a[k];
	for(int i=0;i<Q;i++){
		if(q[i].fr>q[i].re){
			ans[q[i].qnum]=0;
			continue;
		}
		while(e<q[i].re){
			++e;
			add(e%k, a[e]);
			updans(e%k, s, e);
		}
		while(s>q[i].fr){
			--s;
			add(s%k, a[s]);
			updans(s%k, s, e);
			cur[s%k] = a[s-k];
			updans(s%k, s, e);
		}
		while(e>q[i].re){
			del(e%k, a[e]);
			updans(e%k,s,e-1);
			e--;
		}
		while(s<q[i].fr){
			del(s%k, a[s]);
			updans(s%k, s+1,e);
			cur[s%k] = a[s];
			updans(s%k, s+1,e);
			s++;
		}
		ans[q[i].qnum] = cans;
	}

	for(int i=0;i<Q;i++){
		cout<<ans[i]<<'\n';
	}
}