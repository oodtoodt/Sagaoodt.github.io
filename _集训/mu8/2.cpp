#include <cstring>
#include <cstdio>

using namespace std;

int euler[1000005];
void geteuler()
{
	memset(euler,0,sizeof(euler));
	euler[1] = 1;
	for(int i = 2;i <= 1000005;i++)
    if(!euler[i])
    for(int j = i;j <= 1000005; j += i)
    {
        if(!euler[j])
        euler[j] = j;
        euler[j] = euler[j]/i*(i-1);
    }
}


int main()
{
    int n;
    geteuler();
    while(~scanf("%d",&n))
    {
        printf("%d\n",euler[n]);
    }
}