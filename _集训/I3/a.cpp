#include<algorithm>
#include<cstdio>

using namespace std;

const int maxx=200005;
int vis[maxx];
int n,m;
int a[maxx];

int main()
{
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        //if(vis[a[i]])
    }
    for(int i = m - 1; i >= 0; i--)
    {
        if(!vis[a[i]])
        {
            vis[a[i]] = true;
            printf("%d\n",a[i]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) printf("%d\n",i);
    }
    return 0;
}
