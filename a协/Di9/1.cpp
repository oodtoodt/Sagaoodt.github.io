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
#include <map>
#include <sstream>
#include <vector>

using namespace std;

const int maxx=10005;
int n,m,k = 0;
map <string ,string> dic;
vector <string> book;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di9/1.txt","r",stdin);
#endif
    string line;
    getline(cin,line);
    while(getline(cin,line),line != "END")
    {
        stringstream ss(line);
        string front,behind;
        ss>>front>>behind;
        dic[behind] = front;
    }
    cin>>line;
    
    return 0;
}
