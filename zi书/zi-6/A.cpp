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
#endif
    char ch,ch2;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        init();
//        getchar();
        while( (ch = getchar()) && ch != '\n')
        {
            if(ok)
                continue;
            printf("%c",ch);
            if(ch == '(' || ch == '[')  s.push(ch);
            else{
                if(s.empty()){
                    printf("No\n");
                    ok = true;
//                    break;
                    continue;
                }
                ch2 = s.top();
                s.pop();
//printf("%c %c\n",ch,ch2);
                if(!((ch2 == '(' && ch == ')') || (ch == ']' && ch2 == '['))){
                    printf("No\n");
                    ok = true;
//                    break;
                }
            }
        }
        cout<<endl;
        if(!ok)
        printf("Yes\n");
    }
    return 0;
}
