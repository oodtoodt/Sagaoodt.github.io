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
#include <vector>
using namespace std;

const int maxx=1005;
int n,m,k;
int w[maxx];
int b[maxx];
int father[maxx];
int dp[maxx];
vector<int> v[maxx];
int ww[maxx];
int bb[maxx];

void init(){
    for(int i = 0; i <= n; i++)
    {
        father[i] = i;
        v[i].clear();
    }
}

int find_s(int x){
    if(x == father[x]) return x;
    int fx = find_s(father[x]);
    father[x] = fx;
    return father[x];
}

void un(int x,int y){
    int fx,fy;
    fx = find_s(x);
    fy = find_s(y);
    if(fx != fy)
    father[fy] = fx;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di16/1.txt","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i = 1; i <= n; i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d",&b[i]);
    }
    for(int i = 1; i <= m; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        un(x,y);
    }
    for(int i = 1; i <= n; i++)
    {
        v[find_s(i)].push_back(i);
        ww[find_s(i)] += w[i];
        bb[find_s(i)] += b[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)//i是访问到的点
    {
        //printf("?");
        if(v[i].empty())continue;
        for(int j = k; j >= 0; j--)//j是当前买的价值
        {
            for(int l = 0; l < v[i].size(); l++)//l遍历分组
            {
                if(j - w[v[i][l]] >= 0){
                    dp[j] = max(dp[j], dp[j-w[v[i][l]]] + b[v[i][l]]);
                }
            }
            if(j - ww[i] >= 0){
                dp[j] = max(dp[j], dp[j-ww[i]]+bb[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    printf("%d\n",dp[k]);
    return 0;
}
