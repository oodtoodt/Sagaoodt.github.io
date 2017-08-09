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

using namespace std;

const int maxx=1000050;
int n,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

map<int,int > m;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p1/a.txt","r",stdin);
#endif
    while(scanf("%d",&n)&&n)
    {
        m.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
//            a[i].id = i+1;
        }
        for(int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        int t,t1 = -1,t2,cnt1,pos1,pos2;
        int dif;
        for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            t = it->second;
//            printf("%d\t",t);
            if(t & 1)
            dif = it->first;
        }
        printf("%d\n",dif);
        //if(cnt > 1) dif = pos1;
//        else dif = pos2;
        for(int i = 0 ; i < n; i++)
        {
            if(a[i] == dif)
            {
//                printf("%d\n",i+1);
//                break;
            }
        }
    }
    return 0;
}
