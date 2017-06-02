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
#include <queue>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];

const int INF = 100000000;
int dx[4] = {1,-1,4,-4};
//int dy[4] = {1,-1,0,0};
typedef pair <int,int> P;
queue<string> que;
map<string,int> d;
int sx,sy;
int ex,ey;

bool judge(int x){
    if(x >= 0 && x < 8)
    {
        return true;
    }
    return false;
}

void bfs()
{
    for(int i = 0; i < n; i++){
//        d[i] = 0;//初始化
    }
//    d.clear();
    int x;
    que.push("01234567");
    d["01234567"] = 1;
//    d[sx][sy] = 0;//并把距离设为0；
    while(que.size()){//直到队列为空
        string p = que.front();
        que.pop();
        int pos = 0;
        for(int i = 0; i < 8; i++){
            if(p[i] == '0'){
                x = i;
//                break;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            if(judge(nx) && !(x == 3 && i == 0) && !(x == 4 && i == 1))
            {
                string pp = p;
//                char t = p[x];
                swap(pp[x],pp[nx]);
//                pp[x] = p[nx];
//                pp[nx] = t;
                if(!d[pp]){
                    que.push(pp);
                    d[pp] = d[p] + 1;
                }
            }
        }
    }
//    return d[ex][ey];
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/7.txt","r",stdin);
#endif
    bfs();
//    printf("%d",d["10234567"]);
    string s;
    char ch;
    int cnt = 0;
    while(1)
    {
        for(int i = 0 ; i < 8 ; i++)
        {
            ch = getchar();
            getchar();
            s += ch;
            if(ch == EOF){
                return 0;
            }
        }
//            s[cnt] = '\0';
//            cnt = 0;
//            printf("%s\n",s.c_str());
//            printf("%c\n",s[]);
        printf("%d\n",d[s]-1);
//            cout<<endl;
        s.clear();
    }
    return 0;
}
