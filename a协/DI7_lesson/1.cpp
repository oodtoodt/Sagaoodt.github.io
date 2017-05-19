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

const int maxx=10005;
int n,m,k;
char line[5005];
char p1[5005],p2[5005];
char p[5005],pp[5005];
int ans;int len,len1,len2;
void input()
{
    int i;
    getchar();
    while(n--)
    {
        gets(line);
        memset(p1,0,sizeof(p1));
        memset(p,0,sizeof(p));
        memset(pp,0,sizeof(pp));
        memset(p2,0,sizeof(p2));
        ans = 0;
        len1 = 0;
        while(gets(line),strcmp(line,"END")!=0)
        {
            len = strlen(line);
            for(i = 0 ; i < len; i++)
            {
                p[len1++] = line[i];
            }
        }
//        p[len1 + 1] = '\0';
        for(i = 0; i < len1; i++)
        {
            if(p[i] != ' ' && p[i] != '\t' && p[i] != '\n')
            {
                pp[ans++] = p[i];
            }
        }
        ans = 0;
        gets(line);
        len2 = 0;
        while(gets(line),strcmp(line,"END")!=0)
        {
            len = strlen(line);
            for(i = 0 ; i < len; i++)
            {
                p1[len2++] = line[i];
            }
            if(len == 0)
            {
                p1[len2++] = '\n';
            }
        }
//        p1[len2+1] = '\0';
        for(i = 0; i < len2; i++)
        {
            if(p1[i] != ' ' && p1[i] != '\t' && p1[i] != '\n')
            {
                p2[ans++] = p1[i];
            }
        }
        if(strcmp(p,p1) == 0)
        {
            printf("Accepted\n");
        }
        else if(strcmp(pp,p2) != 0)
        {
            printf("Wrong Answer\n");
        }
        else
        {
            printf("Presentation Error\n");
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/DI7_lesson/1.txt","r",stdin);
#endif
    scanf("%d",&n);
    input();
    return 0;
}
