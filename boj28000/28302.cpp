#include <bits/stdc++.h>
using namespace std;

int n,m;
int calc[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}}; //1,i,j,k
int resa,resb;
char a[1010]={},b[1010]={};
struct H{
	int op,x,y,z;
};
vector<H> v1,v2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %c",&a[i]);
		if(a[i]=='R') resa=calc[resa][1];
		else if(a[i]=='B') resa=calc[resa][2];
		else if(a[i]=='G') resa=calc[resa][3];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf(" %c",&b[i]);
		if(b[i]=='R') resb=calc[resb][1];
		else if(b[i]=='B') resb=calc[resb][2];
		else if(b[i]=='G') resb=calc[resb][3];
	}

	if(resa!=resb){
		puts("-1");
		return 0;
	}


	for(int j=0;j<n;j++){
		for(int i=1;i<n;i++){
			if(a[i]==0 || a[i+1]==0)break;
			if(a[i]!=a[i+1]){
				v1.push_back({1,i,i+1,0});
				int x=((int)'R')+((int)'G')+((int)'B')-(int)a[i]-(int)a[i+1];
				a[i]=(char)x;
				for(int j=i+1;j<=n;j++){
					a[j]=a[j+1];
				}
				break;
			}
		}/*
		for(int i=1;i<=strlen(a+1);i++){
			printf("%c ", a[i]);
		}
		puts("");*/
	}
	int strA=strlen(a+1);
	while(strA>=3){
		char x,y;
		if(a[1]=='R'){
			x='G';
			y='B';
		}
		if(a[1]=='G'){
			x='R';
			y='B';
		}
		if(a[1]=='B'){
			x='R';
			y='G';
		}
		v1.push_back({2,2,x,y});
		v1.push_back({1,3,4,0});
		v1.push_back({1,1,2,0});
		v1.push_back({1,1,2,0});
		strA-=2;
	}
	if(strA==2){
		if(a[1]=='G'){
			v1.push_back({2,2,'B','R'});
			v1.push_back({1,1,2,0});
		}
		if(a[2]=='B'){
			v1.push_back({2,2,'G','R'});
			v1.push_back({1,1,2,0});
		}
	}



	for(int j=0;j<m;j++){
		for(int i=1;i<m;i++){
			if(b[i]==0 || b[i+1]==0)break;
			if(b[i]!=b[i+1]){
				v2.push_back({2,i,b[i],b[i+1]});
				int x=((int)'R')+((int)'G')+((int)'B')-(int)b[i]-(int)b[i+1];
				b[i]=(char)x;
				for(int j=i+1;j<=m;j++){
					b[j]=b[j+1];
				}
				break;
			}
		}	
	}
	int strB=strlen(b+1);
	while(strB>=3){
		char x,y;
		if(b[1]=='R'){
			x='G';
			y='B';
		}
		if(b[1]=='G'){
			x='R';
			y='B';
		}
		if(b[1]=='B'){
			x='R';
			y='G';
		}
		v2.push_back({1,2,3,0});
		v2.push_back({2,1,b[1],y});
		v2.push_back({2,2,x,b[1]});
		v2.push_back({2,1,x,y});
		
		
		strB-=2;
	}
	if(strB==2){
		if(b[1]=='G'){
			v2.push_back({1,2,3,0});
			v2.push_back({2,1,'G','B'});
		}
		if(b[2]=='B'){
			v2.push_back({1,2,3,0});
			v2.push_back({2,1,'B','G'});
		}
	}
	printf("%d\n", (int)(v1.size()+v2.size()));
	for(auto i:v1){
		if(i.op==2){
			printf("%d %d %c %c\n", i.op,i.x,i.y,i.z);
		}
		else{
			printf("%d %d %d\n", i.op,i.x,i.y);
		}
	}
	reverse(v2.begin(),v2.end());
	for(auto i:v2){
		if(i.op==2){
			printf("%d %d %c %c\n", i.op,i.x,i.y,i.z);
		}
		else{
			printf("%d %d %d\n", i.op,i.x,i.y);
		}
	}
}