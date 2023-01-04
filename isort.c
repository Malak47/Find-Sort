//
// Created by malak on 1/3/2023.
//
// This code implemented from the pseudo code: https://en.wikipedia.org/wiki/Insertion_sort.


#include <stdio.h>

#define SIZE 50

static int SWITCH = 0;

void print(int *, int);

void swap(int *, int);

void shift_element(int *, int);

void insertion_sort(int *, int);

/**
 * Prints an array.
 * @param arr: A Pointer to the array.
 * @param len: Length of the array.
 */
void print(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[len - 1]);
}

/**
 * Swap function that swap between two near elements in the array.
 * @param arr: A pointer to the array.
 * @param i: i>0. Position where to start swapping, it swaps with the previous element, {arr+i <-> arr+i-1}.
 */
void swap(int *arr, int i) {
    if (i > 0) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + i - 1);
        *(arr + i - 1) = temp;
    }
}

/**
 * Shifts i-elements to the right with the given array.
 * @param arr: A pointer to the array.
 * @param i: how many elements to shift.
 */
void shift_element(int *arr, int i) {
    if (SWITCH == 1) {    //Only use for insertion_sort.
        while (i > 0 && *(arr + i) < *(arr + i - 1)) {
            swap(arr, i);
            i--;
        }
    } else {      //Only use for the shift_element.
        while (i > 0) {
            swap(arr, i);
            i--;
        }
    }
    SWITCH = 0;
}

/**
 * Insertion sort for arrays.
 * @param arr: A Pointer to the array.
 * @param len: Length of the array.
 */
void insertion_sort(int *arr, int len) {
    int i = 1;
    while (i < len) {
        SWITCH = 1;
        shift_element(arr, i);
        i++;
    }
}

int main() {
    int arr[SIZE];
    int num = 0;

    // Create the array.
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &num);
        *(arr + i) = num;
    }

    // Sort the array.
    insertion_sort(arr, SIZE);

    // Print the array.
    print(arr, SIZE);
    return 0;
}

