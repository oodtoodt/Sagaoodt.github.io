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
#include <sstream>

using namespace std;

const int maxx=15;
int n,m,k;
int a[maxx];
int cnt = 0;
int minn = 1000;


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/8.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        cnt = 0;
        string line;
        getline(cin,line);
        line.erase(remove(line.begin(),line.end(),' '),line.end());
//        cout<<line<<endl;

        int length = line.length();
        int cut = length / 2;
        int permute = 1 << length;
        string s = line;

        do
        {
            bitset<10>used = static_cast<bitset<10> >(permute);
            string s1,s2;
            cout<<used<<endl;
            for(int i = 0; i < length; i++)
            {
                if(used[i])
                {
                    s1 += s[i];
                }
                else
                {
                    s2 += s[i];
                }
            }
            if(s1.size() != cut) continue;
            if(s1[0] == '0' && s1.size() > 1){
                continue;
            }
            cout<<s1<<endl;
            do{
                int n1 = atoi(s1.c_str());
                do{
                    if(s2[0] == '0' && s2.size() > 1) continue;
                    int n2 = atoi(s2.c_str());
                    minn = min(minn,abs(n1-n2));
                }while(next_permutation(s2.begin(),s2.end()));
            }while(next_permutation(s1.begin(),s1.end()));
        }while(permute--);
        printf("%d\n",minn);
    }
    return 0;
}
