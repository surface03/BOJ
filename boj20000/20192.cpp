#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a[300010],ch;
int main(){
	int n,cnt=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if( (ch==0 && a[i]>=a[i-1]) || (ch==1 && a[i]<=a[i-1]) )continue;
		cnt++;
		ch=1-ch;
	}
	for(int i=1,ans=0;;i<<=1,ans++){
		if(i>=cnt)return !printf("%d\n", ans);
	}
}