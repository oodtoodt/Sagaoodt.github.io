/*
  ID: oodt
  PROG:
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
const int MAXN = 1010;
int N;
int f[MAXN],SG[MAXN],S[MAXN];
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //因为SG[0]始终等于0，所以i从1开始
    for(i = 1; i <= n; i++){
        //每一次都要将上一状态 的 后继集合 重置
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j < 20; j++)
        S[SG[i-f[j]]] = 1;  //将后继状态的SG函数值进行标记
        for(j = 0;; j++) if(!S[j]){   //查询当前后继状态SG值中最小的非零值
            SG[i] = j;
            break;
        }
    }
}
void init()
{
    memset(f,0,sizeof(f));
    f[0] = 1;
    f[1] = 2;
    f[2] = 3;
    for(int i = 3; ; i++)
    {
        f[i] = f[i-1]+f[i-2];
//        printf("%d ",f[i]);
        N = i;
        if(f[i] >= 1000) break;
    }

}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/4-博弈/sg/hdu1848.txt","r",stdin);
#endif
    int a,b,c;
    init();
    getSG(1000);
    while(scanf("%d%d%d",&a,&b,&c) && a)
    {
//        printf("%d %d %d\n",SG[a],SG[b],SG[c]);
        if(SG[a]^SG[b]^SG[c]) printf("Fibo\n");
        else printf("Nacci\n");
    }
    return 0;
}
