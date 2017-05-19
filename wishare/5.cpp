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
#include <set>

using namespace std;

typedef pair<int,int> P;
const int maxx=10005;
int n,k;
int a[maxx];
map<int ,int > m1;
map<int ,int > m2;
map<P,int> s;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/wishare/5.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        m1[a]++;
        m2[b]++;
        s[P(a,b)]++;
    }
    int cha = n - s.size();
    int sum = 0;
    for(map<int,int>::iterator it = m1.begin(); it != m1.end(); ++it)
    {
        sum += it->second*(it->second-1)/2;
    }
    for(map<int,int>::iterator it = m2.begin(); it != m2.end(); ++it)
    {
        sum += it->second*(it->second-1)/2;
    }
    for(map<P,int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        if(it->second > 1)
        {
            sum -= (it->second-1)*it->second/2;
        }
    }
    printf("%d\n",sum);
    return 0;
}
