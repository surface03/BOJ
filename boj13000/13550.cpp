#include<bits/stdc++.h>
using namespace std;
const int iB=400;
const int SZ=131072;
int n,K,a[100010],ans[100010];
list<int>dq[1000010];
int arr[100010],b[300];
int bf(int idx){
    return dq[idx].back()-dq[idx].front();
}
struct data{
    int frq,req,qnum;
    bool operator<(const data&r)const{
        if(req/iB==r.req/iB)return frq<r.frq;
        return req<r.req;
    }
}p[100010];

int main(){
    int M;
    scanf("%d %d",&n,&K);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=(a[i]+a[i-1])%K;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int aii,bii;
        scanf("%d %d",&aii,&bii);
        aii--;
        p[i].frq=aii;
        p[i].req=bii;
        p[i].qnum=i;
    }
    sort(p,p+M);

    int fr=0,re=-1;

    for(int i=0;i<M;i++){
        int t=0;
        for(int j=re;j>p[i].req;j--){
            arr[bf(a[j])]--;
            b[bf(a[j])/iB]--;
            dq[a[j]].pop_back();
            if(!dq[a[j]].empty()){
                arr[bf(a[j])]++;
                b[bf(a[j])/iB]++;
            }
        }
        for(int j=fr-1;j>=p[i].frq;j--){
            if(!dq[a[j]].empty()){
                arr[bf(a[j])]--;
                b[bf(a[j])/iB]--;
            }
            dq[a[j]].push_front(j);
            arr[bf(a[j])]++;
            b[bf(a[j])/iB]++;
        }
        for(int j=re+1;j<=p[i].req;j++){
            if(!dq[a[j]].empty()){
                arr[bf(a[j])]--;
                b[bf(a[j])/iB]--;
            }
            dq[a[j]].push_back(j);
            arr[bf(a[j])]++;
            b[bf(a[j])/iB]++;
        }
        for(int j=fr;j<p[i].frq;j++){
            arr[bf(a[j])]--;
            b[bf(a[j])/iB]--;
            dq[a[j]].pop_front();
            if(!dq[a[j]].empty()){
                arr[bf(a[j])]++;
                b[bf(a[j])/iB]++;
            }
        }
        int Ans=0;
        for(int j=299;j>=0;j--){
            if(b[j]){
                for(int k=j*iB;k<(j+1)*iB;k++){
                    if(arr[k]>0)Ans=k;
                }
                break;
            }
        }
        ans[p[i].qnum]=Ans;
        fr=p[i].frq;
        re=p[i].req;
    }
    for(int i=0;i<M;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
