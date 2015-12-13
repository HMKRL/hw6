#include<stdio.h>
#include<stdlib.h>

void print_bit_float(int*);
void print_bit_double(long*);

int main()
{
	float fnum;
	double dnum;
	int *ipt;//sizeof(float) == 4 == sizeof(int), use int pointer
	long *lpt;//sizeof(double) == 8 == siezof(long), use long pointer
	printf("Input the float number:");
	scanf("%f",&fnum);
	ipt = &fnum;
	print_bit_float(ipt);
	printf("Input the double number:");
	scanf("%lf",&dnum);
	lpt = &dnum;
	print_bit_double(lpt);

	return 0;
}

void print_bit_float(int *ipt)
{
	int i;
	for(i = 31;i >= 0;i--)
	{
		printf("%d",(*ipt >> i) & 1);
	}
	printf("\n");
}

void print_bit_double(long *lpt)
{
	int i;
	for(i = 63;i >= 0;i--)
	{
		printf("%d",(*lpt >> i) & 1);
	}
	printf("\n");
}
