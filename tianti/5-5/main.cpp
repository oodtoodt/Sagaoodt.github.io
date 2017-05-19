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
    int n;
    scanf("%d",&n);
    int sum = 0,p = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            p *= j;
        }
        sum += p;
        p = 1;
    }
    cout<<sum<<endl;
}