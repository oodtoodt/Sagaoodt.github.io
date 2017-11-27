#include<algorithm>
#include<cstdio>
#include <cstring>
#include<set>

using namespace std;

const int maxx=4050;
int vis[maxx];
int n,m,l,r;
char aa[maxx];
char bb[maxx];
typedef long long ll;
ll a[maxx];
//ll az[maxx];
//ll bz[maxx];
set<ll> az;

int lena;
int lenb;
ll b[maxx];

int ok(int mid)
{
    if(mid == 0) return true;
    az.clear();
    for(int i = 0; i <= lena-mid; i++)
    {
        long long t = 0;
        for(int j = 0; j < mid; j++)
        {
            t += a[i+j];
        }
//        printf("a[] = %d\n",t);
        az.insert(t);
    }
    for(int i = 0; i <= lenb-mid; i++)
    {
        ll t = 0;
        for(int j = 0; j < mid; j++)
        {
            t += b[i+j];
        }
//        printf("b[] = %d\n",t);
        if(az.count(t))
        {
            return true;
        }
    }
    return false;
}

void erfen()
{
    int mid = r;
    int flag;
    while(l<=r)
    {
        if(ok(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
        mid = (l + r) / 2;
    }
    printf("%d\n",--l);
}


int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/I3/d.txt","r",stdin);
    scanf("%s%s",aa,bb);
    lena = strlen(aa);
    lenb = strlen(bb);
    r = min(lena,lenb);
    l = 0;
    for(int i = 0; i < lena; i++)
    {
        a[i] = 1 << (aa[i]-'a');
    }
    for(int i = 0; i < lenb; i++)
    {
        b[i] = 1 << (bb[i]-'a');
    }
//erfen();
    for(int i = r; i >= 0; i--)
    {
        if(ok(i)){
            printf("%d\n",i);
            break;
        }
        //if(i == 1) printf("%d\n",0);
    }
    return 0;
}
