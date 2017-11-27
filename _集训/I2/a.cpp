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
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
vector<char> v;
vector<char> all;
vector<char> da;
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
bool flag1,flag2,flag3;

int jud1(char ch)
{
    if(ch <= 'Z' && ch >= 'A')
    {
        return true;
    }
    return false;
}
int jud2(char ch)
{
    if(ch <= 'z' && ch >= 'a')
    {
        return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/I2/a.txt","r",stdin);
#endif
    string line;
    while(getline(cin,line))
    {
        for(int i = 0; i < line.size(); i++)
        {
            flag1 = false;
            if(jud1(line[i]) && jud2(line[i+1]) && i)
            {
                cnt = 0;
                v.push_back(line[i]);
                for(int j = i+1; j < line.size(); j++)
                {
                    if(line[j] == ' ' && !flag1)
                    {
                        flag1 = true;
                        continue;
                    }
                    else if(jud1(line[j]) && jud2(line[j+1]) && flag1)
                    {
                        v.push_back(line[j]);
                        cnt ++;
                        flag1 = false;
                    }
                    else if(!jud2(line[j]))
                    {
                        if(!cnt)
                        {
                            for(int k = i; k < j; k++) putchar(line[k]);
                            v.clear();
                        }
                        else
                        {
                            for(int k = 0; k < v.size(); k++)
                            {
                                printf("%c",v[k]);
                            }
                            v.clear();
                            printf(" (");
                            cout<<line.substr(i,j-i);
                            printf(")");
                        }
                        i = j-1;
                        break;
                    }
                    else if(flag1)
                    {
                        if(!cnt)
                        {
                            for(int k = i; k < j; k++) putchar(line[k]);
                            v.clear();
                        }
                        else
                        {
                            for(int k = 0; k < v.size(); k++)
                            {
                                printf("%c",v[k]);
                            }
                            v.clear();
                            printf(" (");
                            cout<<line.substr(i,j-i-1);
                            printf(") ");
                        }
                        i = j-1;
                        break;
                    }
                    else if(j == v.size()-1)
                    {
                        if(!cnt)
                        {
                            for(int k = i; k < j; k++) putchar(line[k]);
                            v.clear();
                        }
                        else
                        {
                            for(int k = 0; k < v.size(); k++)
                            {
                                printf("%c",v[k]);
                            }
                            v.clear();
                            printf(" (");
                            cout<<line.substr(i,j-i);
                            printf(")");
                        }
                        i = j-1;
                        break;
                    }
                }
            }
            else putchar(line[i]);
        }
        printf("\n");
    }
    return 0;
}
