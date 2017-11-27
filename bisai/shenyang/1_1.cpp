#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN=200100;

char str[MAXN];
int sa[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];
int Rank[MAXN],height[MAXN];
void build_sa(int s[],int n,int m)
{
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        for(i=n-j;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;
    }
}
void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)Rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[Rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[Rank[i]]=k;
    }
}

bool check(int n,int k,int t)
{
    int num=1;
    for(int i=2;i<=n;i++)
    {
        if(height[i]>=t)
        {
            num++;
            if(num>=k)return true;
        }
        else num=1;
    }
    return false;
}
int s[MAXN];
int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/shenyang/1.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        getchar();
        scanf("%s",str);
        int Max=0;
        n = strlen(str);
        for(int i=0;i<n;i++)
        {
            s[i] = str[i];
            Max=max(Max,s[i]);
        }
//        s[n]=0;
        build_sa(s,n+1,Max+1);
        getHeight(s,n);
        int l=0,r=n;
        int ans=0;/*
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(n,k,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }*/
        for(int i = 0; i <= n; i++)
        {
            printf("%d ",height[i]);
        }
        printf("\n");
    }
    return 0;
}
