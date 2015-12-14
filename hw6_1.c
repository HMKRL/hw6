#include<stdio.h>
#include<stdlib.h>

void print_bit_float(int*);
void print_bit_double(long*);

int main()
{
	int i;
	char fc[32], dc[64];
	float fnum;
	double dnum;
	int *ipt = (int*)&fnum;//sizeof(float) == 4 == sizeof(int), use int pointer
	long *lpt = (long*)&dnum;//sizeof(double) == 8 == siezof(long), use long pointer
	printf("Input the float number:");
	scanf("%f",&fnum);
	print_bit_float(ipt);

	printf("Input binary to convert to float:");
	*ipt = 0;
	scanf("%s",fc);
	for(i = 31;i >= 0;i--)
	{
		if(fc[31 - i] == '1')
			*ipt |= (1 << i);
	}
	printf("%e\n", fnum);

	printf("Input the double number:");
	scanf("%lf",&dnum);
	print_bit_double(lpt);

	printf("Input binary to convert to double:");
	*lpt = 0;
	scanf("%s",dc);
	for(i = 63;i >= 0;i--)
	{
		if(dc[63 - i] == '1')
			*lpt |= ((long)1 << i);
	}
	printf("%e\n", dnum);

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
		printf("%ld",(*lpt >> i) & 1);
	}
	printf("\n");
}
