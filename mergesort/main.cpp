#include<iostream>
using namespace std;

void printarray(int array[],int size)
{
	cout<<"elements of array are:"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}

void merge(int array[], int low, int mid, int high)
{
	int left_size = mid+1-1;
	int right_size = high - mid;
	int left[50], right[50];
	int i, j, k;
	cout << "elements of left array" << endl;
	for (int i =0; i <left_size; i++)
	{
		left[i] = array[i+low];
		cout << left[i]<<endl;
	}
	cout << "elements of right array" << endl;
	for (int j = 0; j < right_size; j++)
	{
		right[j] = array[j+mid+1];
		cout << right[j]<<endl;
	}
	i = 0; j = 0; k = 1;
	while (i < left_size && j < right_size)
	{
		if (array[i]<=array[j])
		{
			array[k] = array[i];
			i++;
		}
		else
		{
			array[k] = array[j];
			j++;
		}
		k++;
	}
	while (i<left_size)
	{
		array[k] = array[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		array[k] = array[j];
		j++;
		k++;
	}

	for (int k = low; k < high; k++)
	{
		cout << "sorted elements:" << endl;
		cout << array[k] << endl;
	}
}

void mergesort(int array[],int low,int high)
{
	if(low<high)
	{
		int mid = (low + high) / 2;
		mergesort(array, low, mid);
		mergesort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

int main()
{
	int array[] = { 20,10,5,3,50};
	int size = sizeof(array) / sizeof(int);
	int low = 0;
	int high = size - 1;
	printarray(array,size);
	mergesort(array,0,size-1);
	//printarray(array, size);

	cin.get();
}
