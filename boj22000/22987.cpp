#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
set<int> ans;
set<pll> s;
struct data{
	pll p;
	int num;
	bool operator<(const data&r)const{
		if(p.se==r.p.se) return num<r.num;
		return p.se>r.p.se;
	}
}a[500010];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].p.fi>>a[i].p.se;
		a[i].num=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		auto it=s.upper_bound({a[i].p.fi-a[i].p.se,(ll)4e18});
		if(it==s.begin() || (*prev(it)).se<a[i].p.fi-a[i].p.se){
			auto jt=s.upper_bound({a[i].p.fi+a[i].p.se,(ll)4e18});
			if(jt==s.begin() || (*prev(jt)).se<a[i].p.fi+a[i].p.se){
				ans.insert(a[i].num);
				s.insert({a[i].p.fi-a[i].p.se,a[i].p.fi+a[i].p.se});
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(int i:ans){
		cout<<i<<' ';
	}
}