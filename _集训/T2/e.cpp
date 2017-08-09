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
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        long long c;
        scanf("%lld",&c);
        int f=1;
        int a[21]={0};
        a[1]=100;
        long long p=2;
        while (c!=1){
            if (c%p!=0){
                p++;
                if (p>21){
//                    f=0;
                    break;
                }
                else{
                    if (a[p-1]>a[p-2]){
                         f=0;
                        break;
                    }
                }
            }
            else{
                c=c/p;
                a[p]++;
            }
            //printf("c:%d\n",c);
        }
        for (int i=2;i<=p;i++){
            if (a[i]>a[i-1]){
                f=0;
                break;
            }
        }
        if (f==0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}