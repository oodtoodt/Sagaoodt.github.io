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
int a[3][3];
char s[4][4];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int f[3][3];
int kim;
int check(int kim)
{
    if(a[0][0] == a[0][1] && a[0][0] == a[0][2] && a[0][0] == kim) return 1;
    if(a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] == kim) return 1;
    if(a[0][0] == a[1][0] && a[0][0] == a[2][0] && a[0][0] == kim) return 1;
    if(a[2][2] == a[1][2] && a[2][2] == a[0][2] && a[2][2] == kim) return 1;
    if(a[2][2] == a[2][1] && a[2][2] == a[2][0] && a[2][2] == kim) return 1;
    if(a[1][1] == a[0][2] && a[1][1] == a[2][0] && a[1][1] == kim) return 1;
    if(a[1][1] == a[1][2] && a[1][1] == a[1][0] && a[1][1] == kim) return 1;
    if(a[1][1] == a[2][1] && a[1][1] == a[0][1] && a[1][1] == kim) return 1;
    return 0;
}
int judge(int kim)
{
    if(check(kim)) return 1;
    int tot = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 0)
            {
                a[i][j] = kim;
                if(check(kim)) tot++;
                a[i][j] = 0;
            }
        }
    }
    if(tot >= 2) return 1;
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/FUZHOU_re/l.txt","r",stdin);
#endif
    int T;
    n = 3;
    scanf("%d",&T);
    bool flag;
    while(T--)
    {
        char ch[5];
        flag = false;
        for(int i = 0 ; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                scanf("%s",ch);
                    if(ch[0] == '.')
                    {
                        a[i][j] = 0;
                    }
                    else if(ch[0] == 'x')
                    {
                        a[i][j] = 1;
                    }
                    else a[i][j] = 2;
            }
        }
//        char ch[5];
        scanf("%s",ch);
        if(ch[0] == 'x') kim = 1;
        else kim = 2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == 0)
                {
                    a[i][j] = kim;
                    if(judge(a[i][j]))
                    {
                        flag = true;
                        //   break;
                    }
                    a[i][j] = 0;
                }
            }
        }
        if(flag) printf("Kim win!\n");
        else printf("Cannot win!\n");
    }
    return 0;
}
