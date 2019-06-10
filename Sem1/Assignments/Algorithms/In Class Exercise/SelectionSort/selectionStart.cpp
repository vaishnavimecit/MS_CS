#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


/*
 * Selection sort implementation
 */
//RUnning time - Upper -> O(n^2) & Lower - O(n^2) => Theta(n^2)

void selectionSort(int * arr, int length)
{
int i, j, minIndex, tmp;
for(i=0; i<length-1; i++)
{
	minIndex = i;
	for(j=i+1;j<length;j++)
	{
		if(arr[j] < arr[minIndex])
			minIndex = j;
	}
	if(minIndex != 1)
	{
		tmp=arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}
}

/*
 * This method creates a sorted integer array of size length
 */
int* create_sorted_array(int* sortedArr, int length)
{
	for (int i=0; i<length; i++)
	{
		sortedArr[i]=i;
	}

	return sortedArr;
}

/*
 * This method creates an integer array of size length
 * with random values
 */
int* create_random_int_array(int* randomArr, int length)
{

	for (int i=0; i<length; i++)
	{
		randomArr[i] = rand() % 1000000;
	}

	return randomArr;
}

/*
 * Check if an array is sorted
 */
void check_sorted(int* arr, int length)
{
	for (int i=1; i<length; i++)
	{
		if(arr[i-1]>arr[i])
		{
			cout << "The array is NOT sorted!" << endl;
			return;
		}
	}
	cout << "The array is sorted!" << endl;
}


int main()
{
	int* arr;
	int length;
	std::clock_t start;
	double duration;

	cout << "Give the size of the array you want to sort: ";
	cin >> length;

	arr = new int[length];

	// call the random array generator function
	arr = create_random_int_array(arr, length);

	// call the sorted array generator function
	//arr = create_sorted_array(arr, length);


    // sort the input
	start = std::clock();
	selectionSort(arr, length);
	duration = (std::clock() - start)/(double) CLOCKS_PER_SEC;
	cout << " Selection sort running time: " << duration << endl;

	check_sorted(arr, length);
	
	delete[] arr;
}