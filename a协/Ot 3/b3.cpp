#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10],type[1100][11],t1[11],t2[11];
int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 3/b.txt","r",stdin);
    int i,j,k,n;
    while(~scanf("%d",&n))
    {
        memset(type,'n',sizeof(type));//江整个字符串初始化成n；
        int count=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            int len = strlen(s);
            k=0;
            for(j=0;j<len;j++)
            {
                int x = s[j] - '0';
                if(type[i][x] == 'n')
                {
                    type[i][x] = 'y';//如果该位置上的数字没有标记过就标记下来，如果已经标记过就不做处理。
                    k++;
                    if(k == 10)//总共有九个数，超过十的数不计算。
                        break;
                }
            }
            type[i][10] = '\0';
        }
        for(i=0;i<n;i++)
        {

            if(strcmp(type[i],"nnnnnnnnnn")==0)
                continue ;
             strcpy(t1,type[i]);
            for(j=i+1;j<n;j++)
            {
                strcpy(t2,type[j]);
                if(strcmp(t1,t2) == 0)
                    strcpy(type[j],"nnnnnnnnnn");
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}