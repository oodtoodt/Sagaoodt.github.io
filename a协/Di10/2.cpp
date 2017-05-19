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

using namespace std;

const int maxx=50005;
int n,m,k;
struct p{
    int a;
    int id;
}data[maxx];
char ch[maxx][100];

int cmp(struct p a,struct p b)
{
    return a.a>b.a;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di10/2.txt","r",stdin);
#endif
    while(scanf("%d",&n)&&n!=0)
    {
        for(int i = 0 ; i < n ; i++)
        {
            int t;
            scanf("%s",ch[i]);
//            printf("%s%d",ch[i],ch[i][strlen(ch[i])-1]-'0');
            data[i].a = ch[i][strlen(ch[i])-1] - '0';
//            printf("%d",data[i].a);
        }
        sort(data,data+n,cmp);
//        printf("%d",data[0].a);
        int root = data[0].id;
        int pos = 0;
        for(int i = 1; i < n; i++)
        {
            if(data[i].id < root)
            {
                r[]
            }
        }
        printf("\n");
    }
    return 0;
}
