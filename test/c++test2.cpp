#include <cstdio>

void swap(int &pa, int &pb);
void plus(int &pa, int &pb);

int main()
{
    int pa=3,pb=2;
    swap(pa,pb);
    printf("%d ,%d",pa,pb);
    return 0;
}

void plus (int &pa, int &pb)
{
    pa++;
    ++pa;
    pb--;
    printf("pa=%d,pb=%d\n",pa,pb);
}

void swap(int &pa, int &pb)
{
    plus(pa,pb);
}