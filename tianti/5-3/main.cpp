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
    freopen("/Users/ecooodt/Desktop/c++ and acm/tianti/5-3/input.txt","r",stdin);
    string A;
    string B;
    string C;
    getline(cin,A);
    getline(cin,B);

    printf("%s\n%s\n",A.c_str(),B.c_str());
    for(int i = 0; i < A.length(); i++)
    {
        if(B.find(A[i]) == string::npos)
        {
            C += A[i];
        }
        
    }
    cout<<C<<endl;
}
