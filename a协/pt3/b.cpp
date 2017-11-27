#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while (T--){
        char st1[100000+10],st2[100000+10];
        scanf("%s %s",st1,st2);
        int l1,l2;
        l1=strlen(st1);
        l2=strlen(st2);
        if (l1>l2) l1=l2;
        int c1[27]={0},c2[27]={0};
        for (int i=0;i<l1;i++){
            c1[st1[i]-'a'+1]++;
        }

        for (int i=0;i<l2;i++){
            c2[st2[i]-'a'+1]++;
        }
        //for (int i=1;i<=26;i++)
        //    printf("%d %d %d \n",i,c1[i],c2[i]);
        int ans=0;
        for (int i=1;i<=26;i++){
            //if (c1[i]!=0&&c2[i]!=0)
                ans+=c1[i]<c2[i]?c1[i]:c2[i];
        //printf("%d %d\n",i,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}