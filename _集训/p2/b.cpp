#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<set>

using namespace std;

const int maxx=1005;
int n,m,k;
int a[maxx];
string str;
set<string> s;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p2/b.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    getchar();
    int a1 = 0,a2 = 0;
    int t = 0;
    if(n > m){
        printf("YES\n");
        return 0;
    }
    if(n < m){
        printf("NO\n");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        cin>>str;
//        cout<<str<<endl;
        s.insert(str);
    }
    for(int i = 0; i < m; i++)
    {
        cin>>str;
//        cout<<str<<endl;
        if(s.count(str)) t++;
    }
//    printf("%d\n",t);
    if(t & 1){
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}
