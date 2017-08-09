#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

const int MAXN=10000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}


int fac[10000][10000]={0};
int a[1000000+10];
int main(){
    int n;

    for (int i=2;i<=10000;i++){
        int tmp=i;
        for (int j=1;j<=prime[0];j++){
            if (tmp % prime[j]==0){
                fac[i][prime[j]]++;
                tmp%=prime[j];
            }
        }
    }
    while (~scanf("%d",&n)){
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int sum=0;
        for (int i=1;i<=n;i++){
            int tmp=a[i];
            int l=1,r=n;
            for (int j=i-1;j>=1;j--){
                if (a[j]==1){
                    l=j;
                    break;
                }
                int f=0;
                for (int k=2;k<=a[j];k++){
                    if (fac[a[j]][k]<fac[a[i]][k]){
                        f=1;
                        break;
                    }
                }
                if (f==0){
                    l=j;
                    break;
                }
            }
            for (int j=i+1;j<=n;j++){
                if (a[j]==1){
                    r=j;
                    break;
                }
                int f=0;
                for (int k=2;k<=a[j];k++){
                    if (fac[a[j]][k]<fac[a[i]][k]){
                        f=1;
                        break;
                    }
                }
                if (f==0){
                    r=j;
                    break;
                }
            }
            sum++;
            //printf("%d\n",1+(i-l)+(r-i)+(i-l)*(r-i));
        }
        printf("%d\n",sum);
    }
    return 0;
}

