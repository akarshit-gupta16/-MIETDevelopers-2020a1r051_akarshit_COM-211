//Author: Aryan Gupta
//Date of creation: 20 June 2021
//Purpose:To check if a given expression is correctly parenthesized using Stacks.
#include <stdio.h>
#include <string.h>
int top=-1;
char stack[20];
void push(char);
void pop();
int main(){
	int choice;
	char exp[20];
	printf("(:  Welcome  :)\n"); 

	do{
	printf("Main Menu\n");
	printf("Press 1 to check the expression\n");
	printf("Press 2 to exit\n");
	scanf("%d", &choice);

		switch(choice)
		{

		case 1:
			printf("Enter the expression\n");
			scanf("%s", &exp);	
			for (int i = 0; exp[i] != '\0'; i++)
			{
				if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
					{
						push(exp[i]);
					}
				else if (exp[i]==')' || exp[i]==']' || exp[i]=='}')
					{
						pop();
					}		
			}
			if (top==-1)
				{
					printf("Expression is valid\n");
				}
			else
				{
					printf("Expression is invalid\n");
					}
			break;

		case 2:
			printf("Thanks visit again\n");
			break;

		default:
			printf("Entered input is wrong\n");	
		}
	}while(choice!=2);	
		
return 0;		
}


void push(char exp){
	top++;
	stack[top]=exp;
}

void pop(){
	top--;
}