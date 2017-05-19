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
    int a[3];
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a, a+3);
    printf("%d->%d->%d",a[0],a[1],a[2]);
    return 0;
}