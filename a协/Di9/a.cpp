#include <cstdio>
#include <iostream>
using namespace std;

short int vis[25000005];
int a,b,c,d,e;

int main()
{
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e) == 5)
    {
        for(int x1 = -50; x1<=50; x1++)
        {
            if(x1==0)continue;
            for(int x2 = -50;x2<=50;x2++)
            {
                if(x2==0)continue;
                int temp = a*x1*x1*x1+b*x2*x2*x2;
                if(tmp<0)
                {
                    temp = temp +INF;
                }
                vis[temp]++;
            }
        }
        for(int x3=-50;x3<=50;x3++)
        {
            if(x3==0)continue;
            for..
                if..
                for..
                    if...
                        int temp = c* x3 *x3 *x3 + d * x4 *x4 * x4 +e * x5 * x5 * x5;
            if(temp<0)temp=temp+INF;
            ans += vis[temp];
        }
    }
}


char a[10][10];
int m [10][10];

int c[10];
int n,k;
void dfs()
{

    if(cur == k)
    {
        ans++;
        return;
    }
    else
    {
        for(int x = i+1;x<n;x++)
        {
            fpr(int j = 0;j < n; j++)
            {
                if(m[x][j]==1&&c[j]==0)
                {
                    c[j]=1;
                    dfs(x,cur+1);
                    c[j]=0;
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&k) == 2)
    {
        for(int i = 0; i < n; i++)
        {
            gets(a[i]);
            for(int j = 0; j < n; j++)
            {
                if(=='#')
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(m[i][j] == 1)
                {
                    c[i] = 1;
                    dfs(i,1);
                }
            }
        }
    }
}





char temp[3005];
while(gets(temp))
{
    if(strcmp(temp,"END"))
    {
        break;
    }
    for(int i = 0; i< strlen(temp);i++)
    {
        if(temp[i] >= 'a' && temp[i] <= 'z')
        {
            a[k++]=temp[i];
        }
        else
        {
            a[k] = 0;
            k=0;
            string ss(a);//what the fuck????
            if(M.find(ss))
        }
    }
}