#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int n,m;
pii a[100010];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].fi);
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    while(m--){
        int i,j,k,cnt=0;
        scanf("%d %d %d",&i,&j,&k);
        for(int ii=1;ii<=n;ii++){
            if(a[ii].se >= i && a[ii].se <= j)cnt++;
            if(cnt == k){
                printf("%d\n",a[ii].fi);
                break;
            }
        }
    }
}