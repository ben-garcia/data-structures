// FILE: quickSort.cpp
// An interactive test program for the quickSort function.
//
// The worst-caes running time of quickSort is O(n^2). But the
// average-case running time and the best-case running time
// for quickSort are both O(n log n). Obtaining a good running
// time requires the choice of a good pivot element.

#include <algorithm>  // provides swap
#include <cstdlib>    // provides EXIT_SUCCESS, size_t
#include <iostream>   // provides cout and cin

using namespace std;

// prototype of the function used in this test program.
void merge(int data[], size_t n1, size_t n2);
void quickSort(int data[], size_t n);

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
    quickSort(data, numberOfElements);

    cout << "In sorted order, your numbers are: " << endl;
    for (i = 0; i < numberOfElements; ++i) {
        cout << data[i] << BLANK << BLANK;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

void merge(int data[], size_t n1, size_t n2) {
    // Precondition: data is an array (or subarray) with at least n1 + n2 elements. The first n1
    // elements (from data[0] to data[n1 - 1]) are sorted from smallest to largest, and the last n2
    // (from data[n1] to data[n1 + n2 - 1]) also are sorted from smallest to largest.
    // Postcondition: The first n1 + n2 elements of data have been rearranged to be sorted from
    // smallest to largest.
    // NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
    // Library facilities used: cstdlib
    int* temp;
    // Points to dynamic array to hold the sorted elements
    size_t copied = 0;   // Number of elements copied from data to temp
    size_t copied1 = 0;  // Number copied from the first half of data
    size_t copied2 = 0;  // Number copied from the second half of data
    size_t i;            // Array index to copy from temp back into data

    // Allocate memory for the temporary dynamic array.
    temp = new int[n1 + n2];

    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2)) {
        if (data[copied1] < (data + n1)[copied2]) {
            // Copy from first half
            temp[copied++] = data[copied1++];
        } else {
            // Copy from second half
            temp[copied++] = (data + n1)[copied2++];
        }
    }
    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1) {
        temp[copied++] = data[copied1++];
    }

    while (copied2 < n2) {
        temp[copied++] = (data + n1)[copied2++];
    }
    // Copy from temp back to the data array, and release temp’s memory.
    for (i = 0; i < n1 + n2; ++i) {
        data[i] = temp[i];
    }

    delete[] temp;
}

void partition(int data[], size_t n, size_t& pivotIndex) {
    // Precondition: n > 1, and data is an array (or subarray)
    // with at least n elements.
    // Postcondition: The function has selected some "pivot value"
    // that occurs in data[0]...data[n - 1]. The elements of data
    // have then been rearranged and the pivot index set so that
    //  - data[pivotIndex] is equal to the pivot;
    //  - each item before data[pivotIndex] is <= the pivot;
    //  - each item after data[pivotIndex] is >= the pivot.
    size_t pivot = data[0];
    size_t tooBigIndex = 1;        // Index of first item after pivot
    size_t tooSmallIndex = n - 1;  // Index of last item

    while (tooBigIndex <= tooSmallIndex) {
    }
}

void quickSort(int data[], size_t n) {
    // Precondition: data is an array with at least n compenents.
    // Postcondition: The elements of data have been rearranged so that
    // data[0] <= data[1] <= data[2] <= ... <= data[n -1].
    size_t pivotIndex;  // Array index for the pivot element.
    size_t n1;          // Number of elements before the pivot element.
    size_t n2;          // Number of elements after the pivot element.

    if (n > 1) {
        // Partition the array, and set the pivot index.
        partition(data, n, pivotIndex);

        // Compute the sizes of the subarrays.
        n1 = pivotIndex;
        n2 - n - n1 - 1;

        // Recursive calls will now sort the subarrays.
        quickSort(data, n1);
        quickSort((data + pivotIndex + 1), n2);
    }
}