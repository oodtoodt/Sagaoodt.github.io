#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;
/*dp[i][j]指前j项含有i个字段的最大值，并且第i个字段包含a[j]。
那么分为，a[j]单独组成第i个字段，或者a[j]和前面的字符共同组成第i个字段
状态转移方程：dp[i][j]=max{dp[i][j-1]+list[j],dp[i-1][k]+list[j]} && i-1<=k<=j-1
那么最大值就是max(dp[m][j])*/
int dp[N][N],list[N];
int max(int a,int b){return a>b?a:b;}

int main(){
    int n,m,i,j,k;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&list[i]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++){
            for(j=i;j<=n;j++)
                if(j>i)
                {   
                    for(k=i-1;k<=j-1;k++){
                        dp[i][j]=max(dp[i][j-1]+list[j],dp[i-1][k]+list[j]);
                    }
                }
                else{   //i和j相等
                    dp[i][j]=dp[i-1][j-1]+list[i];
            }
        }
        int sum=0;
        for(j=1;j<=n;j++){
            sum=max(sum,dp[m][j]);
        }
        cout<<sum<<endl;
    }
return 0;
}