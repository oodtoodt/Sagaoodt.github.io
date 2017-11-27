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
#include<stack>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
stack<char> s;
bool ok;

void init()
{
    ok = false;
    while(!s.empty()){
        s.pop();
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/zi书/zi-6/A.txt","r",stdin);
    freopen("/Users/ecooodt/Desktop/c++ and acm/zi书/zi-6/A-.txt","w",stdout);
#endif
    char ch,ch2;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        init();
        char ch;
        string ss;
        getline(cin,ss);
//        cout<<ss<<endl;
        m = ss.size();
        for(int j = 0; j < m; j++)
        {
            ch = ss[j];
            if(ok)
                continue;
//            printf("%c",ch);
            if(ch == '(' || ch == '[')  s.push(ch);
            else{
                if(s.empty()){
                    ok = true;
                    continue;
                }
                ch2 = s.top();
                s.pop();
                if(!((ch2 == '(' && ch == ')') || (ch == ']' && ch2 == '['))){
                    ok = true;
                }
            }
        }
        if(!s.empty()) {
            ok = true;
        }
        if(!ok)
        printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
