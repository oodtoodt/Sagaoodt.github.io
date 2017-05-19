#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
const int maxx = 105;
int lcs[maxx][maxx];
int pos[maxx][maxx];
char a[105],b[105];

void print(int l, int r)
{
    if(!l && !r)
    return ;
    if(pos[l][r] == 0)
    {
        print(l-1,r-1);
        printf("%c",a[l-1]);
    }
    else if(pos[l][r] == -1)
    {
        print(l,r-1);
        printf("%c",b[r-1]);
    }
    else if(pos[l][r] == 1)
    {
        print(l-1,r);
        printf("%c",a[l-1]);
    }
    return ;
}

int main(int argc, char *argv[])
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/vjudge/njupt DP/1.txt","r",stdin);
#endif
    string line;
    while(scanf("%s %s",a,b) != EOF)
    {
        memset(pos,0,sizeof(pos));
        memset(lcs,0,sizeof(lcs));
//        cout<<a<<b;
        for(int i = 0; i <= strlen(a); i++)
        {
            pos[i][0] = 1;
        }
        for(int j = 0; j <= strlen(b); j++)
        {
            pos[0][j] = -1;
        }
        int n = 0, m = 0;
        for(n = 1; n <= strlen(a); n++)
        {
            for(m = 1; m <= strlen(b); m++)
            {
                if(a[n-1] == b[m-1])
                {
                    lcs[n][m] = lcs[n-1][m-1] + 1;
                    pos[n][m] = 0;
                }
                else
                {
                    if(lcs[n][m-1] > lcs[n-1][m])
                    {
                        lcs[n][m] = lcs[n][m-1];
                        pos[n][m] = -1;
                    }
                    else
                    {
                        lcs[n][m] = lcs[n-1][m];
                        pos[n][m] = 1;
                    }
                }
            }
        }
        print(strlen(a),strlen(b));
//        printf("%d,%d",strlen(a),strlen(b));
        printf("\n");
    }
    return 0;
}
