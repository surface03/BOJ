#include<bits/stdc++.h>
using namespace std;
const int B=1000;
int n,Q;
vector<int>bk[102];
int arr[100010];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        arr[i]=x;
        bk[i/B].push_back(x);
    }
    cin>>Q;
    for(int i=0;i<102;i++) sort(bk[i].begin(),bk[i].end());
    while(Q--){
        int op;
        cin>>op;
        if(op==2){
            int s,e,k,ans=0;
            cin>>s>>e>>k;s--;e--;
            for(int i=s;i<=e;){
                if(i%B==0 && i+B<e){
                    ans += bk[i/B].end()-upper_bound(bk[i/B].begin(),bk[i/B].end(),k);
                    i+=B;
                }
                else{
                    ans+=(arr[i]>k);
                    i++;
                }
            }
            cout << ans << "\n";
        }
        else{
            int i,k;
            cin >> i >> k; i--;
            int pos=lower_bound(bk[i/B].begin(),bk[i/B].end(),arr[i])-bk[i/B].begin();
            bk[i/B].erase(bk[i/B].begin()+pos);
            pos=lower_bound(bk[i/B].begin(),bk[i/B].end(),k)-bk[i/B].begin();
            bk[i/B].insert(bk[i/B].begin()+pos,k);
            arr[i]=k;
        }
    }
}
