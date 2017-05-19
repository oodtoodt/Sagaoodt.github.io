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
    freopen("/Users/ecooodt/Desktop/c++ and acm/tianti/5-9/input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    getchar();
    string line,ss;
    set <int > data[55];
    for(int i = 1; i < n + 1; i++)
    {
        getline(cin,line);
        stringstream ss(line);
        int m;
        ss>>m;
        for(int j = 0; j < m; j++)
        {
            int temp;
            ss>>temp;
            //  cout<<temp<<" ";
            data[i].insert(temp);
        }
        //      cout<<endl;
    }
    int nn;
    scanf("%d",&nn);
    for(int i = 0; i < nn; i++)
    {
        int a,b;
        int same = 0;
        scanf("%d%d",&a,&b);
        for(set <int> :: iterator it = data[a].begin(); it != data[a].end(); ++it)
        {
            if(data[b].find(*it) != data[b].end())
            {
                //    printf("ok ");
                same++;
            }
        }
        int fenmu = data[a].size() + data[b].size() - same
            ;//这里是不同的总数
        double d = same * 1.0 / fenmu * 100;
//        printf("%d,%d",data[a].size(),data[b].size());
//        printf("same=%d / fenmu=%d    ", same, fenmu);
        printf("%.2f%%\n", d);
    }
}
