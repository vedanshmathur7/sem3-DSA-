// Problem 1: Merge Sort
// i. Write a program to implement Merge Sort step by step (data stored in an 1D array).
// o Show how the array is recursively divided into subarrays.
// o Print the intermediate states of the array at each merge step.
// ii. Demonstrate the recurrence relation of Merge Sort T(n) = 2T(n/2) + O(n) by counting
// the number of recursive calls.
// iii. Test your program on arrays of different sizes (n = 8, 16, 32, 64).
// Learning Outcome:
// > How divide-and-conquer breaks a big problem into smaller subproblems.
// > How merging gives the sorted output.
// > Time complexity analysis using recurrence.

#include <iostream>
using namespace std;

int callCount = 0;   // To count recursive calls

// Function to print array
void printArray(int arr[], int start, int end) {
    cout << "[ ";
    for (int i = start; i <= end; i++) cout << arr[i] << " ";
    cout << "]";
}

// Merge two subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "Merging: ";
    printArray(arr, l, r);
    cout << endl;
}

// Recursive Merge Sort
void mergeSort(int arr[], int l, int r) {
    callCount++;  // Counting recursive calls
    if (l < r) {
        int m = (l + r) / 2;

        cout << "Divide: ";
        printArray(arr, l, r);
        cout << " -> Left: ";
        printArray(arr, l, m);
        cout << " | Right: ";
        printArray(arr, m + 1, r);
        cout << endl;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter size of array (n=8,16,32,64): ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl << endl;

    mergeSort(arr, 0, n - 1);

    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\nTotal Recursive Calls (T(n)): " << callCount << endl;

    return 0;
}
