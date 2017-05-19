#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n,m;
    char ch;
    scanf("%d %c",&n,&ch);
    if(n % 2 == 0)
    {
        m = n / 2;
    }
    else
    {
        m = (n + 1) / 2;
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
}