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
#include <vector>

using namespace std;

const int maxx=15;
int n,m,k;
char a[maxx][maxx];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool ok(int x,int y)
{
    if(x >= 0 && x < n)
    {
        if(y >= 0 && y < m)
        {
            return 1;
        }
    }
    return 0;
}

struct node{
    int x,y;
    node(int a,int b){
        x = a;
        y = b;
    }
    node(){}
};
vector<node> data;
int sum = 0;

void judge()
{
    node p[64];
    int t = 0;
    for(vector<node>::iterator it = data.begin(); it != data.end(); ++it)
    {
        p[t++] = (*it);
    }
    for(int i = 0 ; i < t; i++)
    {
        node p1 = p[i];
        for(int j = i+1; j < t; j++)
        {
            node p2 = p[j];
            int x = abs(p1.x - p2.x);
            int y = abs(p1.y - p2.y);
            if((x == 2 && y == 0 )|| (y == 2 && x == 0))
            {
                sum ++;
            }
            if((x == 1 && y == 0) || (x == 0 && y == 1))
            {
                sum += 2;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a组/2214.txt","r",stdin);
#endif
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c",&a[i][j]);
            if(a[i][j] == '*'){
                ans ++;
            }
        }
    }
//    printf("%c",a[2][1]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int cnt = 0;
            if(a[i][j] == '*')
            {
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    //                  printf("%d %d , %d %d\n",i,j,nx,ny);
                    if(ok(nx,ny) && a[nx][ny] == '*')
                    {
                        cnt ++;
//                        printf("\t%d %d\n",nx,ny);
                    }
                }
                if(cnt == 3 && (x == 0 || y == 0 || x == n - 1 || y == m - 1)){
                    node p(i,j);
                    data.push_back(p);
                }
                if(cnt == 2)
                {
                    if(x == 0 || x == n-1)
                    {
                        if(y == 0 || y = m - 1)
                        {
                            node p(i,j);
                            data.push_back(p);
                        }
                    }
                }
//                printf("\n");
                if(cnt == 4)
                {
                    node p(i,j);
                    data.push_back(p);
//                    printf("???");
                }
            }
        }
    }
    judge();
    int t = data.size()*5 - sum ;
    if(ans != t){
        printf("-1\n");
    }
    else{
        printf("%lu\n",data.size());
    }
    return 0;
}
