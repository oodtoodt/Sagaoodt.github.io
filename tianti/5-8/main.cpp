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
    freopen("/Users/ecooodt/Desktop/c++ and acm/tianti/5-8/input.txt","r",stdin);
    const int quan[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    string s;
    int n;
    scanf("%d",&n);
    getchar();
    bool bo = false;
    int sum = 0,m;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        getline(cin,s);
        for(int j = 0; j < 17; j++)
        {
            sum += (s[j] - 48) * quan[j];
        }
        sum %= 11;
        if(sum >= 3)
        {
            m = (12 - sum) + '0';
        }
        else if(sum != 2)
        {
            m = (1 - sum) + '0';
        }
        else
        {
            m = 'X';
        }
        if(s[17] != m)
        {
            cout<<s<<endl;
            bo = true;
        }
//        printf("s[17] = %c,m=%c\n",s[17],m);
    }
    if(!bo)
    {
        printf("All passed");
    }
}