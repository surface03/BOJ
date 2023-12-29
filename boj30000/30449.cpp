#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pair<int,int>> v;
int n,k,cnt;
int main(){
	scanf("%d %d", &n,&k);
	v.push_back({1,1});
	int x=0,y=1;
	while(!v.empty()){
		cnt++;
		if(cnt==k)return !printf("%d %d\n", x,y);
		while(y+v.back().se <= n)v.push_back({x+v.back().fi, y+v.back().se});
		x=v.back().fi;
		y=v.back().se;
		v.pop_back();
	}
	printf("1 1\n");
}