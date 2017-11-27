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
#include<sstream>
#include<set>

using namespace std;

const int maxx=25;
int n,m,k;
int a[maxx][maxx];
int ans = 0,pos = 0,res = 0;
int l = 0,r = 0;
double d;
int cnt[maxx];
int LCS[21][21];
set<int> lcs_s[10000];
typedef long long LL;
const int p = 1e9+7;

void lcs(int l,int r)
{
    int i,j;
    memset(LCS,0,sizeof(LCS));
    for(i=1;i<cnt[l];i++)
    {
        for(j=1;j<cnt[r];j++)
        {
            if(a[l][i-1]==a[r][j-1])
            LCS[i][j]=LCS[i-1][j-1]+1;
            else
            LCS[i][j]= LCS[i-1][j]>LCS[i][j-1]? LCS[i-1][j]:LCS[i][j-1];
        }
    }
    int t = LCS[cnt[l]-1][cnt[r]-1];
    printf("%d\n",t);
    if(t >= k) traceBack(l,r);
}
int q = 0;
void traceBack(int l,int r)
{
    int i = cnt[l]-1;
    int j = cnt[r]-1;
    while (i>0 && j>0)
    {
        if (a[l][i-1] == a[r][j-1])
        {
            lcs_s[q].insert(a[l][i-1]);
            --i;
            --j;
        }
        else
        {
            if (LCS[i-1][j] > LCS[i][j-1])
                --i;
            else if (LCS[i-1][j] < LCS[i][j-1])
                --j;
            else   // 相等的情况
            {
                traceBack(i-1, j);
                traceBack(i, j-1);
                return;
            }
        }
    }
    for(int i = 0; i < q; i++)
    {
        for(int j = 0; j < q; j++)
        {
            
        }
    }
    q++;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/nanning/m.txt","r",stdin);
#endif
    string line;
    scanf("%d%lf",&n,&d);
    m = 0;
    getchar();
    while(getline(cin,line))
    {
//        cout<<line<<endl;
        stringstream ss(line);
        while(ss>>a[m][cnt[m]++]);
        m++;
    }
    d *= m;
    k = ceil(d);
    printf("%d\n",k);
    for(int i = 0 ; i < m; i++)
    sort(a[i],a[i]+cnt[i]-1);
//    printf("%lf\n",d);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < cnt[i]-1; j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = i+1; j < m; j++)
        {
            lcs(i,j);
        }
    }
    printf("\n%d\n",res);
    return 0;
}
