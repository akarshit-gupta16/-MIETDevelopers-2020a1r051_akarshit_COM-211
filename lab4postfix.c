#include<stdio.h>
#include<ctype.h>
#define Max 20 
int stack[10];
int top=-1;
void push(int);
int pop();
int main()
{
	int a, b, result, Answer, number;
	char exp[20], digit;
	printf("Enter the expression to be entered\n");
	scanf("%[^\n]s", exp);

	for (int i = 0; exp[i]!='\0'; i++)
	{
		digit=exp[i];
		if(isdigit(digit))
			{
				number=digit-'0';
				push(number);
			}
		else if (digit =='+' || digit == '-'|| digit == '/'|| digit == '*')
		{
			a= pop();
			b= pop();

			switch(digit)
			{
				case '+':
					result=b+a;
					break;

				case '-':
					result=b-a;
					break;

				case '*':
					result=b*a;
					break;

				case '/':
					result=b/a;
					break;

				default:
					printf("Undifined operator\n");
											
			}
			push(result);

		}	
	}

	Answer=pop();
	printf("Expression after evaluation=%d\n",Answer);
	return 0;	
}

void push(int x)
{
	if (top==Max-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}

int pop()
{
	int number;
	if (top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		number=stack[top];
		top--;	
	}
return number;
}