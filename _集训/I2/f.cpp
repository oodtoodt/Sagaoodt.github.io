#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
char s[1000000+5];
double dp[1000000+5][2];
int main(){
    while (~scanf("%s",s)){
        int len;
        freopen("foreign.in","r",stdin);
        freopen("foreign.out","w",stdout);
        len=strlen(s);
//        printf("%d\n",len);
//        printf("%s\n",s);
        if (s[0]=='W'){
            dp[0][0]=0;
            dp[0][1]=1;
        }
        else{
            dp[0][0]=1;
            dp[0][1]=0;
        }
        for (int i=1;i<len;i++){
            double p;
//            if(i == 0) p = 1;
            p=1.0/(len-i+1);
            if (s[i]=='W'){
                dp[i][0]=(1-p)*dp[i-1][0];
            }
            else{
                dp[i][0]=p+(1-p)*dp[i-1][0];
            }
            dp[i][1]= 1-dp[i][0];
        }
        double ans=0.0;
        for (int i=0;i<len;i++){
            if (s[i]=='W') ans+=dp[i][0];
            else ans += dp[i][1];
        }
        printf("%.10f\n",ans);
    }
    return 0;
}