/*
  ID: oodt
  PROG:poj1182
  LANG:C++
  照搬题解
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=2005;
int n,m,k;
//int a[maxx];
int sum;
int father[maxx];
int rak[maxx];
int er[maxx];

void init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        father[i] = i;//初始时指向自己
    }
    memset(rak,0,sizeof(rak));
}

int find_s(int x)
{
    if(x == father[x]) return x;//自己就是根
    int fx = find_s(father[x]);//寻找并集根
    rak[x] = (rak[x] + rak[father[x]]) % 3;//路径优化
    father[x] = fx;//
    return father[x];//返回根
}

bool un(int x,int y,int pos)
{
    int fx;
    int fy;
    fx = find_s(x);
    fy = find_s(y);
    if (fx == fy)
    {
        if((rak[y] - rak[x] + 3) % 3 != pos)
        {
            return true;
        }
        else return false;
    }
    father[fy] = fx;
    rak[fy] = (rak[x] - rak[y] + 3 + pos) % 3;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a组/A.txt","r",stdin);
#endif
    int d[maxx];
    int x[maxx],y[maxx];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(d,0,sizeof(d));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        int cnt = 0;
        memset(er,-1,sizeof(er));
//        init(n);
        for(int i = 0; i < m; i++)
        {
            char ch;
            scanf("%d",&x[i]);
            ch = getchar();
            while(ch != '>' &&ch != '<' && ch != '=') ch = getchar();
            scanf("%d",&y[i]);
            if(ch == '>')
            {
                d[i] = 2;
            }
            else if(ch == '=')
            {
                d[i] = 0;
            }
            else
            {
                d[i] = 1;
            }
        }
        for(int i = 0; i < n; i++)
        {
            init(n);
            for(int j = 0 ; j < m; j++)
            {
                if(x[j] == i || y[j] == i)//假设i是裁判，则与i相关都无效
                continue;
                if(un(x[j],y[j],d[j]))
                {
                    er[i] = j+1;//
                    break;
                }
//                cnt ++;
            }
        }
        sum = 0;
        int t = 0;
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(er[i] == -1)
            {
                cnt ++;
                t = i;
            }
            else{
                //       printf("")
            }
            sum = max(sum, er[i]);
        }

        if(!cnt)
            printf("Impossible\n");
        else if(cnt>1)
            printf("Can not determine\n");
        else
            printf("Player %d can be determined to be the judge after %d lines\n",t,sum);
    }
    return 0;
}
