// FILE: mergeSort.cpp

// Mergesort Running Time
// The worst-case running time, the average-case running time,
// and the best-case running time for mergesort are all O(n log n).

#include <cstdlib>  // provides size_t

void merge(int data[], size_t n1, size_t n2);

void merge(int data[], size_t n1, size_t n2)
// Precondition: data is an array (or subarray) with at least n1 + n2 elements. The first n1
// elements (from data[0] to data[n1 - 1]) are sorted from smallest to largest, and the last n2
// (from data[n1] to data[n1 + n2 - 1]) also are sorted from smallest to largest.
// Postcondition: The first n1 + n2 elements of data have been rearranged to be sorted from
// smallest to largest.
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
// Library facilities used: cstdlib
{
    int *temp;
    // Points to dynamic array to hold the sorted elements
    size_t copied = 0;   // Number of elements copied from data to temp
    size_t copied1 = 0;  // Number copied from the first half of data
    size_t copied2 = 0;  // Number copied from the second half of data
    size_t i;
    // Array index to copy from temp back into data
    // Allocate memory for the temporary dynamic array.
    temp = new int[n1 + n2];
    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2)) {
        if (data[copied1] < (data + n1)[copied2])
            temp[copied++] = data[copied1++];
        // Copy from first half
        else
            temp[copied++] = (data + n1)[copied2++];  // Copy from second half
    }
    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1)
        temp[copied++] = data[copied1++];
    while (copied2 < n2)
        temp[copied++] = (data + n1)[copied2++];
    // Copy from temp back to the data array, and release temp’s memory.
    for (i = 0; i < n1 + n2; ++i)
        data[i] = temp[i];
    delete[] temp;
}

void mergeSort(int data[], size_t n) {
    // Precondition: data is an array with at least n components.
    // Postcondition: The elements of data have been rearranged so
    // that data[0] <= data[1] <= ... <= data[n - 1].
    // NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
    size_t n1;  // Size of the first subarray
    size_t n2;  // Size of the second subarray

    if (n > 1) {
        // Compute sizes of the subarrays.
        n1 = n / 2;
        n2 = n - n1;

        mergeSort(data, n1);         // Sort from data[0] through data[n1 - 1];
        mergeSort((data + n1), n2);  // Sort from data[n1] to the end.

        // Merge the two sorted halves.
        merge(data, n1, n2);
    }
}

// FILE: insertionSort.cpp
// An interactive test program for the insertionSort function.
//
// Both the worst-case running time and the average-case running times are
// quadratic. But the best-case (when the starting array is already sorted) is
// linear, and the algorithm is also quick when the starting array is nearly sorted.

#include <algorithm>  // provides swap
#include <cstdlib>    // provides EXIT_SUCCESS, size_t
#include <iostream>   // provides cout and cin

using namespace std;

// prototype of the function used in this test program.
void insertionSort(int data[], size_t n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements are rearranged so that data[n - 1] <= data[n - 2] <= ... <= data[n].

int main() {
    const char BLANK = ' ';
    const size_t ARRAY_SIZE = 10;  // Number of elements in the array to be sorted.
    int data[ARRAY_SIZE];          // Array of integers to be sorted.
    int userInput;                 // Number typed by the user.
    size_t numberOfElements;       // How much of the array is used.
    size_t i;                      // Array index

    // Provide some instructions
    cout << "Please type up to " << ARRAY_SIZE << " positive integers. ";
    cout << "Indicate the list's end with a zero." << endl;

    // Read the input numbers
    numberOfElements = 0;
    cin >> userInput;
    while ((userInput != 0) && (numberOfElements < ARRAY_SIZE)) {
        data[numberOfElements] = userInput;
        ++numberOfElements;
        cin >> userInput;
    }

    // Sort the numbers, and print the result with two blanks after each number.
    insertionSort(data, numberOfElements);

    cout << "In sorted order, your numbers are: " << endl;
    for (i = 0; i < numberOfElements; ++i) {
        cout << data[i] << BLANK << BLANK;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

void insertionSort(int data[], size_t n) {
    size_t i, j;
    int next;

    for (i = 1; i < n; ++i) {
        next = data[i];
        j = i;

        while (j > 0 && next < data[j - 1]) {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = next;
    }
}