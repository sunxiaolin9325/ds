#include <stido.h>
#include <math.h>

main()
{
	int i;

	for (i=2; i<100; i++)
	{
		if (isprime(i))
			printf("%d\t", i);
	}
}

int isprime(int n)
{
	int k, i;

	if (n == 1) return 0;

	k = (int)sqrt((double)n);

	for (i=2; i<=k; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int		a;
char	name;
int		b;
char 	sex		= 'F';
int		age		= 20;

for (i=0; i<10; i++) 

if ((a+b>c) && (b+c>a) && (c+a>b)) 

void func1(int x, int y, int z);
printf("%d%d%D", a, b, c);
if (year >= 2000)
if ((a>=b) && (c<=d))
x = a < b ? a : b;
int *x = &y;
array[5] = 0;
a.function();
b->function();

int		width;		//宽度
int		heigth;		//高度
int		depth;		//深度
int		sum		= 0;

if (widh < height) 
{
	do_something();
}

otherthing();

for (initialization; condition; updata)
{
	dosomething();
}

otherthing();

if (verylongvar1 >= verylongvar2
	&& (verylongvar3 >= verylongvar4))
{
	dosomething();
}

double function_name(double variabe_name1,
						double variable_name2);

for (very_longer_initialization;
	very_longer_condition;
	very_longer_update)
{
	dosomething();
}

int *x, y;

-在Linux/Unix平台
	习惯用“小写加下划线”
	funvtion_name
	variable_name

