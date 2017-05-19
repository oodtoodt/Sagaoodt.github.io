#include <cstdio>
#include <algorithm>

bool data[21][21];

int main()
{
    int n, m, k;
    while(scanf("%d%d%d",&n,&m,&k) != 0)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ;j++)
            {
                cout<<data[i][j];
            }
        }
        
    }
}