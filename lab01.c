#include <stdio.h>
int arr[100], n, choice;
void insert();
void delete();
void search();
int main(){
	printf("Enter the number of elements the array:\n");
	scanf("%d", &n);

	printf("Enter the elements\n");

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	printf("The elements in the array are\n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}

	printf("(:  Welcome  :)\n");

	do{
	printf("Main Menu\n");
	printf("Press 1 to insert\n");
	printf("Press 2 to delete\n");
	printf("Press 3 to search\n");
	printf("Press 4 to exit\n");
	printf("Enter your choice\n");
	scanf("%d", &choice);
	
		switch(choice){	
			
		case 1:
			insert();
			break;

		case 2:
			delete();		
			break;

		case 3:
			search();
			break;

		case 4:
			printf("Thanks visit again\n");
			break;

		default:
			printf("input entered is wrong\n");		

		}

	}while(choice!=4);

return 0;
}

void insert()
{

 	printf("Enter the number to be inserted\n");
 	scanf("%d", &arr[n]);

 	printf("The number present in the array are:\n");

 		for (int i = 0; i < n+1; ++i)
 		{
 			printf("%d\n", arr[i]);
 		}
}


void delete()
{
	int x;
	printf("Enter the position of the number to be deleted\n");
	scanf("%d", &x);

	if (x > n)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		for (int i = x - 1; i < n-1; ++i)
		{
    		arr[i];
		}

	printf("The resultant array:\n");
    	for (int i = 0; i < n-1; ++i)
    	{
    		printf("%d\n",arr[i]);
		}
	}
}

void search()
{
	int search;
	printf("Enter the number to be searched in the array\n");
		scanf("%d", &search);

	for (int i = 0; i < n; ++i)
		{
			if (arr[i]==search)
			{
				printf("%d is present at %d position\n", search, i+1 );
			}
		}	
}