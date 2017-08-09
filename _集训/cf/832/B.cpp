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
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxx=100050;
int n,m,k;
char a[maxx];
char good[maxx];
char ques[maxx];
int go[maxx];
int go2[maxx];
int ans = 0,cnt = 0,pos = 0;
int cntt = 0;
int l = 0,r = 0;
set<char> s;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/cf/832/B.txt","r",stdin);
#endif
    scanf("%s",good);
    int goodn = strlen(good);
    for(int i = 0; i < goodn; i++)
    {
        s.insert(good[i]);
    }
    scanf("%s",a);
    int lena = strlen(a);
    pos = INF;
    for(int i = 0; i < lena; i++)
    {
        if(a[i] == '?')
        {
            go[cnt++] = i;
        }
        if(a[i] == '*')
        {
            pos = i;
            break;
        }
    }
    for(int i = lena-1; i > pos; i--)
    {
        if(a[i] == '?')
        {
            go[cntt++] = lena - i;
        }
    }
    scanf("%d",&n);
    getchar();
    bool flag;
    while(n--)
    {
//        printf("%d",pos);
        flag = true;
        scanf("%s",ques);
        int cnt1 = 0;
        for(int i = 0; i < pos && i < lena; i++)
        {
            if(i == go[cnt1] && cnt1 < cnt)
            {
                cnt1++;
                if(!s.count(ques[i]))
                {
                    flag = false;
                    break;
                }
            }
            else if(a[i] != ques[i]){
                flag = false;
                break;
            }
        }
        int cnt2 = 0;
        int t = strlen(ques);
        int r ;
        for(int i = strlen(ques)-1;; i--)
        {
            if(pos > i) break;
            r = t - i;
            if(r == go[cnt2] && cnt2 < cntt)
            {
                cnt2++;
                if(!s.count(ques[i]))
                {
                    //printf("ok");
                    flag = false;
                    break;
                }
            }
            else if(a[lena-r] != ques[i])
            {
                //printf("ok");
                flag = false;
                break;
            }
            if(lena-r == pos + 1) {
                r = i;
                break;
            }
        }
        for(int i = pos; i < r; i++)
        {
            if(s.count(ques[i]))
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
