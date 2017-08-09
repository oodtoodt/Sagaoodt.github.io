#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=1005;
int n,m,k;
int a[maxx][maxx];
int F[maxx*maxx];
int cnt;
struct Edge{
    int u,v,cost;
}edge[maxx*maxx*5];
int cmp(Edge a,Edge b)
{
    return a.cost<b.cost;
}
int find(int x)
{
    if(F[x] == -1) return x;
    else return F[x] = find(F[x]);
}
int tol;
void addedge(int u,int v,int cost)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].cost = cost;
//    printf("%d %d %d\n",u,v,cost);
}
int kruskal(int n)
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    int ans = 0;
    int cnt = 0;
    for(int i = 0 ; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int c = edge[i].cost;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2)
        {
            ans += c;
            F[t1] = t2;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;
    else return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T4/h.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        tol = 0;
        scanf("%d%d",&n,&m);
//        printf("???\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == n-1 && j == m-1) break;
                else if(j == m-1)
                {
                    addedge((i+1)*m+j,j+i*m,abs(a[i][j]-a[i+1][j]));
//                    addedge(i-1,j,abs(a[i]-a[j]));
                }
                else if(i == n-1) addedge(i*m+j,j+1+i*m,abs(a[i][j]-a[i][j+1]));
                else
                {
                    addedge((i+1)*m+j,j+i*m,abs(a[i+1][j]-a[i][j]));
                    addedge(i*m+j,j+1+i*m,abs(a[i][j]-a[i][j+1]));
                }
//                else if(i == n-1) addedge(i-1,j,abs(a[i]-a[j]));
//                a[i][j]
            }
        }
//
        int res = kruskal(n*m);
        printf("Case #%d:\n",++cnt);
        printf("%d\n",res);
    }
    return 0;
}
