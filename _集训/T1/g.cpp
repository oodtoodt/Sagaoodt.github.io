#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=25;
int n,m,k;
int a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
bool vis[maxx][maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T1/g.txt","r",stdin);
#endif
    int T;
    char ch[10];
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        scanf("%d%s",&n,ch);
//        printf("%d,%c\n",n,ch[0]);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        if(ch[0] == 'd')
        {
//            for(int i = 0; i )
            for(int j = 0 ; j < n; j++)
            {
                for(int i = n-2 ; i >= 0; i--)
                {
                    int p = i+1;
                    int t = a[i][j];
                    a[i][j] = 0;
                    while(a[p][j] == 0 && p != n-1)
                    {
                        p++;
                    }
                    if(p == n-1 && a[p][j] == 0)
                    {
//                        vis[i][p] = true;
                        a[p][j] = t;
                        continue;
                    }
                    if(a[p][j] == t && !vis[p][j])
                    {
                        a[p][j] = a[p][j] * 2;
                        vis[p][j] = true;
                    }
                    else
                    {
                        a[p-1][j] = t;
//                        vis[i][p+1] = true;
                    }
                }
            }
        }
        else if(ch[0] == 'r')
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = n-2; j >= 0; j--)
                {
                    int p = j+1;
                    int t = a[i][j];
                    a[i][j] = 0;
                    while(a[i][p] == 0 && p != n-1)
                    {
                        p++;
                    }
                    if(p == n-1 && a[i][p] == 0)
                    {
//                        vis[i][p] = true;
                        a[i][p] = t;
                        continue;
                    }
                    if(a[i][p] == t && !vis[i][p])
                    {
                        a[i][p] = a[i][p] * 2;
                        vis[i][p] = true;
                    }
                    else
                    {
                        a[i][p-1] = t;
//                        vis[i][p-1] = true;
                    }
                }
            }
        }
        else if(ch[0] == 'l')
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 1; j < n; j++)
                {
//                    if(a[i][j] == 0) continue;
                    int p = j-1;
                    int t = a[i][j];
                    a[i][j] = 0;
                    while(a[i][p] == 0 && p != 0)
                    {
                        p--;
                    }
                    if(p == 0 && a[i][p] == 0)
                    {
//                        vis[i][p] = true;
                        a[i][p] = t;
                        continue;
                    }
                    if(a[i][p] == t && !vis[i][p])
                    {
                        a[i][p] = a[i][p] * 2;
                        vis[i][p] = true;
                    }
                    else
                    {
                        a[i][p+1] = t;
//                        vis[i][p+1] = true;
                    }
                }
            }
        }
        else
        {
            for(int j = 0 ; j < n; j++)
            {
                for(int i = 1 ; i < n; i++)
                {
                    int p = i-1;
                    int t = a[i][j];
                    a[i][j] = 0;
                    while(a[p][j] == 0 && p != 0)
                    {
                        p--;
                    }
                    if(p == 0 && a[p][j] == 0)
                    {
//                        vis[i][p] = true;
                        a[p][j] = t;
                        continue;
                    }
                    if(a[p][j] == t && !vis[p][j])
                    {
                        a[p][j] = a[p][j] * 2;
                        vis[p][j] = true;
                    }
                    else
                    {
                        a[p+1][j] = t;
//                        vis[i][p+1] = true;
                    }
                }
            }
        }
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%d",a[i][j]);
                if(j == n-1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
