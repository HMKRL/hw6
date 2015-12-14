#include<stdio.h>
#include<stdlib.h>

void print_bit_float(unsigned int);
void print_bit_double(unsigned long);

int main()
{
	int i;
	char fc[33], dc[65];
	union{
		unsigned int inum;
		float Field;
	}AT;
	union{
		unsigned long lnum;
		double dnum;
	}larger;
	printf("Input the float number:");
	scanf("%f",&AT.Field);
	print_bit_float(AT.inum);

	printf("Input binary to convert to float:");
	AT.inum = 0;
	scanf("%s",fc);
	for(i = 31;i >= 0;i--)
	{
		if(fc[31 - i] == '1')
			AT.inum |= (1 << i);
	}
	printf("%e\n", AT.Field); //A.T.Field Max Power!!!

	printf("Input the double number:");
	scanf("%lf",&larger.dnum);
	print_bit_double(larger.lnum);

	printf("Input binary to convert to double:");
	larger.lnum = 0;
	scanf("%s",dc);
	for(i = 63;i >= 0;i--)
	{
		if(dc[63 - i] == '1')
			larger.lnum |= ((unsigned long)1 << i);
	}
	printf("%e\n", larger.dnum);

	return 0;
}

void print_bit_float(unsigned int inum)
{
	int i;
	for(i = 31;i >= 0;i--)
	{
		printf("%d",(inum >> i) & 1);
	}
	printf("\n");
}

void print_bit_double(unsigned long lnum)
{
	int i;
	for(i = 63;i >= 0;i--)
	{
		printf("%ld",(lnum >> i) & 1);
	}
	printf("\n");
}
