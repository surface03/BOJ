#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;
vector<int> diff(vector<int> x,vector<int> y){
	for(int i:y){
		for(int &j: x){
			if(i==j){
				j=-1;
				break;
			}
		}
	}
	vector<int> ret;
	for(int i:x){
		if(i!=-1)ret.push_back(i);
	}
	return ret;
}
int SUM(vector<int> x){
	int sum=0;
	for(int i:x){
		sum+=i;
	}
	return sum;
}

vector<int> f(vector<int> x){
	if((int)x.size()==1) return x;
	
	int nn=((int)x.size()+1)/4; //2^(k-1)
	vector<int> ans1,ans2,ans3,rans1,rans2,rans3;
	for(int i=0;i<2*nn-1;i++){
		ans1.push_back(x[i]);
	}
	rans1=f(ans1);
	ans2=diff(ans1,rans1);
	for(int i=2*nn-1;i<3*nn-1;i++){
		ans2.push_back(x[i]);
	}
	rans2=f(ans2);
	ans3=diff(ans2,rans2);
	for(int i=3*nn-1;i<4*nn-1;i++){
		ans3.push_back(x[i]);
	}
	rans3=f(ans3);
	if((SUM(rans1)+SUM(rans2))%(2*nn)==0){
		for(int i:rans2){
			rans1.push_back(i);
		}
		return rans1;
	}
	else if((SUM(rans1)+SUM(rans3))%(2*nn)==0){
		for(int i:rans3){
			rans1.push_back(i);
		}
		return rans1;
	}
	else{
		for(int i:rans2){
			rans3.push_back(i);
		}
		return rans3;
	}
}

int main(){
	scanf("%d",&n);
	vector<int> g;
	for(int i=0;i<2*n-1;i++){
		int xx;
		scanf("%d",&xx);
		g.push_back(xx);
	}
	auto t=f(g);
	for(auto i:t) printf("%d ", i);
}