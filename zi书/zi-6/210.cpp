#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<sstream>
#include<queue>

using namespace std;

const int maxx = 2000;
int a[26];
deque<int> q_wait;
queue<int> q_stop;
vector<string> v[maxx];
int pos[maxx];
bool have = false;

int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/zi书/zi-6/210.txt","r",stdin);
    freopen("/Users/ecooodt/Desktop/c++ and acm/zi书/zi-6/210_.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(pos,0,sizeof(pos));
        for(int i = 0; i < maxx; i++) v[i].clear();
        int n,ca,cb,cc,cd,ce,Q;
        scanf("%d %d %d %d %d %d %d\n",&n,&ca,&cb,&cc,&cd,&ce,&Q);
        for(int i = 0; i < n; i++)
        {
            string s;
            while(getline(cin,s))
            {
                v[i].push_back(s);
                if(s == "end") break;
            }
            q_wait.push_back(i);
        }
        while(!q_wait.empty())
        {
            int i = q_wait.front();
            q_wait.pop_front();
        //    printf("%d\t",i);
            int j = pos[i];
            int time = Q;
            int fk = 0;
            while(time > 0)
            {
                string ss = v[i][j];
                if(ss[2] == 'l')//unlock
                {
                    time -= cd;
                    have = false;
                    if(!q_stop.empty())
                    {
                        int t = q_stop.front();
                        q_stop.pop();
                        q_wait.push_front(t);
                    }
                }
                if(ss[1] == 'o')//lock
                {
                    time -= cc;
                    if(have) {
                        q_stop.push(i);
                        fk = 1;
                        break;
                    }
                    else have = true;
                }
                if(ss[1] == 'r')//print . 01234 6
                {
                    time -= cb;
                    printf("%d: %d\n",i+1,a[ss[6]-'a']);
                }
                if(ss[2] == '=')// =
                {
                    time -= ca;
                    stringstream sss(ss);
                    int t;
                    char ch;
                    char c;
                    sss>>c>>ch>>t;
                    a[c-'a'] = t;
                }
                if(ss[2] == 'd'){//end
                    fk = 1;
                    break;
                }
                pos[i] = ++j;
            }
          //  printf("%d\t",i);
            if(!fk) q_wait.push_back(i);
        }
        if(T) printf("\n");
    }
    return 0;
}