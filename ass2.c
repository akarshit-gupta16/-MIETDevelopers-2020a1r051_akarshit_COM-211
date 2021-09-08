#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y){ //pass the address of the variables to swap
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int *arr, int n){
	int i, j;
	for (i = 0; i < (n-1); ++i)
	{
		printf("inside first for loop i=%d, arr[%d] = %d\n", i,i, arr[i]);
		for (j = 0; j < (n-(i+1)); ++j)
		{
			printf("\tinside second for loop j=%d, arr[%d]=%d\n", j,j, arr[j]);
			printf("\t\tcomparing arr[%d] with arr[%d]\n", j, j+1);
			if (arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void insertionSort(int *arr, int n){
	int key, i, j;
	for (i = 1; i < n; ++i)
	{
		key = arr[i];
		// find the right place of key in sub-array arr[0..(i-1)]
		j = i-1;
		// keep moving left until the array ends or you find an element which is smaller than key
		while(j>=0 && key<=arr[j]){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}
void merge(int *arr, int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;//r-(m+1)+1;
	int L[n1], R[n2];
	int i,j,k;
	/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[(m + 1) + j];
	i = 0; // Initial index of first or left subarray
    j = 0; // Initial index of second or right subarray
    k = l; // Initial index of merged subarray
    while(i<n1 && j<n2){
    	if (L[i]<=R[j])
    	{
    		arr[k] = L[i];
    		i++;
    	} else{
    		arr[k] = R[j];
    		j++;
    	}
    	k++;
    }
    while (i < n1) { // right is empty
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) { // left is empty
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r){//recursive function
	int m;
	if (l < r)
	{
		m = (l+r)/2;
		// call mergeSort() for left subarray
		mergeSort(arr, l, m);
		// call mergeSort() for right subarray
		mergeSort(arr, m+1, r);
		// merge the left and right subarrays
		merge(arr, l, m, r);
	}
}


int printArray(int *arr, int size){
	int count;
	for (count = 0; count < size; ++count)
	{
	
		printf("\narr[%d] = %d\n", count, *(arr+count));
	}
	return (count+1);
}

int getInput(int *arr, int size){
	int count;
	for (count = 0; count < size; ++count)
	{
		printf("Enter arr[%d]=",count);
		scanf(" %d", (arr+count));
	}
	return (count+1);// returns the number of elements read
}
int main()
{
	int arr[100],n, choice;
	clock_t start,end;
	double time_spent;
	printf("\nenter the size of array:\n");
	scanf("%d", &n);
	do{
		printf("Enter the operation\n\n");
		printf("1. Bubble Sort\n");
		printf("2. Insertion Sort\n");
		printf("3. Merge Sort\n");
		printf("4. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			start = clock();
			getInput(arr, n);
			bubbleSort(arr, n);
			printArray(arr, n);
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("time consumed=%f\n", time_spent );
			break;
			case 2:
		    start = clock();
		    getInput(arr, n);
			insertionSort(arr, n);
			printArray(arr,n);
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("time consumed=%f\n",time_spent );
			break;
			case 3:
			start = clock();
			getInput(arr, n);
			mergeSort(arr, 0, n-1);
			printArray(arr, n);
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("time consumed=%f\n", time_spent );
			break;
			case 4:
			printf("exitting the program:\n");
			exit(0);
			break;
			default :
			printf("enter correct option\n");
			break;
		}
	}while(1);
	return 0;
}