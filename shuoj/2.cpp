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

using namespace std;

const int maxx=1005;
int n,m,k;
int a[maxx],b[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/shuoj/2.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&b[i]);
    }
    int l1 = 0,l2 = 0;
    bool draw = false;
    bool win1 = false;
    bool win2 = false;
    while(1){
        printf("%d,%d",l1,l2);
        if(l1 == n && l2 == m){
            draw = true;
            break;
        }
        if(l1 == n)
        {
            win2 = true;
            break;
        }
        if(l2 == n){
            win1 = true;
            break;
        }
        if(a[l1] == 31)
        {
            if(b[l2] == 32)
            {
                l1++;
                continue;
            }
            else if(b[l2] == 31)
            {
                draw = true;
                break;
            }
            else if(b[l2] == 30)
            {
                l1++;
                l2++;
                continue;
            }
            else{
                l2++;
                continue;
            }
        }
        if(a[l1] == 30)
        {
            l2++;
            l1++;
            continue;
        }
        if(b[l2] == 30)
        {
            l2++;
            l1++;
            continue;
        }
        if(b[l2] == 31)
        {
            if(a[l1] == 32)
            {
                l2++;
                continue;
            }
            else
            {
                l1++;
            }
        }
        else
        if(b[l2] > a[l1])
        {
            l1++;
        }
        else if(b[l2] < a[l1])
        {
            l2++;
        }
        else{
            l1++;
            l2++;
        }
    }
    if(draw)
    {
        printf("Draw\n");
        return 0;
    }
    if(win1)
    {
        printf("First\n");
        return 0;
    }
    if(win2)
    {
        printf("Second\n");
        return 0;
    }
    return 0;
}
