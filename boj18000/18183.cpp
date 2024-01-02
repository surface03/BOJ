#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;

struct data8{
	LL a[2][2];
	data8 operator*(const data8&r)const{
		data8 t;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				t.a[i][j]=0;
				for(int k=0;k<2;k++){
					t.a[i][j]=(t.a[i][j]+a[i][k]*r.a[k][j])%MOD;
				}
			}
		}
		return t;
	}
};
struct data12{
	LL a[4][4];
	data12 operator*(const data12&r)const{
		data12 t;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				t.a[i][j]=0;
				for(int k=0;k<4;k++){
					t.a[i][j]=(t.a[i][j]+a[i][k]*r.a[k][j])%MOD;
				}
			}
		}
		return t;
	}
};
data8 pow8(LL b){
	if(b==0){
		return data8{{
			{1,0},
			{0,1}
		}};
	}
	data8 tmp=pow8(b/2);
	tmp=tmp*tmp;
	if(b&1){
		tmp=tmp*data8{{
			{16,MOD-27},
			{1,0}
		}};
	}
	return tmp;
}
data12 pow12(LL b){
	if(b==0){
		return data12{{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		}};
	}
	data12 tmp=pow12(b/2);
	tmp=tmp*tmp;
	if(b&1){
		tmp=tmp*data12{{
			{87,998242913,6183,998237792},
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0}
		}};
	}
	return tmp;
}

LL ipow(LL a,LL b){
	if(b==0) return 1;
	LL tmp=ipow(a,b/2);
	tmp=(tmp*tmp)%MOD;
	if(b&1)tmp=(tmp*a)%MOD;
	return tmp;
}


int main(){
	LL n,m;
	scanf("%lld %lld",&n,&m);
	if(n%4 || m%4)return !printf("0\n");
	if(m==4){
		printf("%lld\n", (2*ipow(3,n/4-1)%MOD));
	}
	if(m==8){
		data8 k=pow8(n/4-1);
		k=k*data8{{
			{84,0},
			{6,0}
		}};
		printf("%lld\n", k.a[1][0]);
	}
	if(m==12){
		data12 k=pow12(n/4-1);
		k=k*data12{{
			{5253822,0,0,0},
			{78696,0,0,0},
			{1182,0,0,0},
			{18,0,0,0}
		}};
		printf("%lld\n", k.a[3][0]);
	}
}