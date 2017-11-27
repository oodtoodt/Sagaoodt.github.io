#include<stdio.h>
int a[1005];
int main()
{
    #ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu8/8.txt","r",stdin);
#endif
    int T,n,k,i,begin,end;
    char c;
    scanf("%d",&T);
    while(T--)
    {
        begin=0;
        end=0;
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        scanf("%c",&c);
        for(i=1;i<=n;i++)
        {
            while(true)
            {
                scanf("%c",&c);
                if(c!=' ')break;
            }
            if(c=='L'){end=end+a[i];}
            if(c=='D'){begin=begin-a[i];}
            if(c=='N'){end=end+a[i];begin=begin-a[i];}
        }
        if(k<=end && k>=begin)printf("yes\n");
        else printf("no\n");

    }
    return 0;
}