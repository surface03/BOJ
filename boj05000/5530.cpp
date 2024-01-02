#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

char a[1000010];
int n;
bool chk(int x){
	int ticnt=0,icnt=0,ocnt=0,cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]=='I'){
			if(ticnt<x)ticnt++,icnt++;
			else{
				if(icnt>0 && ocnt>0){
					icnt--;ocnt--;cnt++;
				}
			}
		}
		if(a[i]=='O'){
			if(icnt>0 && ocnt<icnt){
				ocnt++;
			}
		}
		if(a[i]=='J'){
			if(ocnt>0 && icnt>0){
				ocnt--;icnt--;cnt++;
			}
		}
	}
	if(ticnt<x)return false;
	if(cnt==x)return true;
	else return false;
}

int main(){
	int ocnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %c",&a[i]);
		if(a[i]=='O')ocnt++;
	}
	int fr=0,re=ocnt,ans=0,m;
	while(fr<=re){
		m=(fr+re)/2;
		if(chk(m))ans=m,fr=m+1;
		else re=m-1;
	}
	printf("%d\n", ans);
}