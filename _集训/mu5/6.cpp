#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    long long t;
    while (T--){
        long long n,m;
        scanf("%lld%lld",&n,&m);
        if (m<=n-1){
            t=n*n*(n-1)-(2*n-4)*(m+1)*m/2-2*m;
        }
        else{
            t=2*n*n-2*n-2*m;

        }
        printf("%lld\n",t);
    }
    return 0;
}
