#include<stdio.h>//Header file for standard input and output(printf, scanf)
#include<stdlib.h>//Header file for standard library used to allocate memory(malloc function, free function)

int count=0, i=2, n;//Variable declaration
void insert_pos();//Insert function prototype
void delete_pos();//Delete function prototype
void search();//search function prototype
void view();//view function prototype


//In the 11th line we have used typedef so that instead of writing struct node again 
//we can simply write variable of the structure to declare the name of the node 
typedef struct node//Node structure 
{
	int data;//Node structure member which contains the data
	struct node *next;//Node structure member which contains the address of the next node
}Node;
Node *head=NULL;//Head node will be the top most node in the list and
//is initialised with null because the list is empty in the beginning 
int main()
{
	int choice;//Variable declaration
	printf("(: Welcome :)\n");
	do{
		printf("Main Menu\n");
		printf("Press 1 to Insert\n");
		printf("Press 2 to Delete\n");//Menu of the program to insert, delete, view, search and exit the program
		printf("Press 3 to search\n");
		printf("Press 4 to view\n");
		printf("Press 5 to Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insert_pos();
				break;

			case 2:
				delete_pos();
				break;	

			case 3:
				search();
				break;	

			case 4:
				view();
				break;	

			case 5:
				printf("Thanks Visit Again\n");	
				break;

			default:
				printf("Invalid input\n");	
		}
	}while(choice!=5);
}

void insert_pos()
{
	int pos;//Variable declaration
	Node *ptr, *temp;//Node declaration
	ptr=(struct node*) malloc(sizeof(struct node));//Memory Allocation of the node

	if (ptr==NULL)//if the memory is not allocated in the ram then pointer ptr will return null
	{
		printf("Oops! Memory not available\n");
	}
	printf("Enter the element\n");
	scanf("%d",&ptr->data);//Entering data in the node
	ptr->next=NULL;//Initialising next of ptr to null
	printf("Enter the position\n");
	scanf("%d",&pos);//Taking position as input from the user
	

	if (head==NULL)//If the list is empty
	{
		if (pos==1)//And //Head will be equal to the new node i.e. ptrif the user have opted for position 1 then only he can insert
		{
			head=ptr;//Head will be equal to the new node i.e. ptr
			count++;//Increasing the count by 1 as node is inserted
			printf("Node Inserted\n");
		}
		else//Else the program will print invalid position
		{
			printf("Invalid position\n");
		}
	}
	else if (pos==count+1)//Entering the node at the end
	{
		temp=head;
		while(temp->next!=NULL)//Treversing the list till last
		{
			temp=temp->next;
		}
		temp->next=ptr;//Assigning the next of temp to ptr i.e. the newnode
		count++;
		printf("Node Inserted\n");
	}
	else if (pos==1)//Entering node at position 1
	{
		temp=head;//first we will assign head to a temporary node
		head=ptr;//then we will point head to the new node
		head->next=temp;//and the head will contain the address of secont node i.e. temp
		count++;
		printf("Node Inserted\n");
	}
	else
	{
		temp=head;//first we will assign head to a temporary node
		while(i<pos)//treversing the list till the element to be inserted
		{
			temp=temp->next;
			i++;
		}
		ptr->next=temp->next;//then pointing next of ptr to the next of temp
		temp->next=ptr;//and the next of temp to ptr
		count++;
		printf("Node Inserted\n");
	}
	printf("Total elements=%d\n",count);
}

void delete_pos()//delete function definition
{
	int pos, x=1;
	Node *ptr, *temp;
	printf("Enter the position\n");
	scanf("%d",&pos);

	if (head==NULL)//if list is empty
	{
		printf("List is empty\n");
	}
	else if (head->next==NULL)//if the there is only one element in the list
	{
		printf("%d is deleted\n",head->data);
		head=NULL;
		free(head);
		count--;
	}
	else if (pos>count)//if position entered is greater than the total elements
	{
		printf("Invalid Position\n");
	}
	else if (pos==1)//if the user want to delete the element from the beginning
	{
		temp=head;
		printf("%d is deleted\n",temp->data);
		head=head->next;
		free(temp);
		count--;
	}
	else
	{
		temp=head;//to delete from any random position
		while(x<pos)//treversing the list
		{
			ptr=temp;
			temp=temp->next;
			x++;
		}
		ptr->next=temp->next;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	printf("Total elements=%d\n",count);
}

void search()//search function definition
{
	int num, index=1;
	Node *temp;

	printf("Enter the element to be searched\n");
	scanf("%d",&num);
	if (head==NULL)//if the list is empty
	{
		printf("List is empty\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)//traversing the list till the last node
		{
			if (temp->data==num)//if we get the element in the list entered by the user
			{
				printf("%d is at %d position\n",num, index);
				n=0;//we will print the element and n=0
			}
			else
			{
				n=1;//else n=1
			}
			temp=temp->next;
			index++;
		}
		if (n==1)
		{
			printf("Element not found\n");
		}
	}
}

void view()//View function definition
{
	Node *temp;
	if (head==NULL)//if the list is empty we will not able to view
	{
		printf("List is empty\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)//treversing the list and printing each element
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("Total elements=%d\n",count);
	}
}