#include "stack.h"
#include <unistd.h>

int main(void)
{
	char data[DATA_LEN] = "352*+63/-";
	int i;
	int a, b, c;

	for (i=0; data[i]!='\0'; i++)
	{
		system("clear");
		stack_traverse();
		getchar();
		if ((data[i] >= '0') && (data[i] <= '9'))
		{
			stack_push(data[i] - '0');
		}
		else 
		{
			a = stack_pop();
			b = stack_pop();

			switch (data[i])
			{
				case '+':
					c = b + a;
					break;
				case '-':
					c = b - a;
					break;
				case '*':
					c = b * a;
					break;
				case '/':
					c = b / a;
					break;
				default:
					printf("Data error\n");
					break;
			}
			stack_push(c);
		}
	}

	stack_traverse();


	return 0;
}
