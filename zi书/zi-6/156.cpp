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
#include <cctype>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
map<string,string> w_map;
set<string> w_set;
map<string,int> word;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/zi书/zi-6/156.txt","r",stdin);
#endif
    string s,s1;
    while(cin>>s)
    {
        w_map.clear();
        w_set.clear();
        word.clear();
        if(s[0] == '#') break;
        n = s.size();
        s1 = s;
        for(int i = 0; i < n; i++)
        {
            s[i] = tolower(s[i]);
//            printf("%c",s1[i]);
        }
//        cout<<s<<endl;
        sort(s.begin(),s.end());
        word[s]++;
        w_map[s1] = s;
        w_set.insert(s1);
    }
    for(auto it = w_set.begin(); it != w_set.end(); ++it)
    {
        if(word[w_map[*it]] == 1)
        cout<<*it<<endl;
    }
    return 0;
}
