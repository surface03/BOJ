#include <bits/stdc++.h>
using namespace std;

int n;

void pr(int x){
	printf("%d\n", x);
	fflush(stdout);
	n-=x;
	if(n==0)exit(0);
}


int main(){
	scanf("%d",&n);
	int mod=n%5;
	if(mod==2 || mod==3 || mod==0){
		puts("NO");
		fflush(stdout);
		return 0;
	}
	puts("YES");
	fflush(stdout);
	pr(1);

	while(n){
		int x;
		scanf("%d",&x);
		n-=x;
		int m=n%5;
		if(m==1){
			pr(1);
		}
		else if(m==2){
			pr(2);
		}
		else if(m==3){
			pr(3);
		}
		else if(m==4){
			pr(1);
		}
	}
}