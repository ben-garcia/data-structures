// FILE: selectionsort.cpp
// An interactive test program for the selectionsort function.
// The worst-case running time, the average-case running time, and the best-case
// running time for selectionSort are all quadratic(n^2).

#include <algorithm>  // provides swap
#include <cstdlib>    // provides EXIT_SUCCESS, size_t
#include <iostream>   // provides cout and cin

using namespace std;

// prototype of the function used in this test program.
void selectionSort(int data[], size_t n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements are rearranged so that data[0] <= data[1] <= ... <= data[n - 1].

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
    selectionSort(data, numberOfElements);

    cout << "In sorted order, your numbers are: " << endl;
    for (i = 0; i < numberOfElements; ++i) {
        cout << data[i] << BLANK << BLANK;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

void selectionSort(int data[], size_t n) {
    size_t i, j, indexOfLargest;
    int largest;

    if (n == 0) {
        return;  // No work for an empty array
    }

    // loop through the array starting at the n - 1 position.
    // which in this case is 6.
    // after the first iteration the element with the greater value is
    // moved to the n - 1 position in the array.
    for (i = n - 1; i > 0; --i) {
        // set initial value to first index in the array.
        largest = data[0];
        // same for the index.
        indexOfLargest = 0;
        // inner loop that starts at 1(second element).
        // until it reaches i.
        for (j = 1; j <= i; ++j) {
            if (data[j] > largest) {
                // if an element is greater than the current largest then
                // it becomes the largest value in the array.
                largest = data[j];
                // get the index which will be used later
                // to swap the elements.
                indexOfLargest = j;
            }
        }
        // std function to swap 2 elements of an array.
        swap(data[i], data[indexOfLargest]);
    }
}