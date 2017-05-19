/*
  ID: oodt
  PROG:1772
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include <set>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
set<int > s;

bool judge(int temp)
{
    if(temp%10 ==0)    return false;
    if(!s.count(temp%10))    s.insert(temp%10);
    else return false;
    temp/=10;
    if(temp%10 ==0)    return false;
    if(!s.count(temp%10))    s.insert(temp%10);
    else return false;
    temp/=10;
    if(temp%10 ==0)    return false;
    if(!s.count(temp%10))    s.insert(temp%10);
    else return false;
    return true;
}

int main()
{
    for(int i = 100; i < 333; i++)
    {
        s.clear();
        if(judge(i))
        {
//            printf(".");
            int i1 = i * 2;
            if(judge(i1))
            {
                int i2 = i * 3;
                if(judge(i2))
                {
                    printf("%d %d %d\n",i,i1,i2);
                }
                else
                {
//                    printf("%d %d %d\n",i,i1,i2);
                    continue;
                }
            }
            else continue;
        }
        else continue;
    }
    return 0;
}
