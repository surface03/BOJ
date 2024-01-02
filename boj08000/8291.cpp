#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll a[3000010],b[3000010],c[3000010],d[3000010];
int n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        a[x]++;
    }
    for(int i=1;i<=3000000;i++){
        for(int j=i;j<=3000000;j+=i){
            b[i]+=a[j];
        }
    }
    for(int i=1;i<=3000000;i++){
        c[i]=b[i]*(b[i]-1)/2;
    }
    for(int i=3000000;i>=1;i--){
        d[i]=c[i];
        for(int j=2*i;j<=3000000;j+=i){
            d[i]-=d[j];
        }
    }
    printf("%lld\n", d[1]);
}
