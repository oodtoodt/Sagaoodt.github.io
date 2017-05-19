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
    int a;
    scanf("%d",&a);
    int t = pow(2, a) + 0.5;
    printf("2^%d = %d",a,t);
}