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