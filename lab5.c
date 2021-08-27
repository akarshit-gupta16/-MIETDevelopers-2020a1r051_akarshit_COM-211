#include<stdio.h>
#include<ctype.h>
#define max 20
int operand_stack[max];
char operator_stack[max];
int top_operand=-1, top_operator=-1;
void push_operand(int);
void push_operator(char);
void view_operand();
void view_operator();
int main()
{
	int number,a;
	char exp[max], digit, b;
	printf("Enter the expression\n");
	scanf("%[^\n]s",exp);
	for (int i = 0; exp[i]!='\0'; i++)
	{
		digit=exp[i];
		if (isdigit(digit))
		{
			number=digit-'0';
			push_operand(number);
		}
		else
		{
			push_operator(digit);
		}
	}
	printf("Converted infix expression to postfix expression:\n");
	view_operand();
	view_operator();
}

void push_operand(int x)
{
	if (top_operand==max-1)
	{
		printf("Error\n");
	}
	else
	{
		top_operand++;
		operand_stack[top_operand]=x;
	}
}

void push_operator(char y)
{
	if (top_operator==max-1)
	{
		printf("Error\n");
	}
	else
	{
		top_operator++;
		operator_stack[top_operator]=y;
	}
}

void view_operand()
{
	if (top_operand==-1)
	{
		printf("Error\n");
	}
	else
	{
		for (int i =0; i<=top_operand ;i++)
		{
			printf("%d",operand_stack[i]);
		}
	}
}

void view_operator()
{
	if (top_operator==-1)
	{
		printf("Error\n");
	}
	else
	{
		for (int i = top_operator; i>=0; i--)
		{
			printf("%c",operator_stack[i]);
		}
	}
}