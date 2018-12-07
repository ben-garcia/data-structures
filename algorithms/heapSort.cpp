// FILE: heapSort.cpp
// An interactive test program for the heapSort function.
//
// The worst-case running time and the average-case running time
// for a heapSort are both O(n log n).

#include <algorithm>  // provides swap
#include <cstdlib>    // provides EXIT_SUCCESS, size_t
#include <iostream>   // provides cout and cin

using namespace std;

// prototype of the function used in this test program.
void makeHeap(int data[], size_t n);
// Precondition: data is an array with at least n elements.
// Postcondition: The elements of data have been rearranged so that the
// complete binary tree represented by this array is a heap.

void heapSort(int data[], size_t n);

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
    heapSort(data, numberOfElements);

    cout << "In sorted order, your numbers are: " << endl;
    for (i = 0; i < numberOfElements; ++i) {
        cout << data[i] << BLANK << BLANK;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

void reheapifyDown(int data[], size_t n) {
    // Precondition: n > 0, and data is an array with at least n elements. These
    // elements form a heap, except data[0] may be in an incorrect location.
    // Postcondition: The data values have been rearranged so that the first
    // n elements of data now form a heap.

    // Reheapification downward (for a heap where the root is out of place)
    size_t current;        // index of the node that's moving down
    size_t bidChildIndex;  // index of current's largest child
    bool heapOk;           // will become true when heap is correct

    current = 0;
    heapOk = false;

    while ((!heapOk) /* && ( current node is not a leaf))*/) {
        if (data[current] < data[bidChildIndex]) {
        } else {
            heapOk = true;
        }
    }
}

void heapSort(int data[], size_t n) {
    // Precondition: data is an array with at least n components.
    // Postcondition: The elements of data have been rearranged so
    // that data[0] <= data[1] <= data[n - 1].
    size_t unsorted;

    makeHeap(data, n);

    unsorted = n;

    while (unsorted > 1) {
        --unsorted;
        swap(data[0], data[unsorted]);
        reheapifyDown(data, unsorted);
    }
}
