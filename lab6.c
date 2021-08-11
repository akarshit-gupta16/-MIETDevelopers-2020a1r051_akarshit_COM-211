#include<stdio.h>
int queue[100], front=-1, rear=-1, n;
void enqueue();
void dequeue();
void display();
int main()
{
	int choice;	
	printf("Enter the size of the queue\n");
	scanf("%d", &n);

	printf("(: Welcome :)\n");

 do{
 	printf("Main Menu\n");
	printf("Press 1 to enqueue\n");
	printf("Press 2 to dequeue\n");
	printf("Press 3 to view the queue\n");
	printf("Press 4 to exit\n");
	scanf("%d",&choice);
	

	switch(choice)
	{
		case 1:
			enqueue();
			break;

		case 2:
			dequeue();
			break;

		case 3:
			display();
			break;	

		case 4:
			printf("Thanks Visit Again\n");
			break;

		default:
			printf("Enter a valid input(1/2/3)\n");	

	}

    }while(choice!=4);
return 0;	
}




void enqueue()
{
	int x;
	printf("Enter the element in the queue\n");
	scanf("%d", &x);
	if (rear==n-1)
		{
			printf("Queue is Full\n");
		}
	else
		{
			if (front=-1)
				{
					front = 0;
					rear++;
					queue[rear]=x;
				}
		}
}

void dequeue()
{
	if (front==-1 || front>rear)
		{
			printf("Queue is empty\n");
		}
	else
		{
			printf("%d is dequeued\n", queue[front] );
			front++;
			
		}
}

void display()
{
	if (front==-1)
		{
			printf("Queue is Empty\n");
		}
	else
		{
			printf("Elements in the queue are:\n");
			for (int i = front; i <= rear; i++)
				{
					printf("%d\n",queue[i] );
				}
		}

}