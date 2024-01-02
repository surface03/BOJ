#include<bits/stdc++.h>
using namespace std;
char word[100][100];
int n,L,i,j,k,l,d[100][100][100],le,lk,ic,sum,mini;
int main(){
    scanf("%d%d",&n,&L);
    for(i=0;i<n;i++){
        scanf("%s",word[i]);
    }
    for(i=0;i<n;i++){
        le=strlen(word[i]);
        if(le>L)continue;
        if(le==L){
            for(j=0;j<le;j++){
                if(word[i][j]!=word[i][le-j-1])break;
            }
            if(j==le)d[le][0][i]++;
        }
        if(le<L){
            d[0][le][i]++;
        }
    }
    for(i=0;i<L;i++){
        for(j=0;j<L;j++){
            for(k=0;k<n;k++){
                for(l=0;l<n;l++){
                    if(d[i][j][k]==0)continue;
                    le=strlen(word[l]);
                    lk=strlen(word[k]);
                    if(i+j+le>L)continue;
                    if(i+j+le==L){
                        if(i>j){
                            if(le>=i-j){
                                for(ic=0;ic<i-j;ic++){
                                    if(word[k][lk-i+j+ic]!=word[l][le-1-ic])break;
                                }
                                if(ic!=i-j)continue;
                                for(ic=0;ic<le-i+j;ic++){
                                    if(word[l][ic]!=word[l][le-i+j-1-ic])break;
                                }
                                if(ic==le-i+j)d[i][j+le][l]+=d[i][j][k];
                                else continue;
                            }
                            else if(le<i-j){
                                for(ic=0;ic<le;ic++){
                                    if(word[k][lk-i+j+ic]!=word[l][le-1-ic])break;
                                }
                                if(ic!=le)continue;
                                for(ic=lk-i+j+le;ic<lk;ic++){
                                    if(word[k][ic]!=word[k][2*lk-i+j+le-ic-1])break;
                                }
                                if(ic==lk)d[i][j+le][l]+=d[i][j][k];
                                else continue;
                            }
                        }
                        else if(i<j){
                            if(le>=j-i){
                                for(ic=0;ic<j-i;ic++){
                                    if(word[k][j-i-ic-1]!=word[l][ic])break;
                                }
                                if(ic!=j-i)continue;
                                for(ic=0;ic<le-j+i;ic++){
                                    if(word[l][ic+j-i]!=word[l][le-ic-1])break;
                                }
                                if(ic==le-j+i)d[i+le][j][l]+=d[i][j][k];
                                else continue;
                            }
                            else if(le<j-i){
                                for(ic=0;ic<le;ic++){
                                    if(word[l][ic]!=word[k][j-i-ic-1])break;
                                }
                                if(ic!=le)continue;
                                for(ic=0;ic<j-i-le;ic++){
                                    if(word[k][ic]!=word[k][j-i-le-ic-1])break;
                                }
                                if(ic==j-i-le)d[i+le][j][k]+=d[i][j][k];
                                else continue;
                            }
                        }
                        else if(i==j){
                            for(ic=0;ic<le;ic++){
                                if(word[l][ic]!=word[l][le-ic-1])break;
                            }
                            if(ic==le)d[i+le][j][l]+=d[i][j][k];
                            else continue;
                        }
                        continue;
                    }
                    if(i>j){
                        mini=min(le,i-j);
                        for(ic=0;ic<mini;ic++){
                            if(word[l][le-ic-1]!=word[k][ic+lk-i+j])break;
                        }
                        if(ic==mini){
                            if(le<i-j)d[i][j+le][k]+=d[i][j][k];
                            else d[i][j+le][l]+=d[i][j][k];
                        }
                        else{
                            continue;
                        }
                    }
                    else if(i<j){
                        mini=min(le,j-i);
                        for(ic=0;ic<mini;ic++){
                            if(word[l][ic]!=word[k][j-i-ic-1])break;
                        }
                        if(ic==mini){
                            if(le<j-i)d[i+le][j][k]+=d[i][j][k];
                            else d[i+le][j][l]+=d[i][j][k];
                        }
                        else{
                            continue;
                        }
                    }
                    else if(i==j){
                        if(i+j+le==L){
                            for(ic=0;ic<le;ic++){
                                if(word[l][ic]!=word[l][le-ic-1])break;
                            }
                            if(ic==le)d[i+le][j][k]+=d[i][j][k];
                        }
                        else{
                            d[i][j+le][l]+=d[i][j][k];
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=L;j++){
            sum+=d[j][L-j][i];
        }
    }
    printf("%d",sum);
}