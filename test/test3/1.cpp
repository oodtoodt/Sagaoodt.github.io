#include<stdio.h>
#include<math.h>
#define G 6.67*pow(10,-11)
#define PI 3.1415926
int main()
{
	double R = 6.371*pow(10,6),M = 6*pow(10,24),H,a,T;
	scanf("%lf",&T);
    printf("%lf\n%f\n",G*M,4*PI*PI);
	a = G*M*T*T/(4*PI*PI);
    printf("%lf\n",a);
	H = pow(a,1.0/3)-R;
	printf("%f",H);
	return 0;
}