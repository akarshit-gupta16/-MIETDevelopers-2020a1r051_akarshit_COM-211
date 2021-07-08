#include <stdio.h>
int top=-1 ,stack[100], n;
void push();
void pop();
void view();
int main(){
	int choice;
	printf("Enter the number of elements max size 100\n"); 
	scanf("%d", &n);
	printf("(:  Welcome  :)\n");
  do{
  	printf("Main Menu\n");
	printf("Press 1 to push\n");
	printf("Press 2 to pop\n");
	printf("Press 3 to View\n");
	printf("Press 4 to exit\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			 push();
			 break;

		case 2:
			pop();
			break;

		case 3:
		 	view();
		 	break;

		 case 4:
		 	printf("Thanks visit again\n");	
		 	break;

		 default:
		 	printf("Wrong input entered\n");	

				
	}

}while(choice!=4);
return 0;
}

void push(){
int x; 

printf("Enter the number to be pushed\n");
scanf("%d", &x);

	if (top == n-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;	
		stack[top]=x;
	}

}


void pop(){
	if (top <= -1)
	{
		printf("underflow\n");
	}

	else
	{
		printf("%d is popped\n", stack[top] );
		top--;
	}	
}

void view(){
	if (top >= 0)
	{
		printf("Elements in the stack are:\n");
		for (int i = top; i >= 0; i--)
			{
			printf("%d\n",stack[i]);
			}

	}
	else
	{
		printf("Stack is empty\n");
	}

}