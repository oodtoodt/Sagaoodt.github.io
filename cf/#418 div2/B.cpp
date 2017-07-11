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
#include <map>
using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
int b[maxx];
map<int,int> data;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#418 div2/B.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        data.insert(make_pair(i+1,1));
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
    }
    int pos1 = -1,pos2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i] && pos1 == -1)
        {
//            printf("%d\n",i);
            pos1 = i;
            continue;
        }
        if(a[i] != b[i] && pos1 != -1)
        {
            pos2 = i;
            continue;
        }
        data[a[i]] = 0;
    }
//    printf("%d",data[b[pos1]]);
    if(pos2 == 0)
    {
        int t;
        for(int i = 1; i <= n; i++)
        {
            if(data[i] != 0)
            {
                t = i;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(i != pos1) printf("%d",a[i]);
            else printf("%d",t);
            if(i != n-1)
            printf(" ");
            else {
                printf("\n");
            }
        }
        return 0;
    }
    if(data[a[pos1]] == 0){
        if(data[b[pos2]] != 0) a[pos1] = b[pos2];
        if(data[b[pos1]] != 0) a[pos1] = b[pos1];
    }
    else if(data[a[pos2]] == 0){
        if(data[b[pos2]] != 0) a[pos2] = b[pos2];
        if(data[b[pos1]] != 0) a[pos2] = b[pos1];
    }
    else{
        if(data[b[pos2]] != 0) a[pos2] = b[pos2];
        else if(data[b[pos1]] != 0) a[pos1] = b[pos1];
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
        if(i != n-1) printf(" ");
        else printf("\n");
    }
    return 0;
}
