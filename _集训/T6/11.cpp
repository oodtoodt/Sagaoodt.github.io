//nupt2017team05
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
using namespace std;
const int INF=0x7fffffff;
const int MAXN=100000+10;
struct Rec
{
    int num,len;
    bool operator < (const Rec &a) const
    {
        return len>a.len;
    }
};
int u[MAXN*2],v[MAXN*2],w[MAXN*2];
int dis[MAXN],secondis[MAXN];
int first[MAXN],nextt[MAXN*2];
int n,r;

void dijkstra()
{
    priority_queue<Rec> que;

    for (int i=1;i<n;i++)
    {
         dis[i]=INF;
         secondis[i]=INF;
    }
    dis[0]=0;
    secondis[0]=INF;

    Rec temp;
    temp.len=0;temp.num=0;
    que.push(temp);

    while (!que.empty())
    {
        Rec head=que.top();
        que.pop();
        if (head.len>secondis[head.num]) continue;

        int k=first[head.num];
        while (k!=-1)
        {
            int d=head.len+w[k];
            if (dis[v[k]]>d)
            {
                swap(dis[v[k]],d);
                temp.len=dis[v[k]];temp.num=v[k];
                que.push(temp);
            }
            if (dis[head.num]<d && secondis[v[k]]>d)
            {
                secondis[v[k]]=d;
                temp.len=secondis[v[k]];temp.num=v[k];
                que.push(temp);
            }
            k=nextt[k];
        }
    }
}

int main()
{
    int t;
    cin>> t;
    while (t--)
    {
        scanf("%d%d",&n,&r);
        memset(first,-1,sizeof(first));
        for (int i=0;i<r;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            u[i]--;
            v[i]--;
            nextt[i]=first[u[i]];
            first[u[i]]=i;

            v[i+r]=u[i];
            u[i+r]=v[i];
            w[i+r]=w[i];
            nextt[i+r]=first[u[i+r]];
            first[u[i+r]]=i+r;
        }
        dijkstra();
        cout<<secondis[n-1]<<endl;
    }
    return 0;
}