#include <stdio.h>

#include "repolish.h"

int main(void)
{
	char *p = "352*+63/-";
	int res = 0;

	//2出栈	*	1出栈

	while(*p != '\0')
	{
		system("clear");
		switch(*p)
		{
			case '0' : case '1' : case '2' :
			case '3' : case '4' : case '5' :
			case '6' : case '7' : case '8' :
			case '9' :
				stack_push(*p - '0');//入栈
				break;
			case '+' :
				res = stack_pop();//出栈
				stack_push(stack_pop() + res);
				break;
			case '-' :
				res = stack_pop();
				stack_push(stack_pop() - res);
				break;
			case '*' :
				res = stack_pop();
				stack_push(stack_pop() * res);
				break;
			case '/' :
				res = stack_pop();
				stack_push(stack_pop() / res);
				break;
		}
		p++;
		stack_display();
	}

	printf("SUM = %d\n", stack_pop());

	return 0;
}














