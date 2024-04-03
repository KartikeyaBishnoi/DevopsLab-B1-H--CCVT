#include <stdio.h>
#include <unistd.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

#define CAPACITY 100
int queue[CAPACITY], n = 0;
int stack[8];

void processScheduling()
{
	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process:");
	scanf("%d", &n);

	printf("\nEnter Burst Time:\n");
	for (i = 0; i < n; i++)
	{
		printf("p%d:", i + 1);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}

	// sorting of burst times
	for (i = 0; i < n; i++)
	{
		pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (bt[j] < bt[pos])
				pos = j;
		}

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0] = 0;

	for (i = 1; i < n; i++)
	{
		wt[i] = 0;
		for (j = 0; j < i; j++)
			wt[i] += bt[j];

		total += wt[i];
	}

	avg_wt = (float) total / n;
	total = 0;

	printf("\nProcess\t    Burst Time\t    Waiting Time\tTurnaround Time");
	for (i = 0; i < n; i++)
	{
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
	}

	avg_tat = (float) total / n;
	printf("\n\nAverage Waiting Time=%f", avg_wt);
	printf("\nAverage Turnaround Time=%f\n", avg_tat);
}

void quickSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

int partition(int array[], int low, int high)
{
	// select the rightmost element as pivot
	int pivot = array[high];

	// pointer for greater element
	int i = (low - 1);

	// traverse each element of the array
	// compare them with the pivot
	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			// if element smaller than pivot is found
			// swap it with the greater element pointed by i
			i++;

			// swap element at i with element at j
			swap(&array[i], &array[j]);
		}
	}

	// swap the pivot element with the greater element at i
	swap(&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

void insert_front(int item)
{
	if (n == CAPACITY - 1)
	{
		printf("\nOVERFLOW");
	}
	else if (n == 0)
	{
		queue[0] = item;
		n++;
	}
	else
	{
		for (int i = n; i >= 0; i--)
		{
			queue[i + 1] = queue[i];
		}

		queue[0] = item;
		n++;
	}
}

void insert_rear(int item)
{
	if (n == CAPACITY - 1)
	{
		printf("\nOVERFLOW");
	}
	else if (n == 0)
	{
		queue[0] = item;
		n++;
	}
	else
	{
		queue[n] = item;
		n++;
	}
}

int delete_front()
{
	if (n == 0)
	{
		printf("\nUnderflow");
	}
	else
	{
		int item = queue[0];
		for (int i = 0; i < n - 1; i++)
		{
			queue[i] = queue[i + 1];
		}

		n--;
		return item;
	}
}

int delete_rear()
{
	if (n == 0)
	{
		printf("\nUNDERFLOW");
	}
	else
	{
		int item = queue[n - 1];
		n--;
		return item;
	}
}

void display()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", queue[i]);
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
			 	// Swap elements
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int isempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if (top == MAXSIZE)
		return 1;
	else
		return 0;
}

int peek()
{
	return stack[top];
}

int pop()
{
	int data;
	if (!isempty())
	{
		data = stack[top];
		top = top - 1;
		return data;
	}
	else
	{
		printf("Could not retrieve data, Stack is empty.\n");
	}
}

int push(int data)
{
	if (!isfull())
	{
		top = top + 1;
		stack[top] = data;
	}
	else
	{
		printf("Could not insert data, Stack is full.\n");
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 *i + 1;
	int right = 2 *i + 2;

	if (left < N && arr[left] > arr[largest])
		largest = left;

	if (right < N && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}

void heapSort(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	for (int i = N - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int binarySearch(int array[], int x, int low, int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == x)
			return mid;
		if (array[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

int main()
{
	int choice;
	int arr[100], N, i, x, low, high;

	do {
		printf("\n**********************************************************************");
		printf("\nMenu:\n");
		printf("1. Heap Sort\n");
		printf("2. Binary Search\n");
		printf("3. Stack Operations\n");
		printf("4. Bubble Sort\n");
		printf("5. Dequeue Operations\n");
		printf("6. Quick Sort\n");
		printf("7. Process Scheduling\n");
		printf("8. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		    sleep(1);
			case 1:
				printf("Enter number of elements: ");
				scanf("%d", &N);
				printf("Enter elements: ");
				for (i = 0; i < N; i++)
					scanf("%d", &arr[i]);
				heapSort(arr, N);
				printf("Sorted array is: ");
				printArray(arr, N);
				break;
			case 2:
			
				printf("Enter number of elements: ");
				scanf("%d", &N);
				printf("Enter elements: ");
				for (i = 0; i < N; i++)
					scanf("%d", &arr[i]);
				printf("Enter element to search: ");
				scanf("%d", &x);
				printf("Enter low index: ");
				scanf("%d", &low);
				printf("Enter high index: ");
				scanf("%d", &high);
				int result = binarySearch(arr, x, low, high);
				(result == -1) ? printf("Element is not present in array\n"): printf("Element is present at index %d\n", result);
				break;
			case 3:
				int stackChoice;
				do { 
				    sleep(1);
				    printf("Stack Operations:\n");
					printf("1. Push\n");
					printf("2. Pop\n");
					printf("3. Peek\n");
					printf("Enter your choice: ");
					scanf("%d", &stackChoice);
					switch (stackChoice)
					{
						case 1:
							printf("Enter a number to push into the stack: ");
							int num;
							scanf("%d", &num);
							push(num);
							break;
						case 2:
							printf("Popped element: %d\n", pop());
							break;
						case 3:
							printf("Top element: %d\n", peek());
							break;
						case 4:
							printf("Stack done");
							break;
						default:
							printf("Invalid choice!\n");
					}
				} while (stackChoice != 4);
				top = -1;
				break;
			case 4:
				printf("Enter number of elements: ");
				scanf("%d", &N);
				printf("Enter elements: ");
				for (i = 0; i < N; i++)
					scanf("%d", &arr[i]);
				bubbleSort(arr, N);
				printf("Sorted array is: ");
				printArray(arr, N);
				break;
			case 5:
				int internal_choice;
				do { 
				    sleep(1);
				    printf("\nDequeue Operations:\n");
					printf("1. Insert from front\n");
					printf("2. Insert from rear\n");
					printf("3. Delete from front\n");
					printf("4. Delete from rear\n");
					printf("5. Display\n");
					printf("6. Exit\n");
					int item;
					scanf("%d", &internal_choice);
					switch (internal_choice)
					{
						case 1:
							printf("\nEnter the element: ");
							scanf("%d", &item);
							insert_front(item);
							break;
						case 2:
							printf("\nEnter the element: ");
							scanf("%d", &item);
							insert_rear(item);
							break;
						case 3:
							item = delete_front();
							printf("\nDeleted Item: %d", item);
							break;
						case 4:
							item = delete_rear();
							printf("\nDeleted Item: %d", item);
							break;
						case 5:
							display();
							break;
						case 6:
							printf("Exiting...\n");
							break;

						default:
							printf("\nWrong Choice");
					}
				} while (internal_choice != 6);
				top = -1;

				break;
			case 6:
				printf("Enter number of elements: ");
				scanf("%d", &N);
				printf("Enter elements: ");
				for (i = 0; i < N; i++)
					scanf("%d", &arr[i]);
				quickSort(arr, 0, N - 1);
				printf("Sorted array is: ");
				printArray(arr, N);
				break;
			case 7:
				processScheduling();
				break;
			case 8:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice!\n");
		}
	} while (choice != 8);

	return 0;
}
