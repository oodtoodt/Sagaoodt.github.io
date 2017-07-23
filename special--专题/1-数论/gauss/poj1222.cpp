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
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

//对2取模的01方程组
const int MAXN = 300;
//有equ个方程，var个变元。增广矩阵行数为equ,列数为var+1,分别为0到var
int equ,var;
int a[MAXN][MAXN]; //增广矩阵
int x[MAXN]; //解集
int free_x[MAXN];//用来存储自由变元（多解枚举自由变元可以使用）
int free_num;//自由变元的个数

//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss()
{
    int max_r,col,k;
    free_num = 0;
    for(k = 0, col = 0 ; k < equ && col < var ; k++, col++)
    {
        max_r = k;
        for(int i = k+1;i < equ;i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
            max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;//这个是自由变元
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var+1; j++)
            swap(a[k][j],a[max_r][j]);
        }
        for(int i = k+1;i < equ;i++)
        {
            if(a[i][col] != 0)
            {
                for(int j = col;j < var+1;j++)
                a[i][j] ^= a[k][j];
            }
        }
    }
    for(int i = k;i < equ;i++)
    if(a[i][col] != 0)
    return -1;//无解
    if(k < var) return var-k;//自由变元个数
    //唯一解，回代
    for(int i = var-1; i >= 0;i--)
    {
        x[i] = a[i][var];
        for(int j = i+1;j < var;j++)
        x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}
void init()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    equ = 5*6;
    var = 5*6;
    for(int i = 0;i < 5;i++)
    for(int j = 0;j < 6;j++)
    {
        int t = i*6+j;
        a[t][t] = 1;
        if(i > 0)a[(i-1)*6+j][t] = 1;
        if(i < 5-1)a[(i+1)*6+j][t] = 1;
        if(j > 0)a[i*6+j-1][t] = 1;
        if(j < 6-1)a[i*6+j+1][t] = 1;
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/gauss/poj1222.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        for(int i = 0; i < 30; i++)
        {
            scanf("%d",&a[i][30]);
        }
        Gauss();
        printf("PUZZLE #%d\n",cnt++);
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%d ",x[i*6+j]);
            }
            printf("%d\n",x[i*6+6]);
        }
    }
    return 0;
}
