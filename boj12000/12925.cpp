#include<stdio.h>
typedef long long LL;
const LL M=1000;
struct data{
    LL a[2][2];
    data operator*(data r){
        data t;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                t.a[i][j]=0;
                for(int k=0;k<2;k++){
                    t.a[i][j]=(t.a[i][j]+a[i][k]*r.a[k][j])%M;
                }
            }
        }
        return t;
    }
}ans;
data recur(LL n){
    if(n==0)return {{{1,0},{0,1}}};
    data tmp=recur(n/2);
    tmp=tmp*tmp;
    if(n&1)tmp=tmp*data{{{6,M-4},{1,0}}};
    return tmp;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        LL N;
        scanf("%lld",&N);
        ans=recur(N);
        ans=ans*data{{{6,0},{2,0}}};
        printf("Case #%d: %03lld\n",i,(ans.a[1][0]-1+M)%M);
    }
}
