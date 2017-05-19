/*
  ID: oodt
  PROG:hdu-2142
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include <set>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

const int maxx=10005;
int n,k;
int a[maxx];

struct node{
    string name;
    int n;
    bool operator<(const node &a)const{
        return n < a.n;
    }
}p;
map<string,int>m;
//set<node> data;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/10.txt","r",stdin);
#endif
    string line;
    while(getline(cin,line))
    {
        if(line[0] == 'Q') break;
        if(line[0] == 'N')
        {
            string temp;
            stringstream ss(line);
            ss>>temp;
            ss>>temp;
            int t;
            ss>>t;
            if(m.count(temp))
            {
                m[temp] = t;
                printf("update succeed\n");
                continue;
            }
            else
            {
                m[temp] = t;
                printf("A new record\n");
                continue;
            }
        }
        if(line[0] == 'M')
        {
            map<string,int>::iterator it;
            vector <string> v;
            v.clear();
            int maxi = 0;
            for(it = m.begin(); it != m.end(); ++it)
            {
                maxi=max(it->second,maxi);
            }
            int num = 0;
            for(it = m.begin(); it != m.end(); ++it)
            {
                if(it->second ==maxi)
                {
                    num ++;
                    v.push_back(it->first);
                }
            }
            sort(v.begin(),v.end());
            printf("%d %d\n",maxi,num);
            for(vector<string>::iterator i = v.begin(); i != v.end(); ++i)
            {
                printf("%s\n",(*i).c_str());
            }
        }
        if(line[0] == 'A')
        {
            map<string,int>::iterator it;
            double sum = 0;
            for(it = m.begin(); it != m.end(); ++it)
            {
                sum += it->second;
            }
            if(m.size()>0) sum /= m.size();
            printf("%.2f\n",sum);
        }
        if(line[0] == 'D')
        {
            map<string,int>::iterator it;
            string temp;
            stringstream ss(line);
            ss>>temp;
            bool fk = false;
            ss>>temp;
            for(it = m.begin(); it != m.end(); ++it)
            {
                if(it->first == temp)
                {
                    printf("delete succeed\n");
                    m.erase(it);
                    fk = true;
                    break;
                }
            }
            if(!fk)
            {
                printf("no such record\n");
            }
        }
    }
    return 0;
}
