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
#include<queue>

using namespace std;

const int maxx=20005;
int n,m,k;
int a,b;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/2/2.txt","r",stdin);
#endif
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        q.push(a);
    }
    long long int sum = 0;
    if(q.size()==1)
    {
        sum+=q.top();
    }
    while(q.size()!=1)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        q.push(a+b);
        sum += a + b;
    }
    printf("%lld\n",sum);
    return 0;
}
