#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

// #include <stdio.h>
// #include <stdlib.h>

// // Function to perform binary search for insertion
// int binarySearch(int arr[], int left, int right, int key) {
//     while (left < right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] < key)
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     return left;
// }

// // Function to insert an element at the correct position
// void insertElement(int arr[], int *size, int element) {
//     int pos = binarySearch(arr, 0, *size, element);
//     for (int i = *size; i > pos; i--)
//         arr[i] = arr[i - 1];
//     arr[pos] = element;
//     (*size)++;
// }

// // Merge-Insertion Sort function
// void mergeInsertionSort(int arr[], int n) {
//     if (n <= 1)
//         return;

//     int pairedSize = n / 2;
//     int larger[pairedSize], smaller[pairedSize], sortedSize = 0;

//     // Step 1: Pair elements and find larger/smaller
//     for (int i = 0; i < pairedSize; i++) {
//         if (arr[2 * i] > arr[2 * i + 1]) {
//             larger[i] = arr[2 * i];
//             smaller[i] = arr[2 * i + 1];
//         } else {
//             larger[i] = arr[2 * i + 1];
//             smaller[i] = arr[2 * i];
//         }
//     }

//     // If n is odd, handle the last element
//     int unpaired = (n % 2 == 1) ? arr[n - 1] : -1;

//     // Step 2: Recursively sort the larger elements
//     mergeInsertionSort(larger, pairedSize);

//     // Step 3: Insert the first smaller element into sorted sequence
//     sortedSize = pairedSize;
//     int sorted[n];
//     for (int i = 0; i < pairedSize; i++)
//         sorted[i] = larger[i];
//     insertElement(sorted, &sortedSize, smaller[0]);

//     // Step 4: Insert remaining elements in specific order
//     int insertionOrder[n - sortedSize], orderIndex = 0;

//     // Generate insertion order as per the algorithm
//     for (int i = 1; i < pairedSize; i++)
//         insertionOrder[orderIndex++] = smaller[i];
//     if (n % 2 == 1)
//         insertionOrder[orderIndex++] = unpaired;

//     // Perform binary insertion
//     for (int i = 0; i < orderIndex; i++)
//         insertElement(sorted, &sortedSize, insertionOrder[i]);

//     // Copy sorted elements back to original array
//     for (int i = 0; i < sortedSize; i++)
//         arr[i] = sorted[i];
// }

// // Utility function to print an array
// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// // Main function
// int main() {
//     int arr[] = {12, 11, 13, 5, 6, 7, 20};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     printf("Original array: \n");
//     printArray(arr, size);

//     mergeInsertionSort(arr, size);

//     printf("Sorted array: \n");
//     printArray(arr, size);

//     return 0;
// }

// // https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
// // https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
int main(int argc, char** argv)
{
	PmergeMe<std::vector<int> > algo;

	if (argc == 1)
	{
		std::cerr << "usage: ./PmergeMe [...]\n";
		return (1);
	}

	try
	{
		algo.init_bottom(argc, argv);

		std::cout << "Before:  ";
		algo.show();

		algo.sort();

		std::cout << "after:   ";
		algo.show();

		algo.print_time();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}