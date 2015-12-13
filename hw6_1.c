#include<stdio.h>
#include<stdlib.h>

void print_bit_float(int*);
void print_bit_double(long*);

int main()
{
	int i;
	char fc[32], dc[64];
	float fnum, *fpt;
	double dnum, *dpt;
	int *ipt;//sizeof(float) == 4 == sizeof(int), use int pointer
	long *lpt;//sizeof(double) == 8 == siezof(long), use long pointer
	printf("Input the float number:");
	scanf("%f",&fnum);
	ipt = &fnum;
	print_bit_float(ipt);

	printf("Input binary to convert to float:");
	unsigned int a = 0;
	scanf("%s",fc);
	for(i = 31;i >= 0;i--)
	{
		if(fc[31 - i] == '1')
			a |= (1 << i);
	}
	fpt = &a;
	printf("%e\n", *fpt);

	printf("Input the double number:");
	scanf("%lf",&dnum);
	lpt = &dnum;
	print_bit_double(lpt);

	printf("Input binary to convert to double:");
	unsigned long d = 0;
	scanf("%s",dc);
	for(i = 63;i >= 0;i--)
	{
		if(dc[63 - i] == '1')
			d |= ((long)1 << i);
	}
	dpt = &d;
	printf("%e\n", *dpt);

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
