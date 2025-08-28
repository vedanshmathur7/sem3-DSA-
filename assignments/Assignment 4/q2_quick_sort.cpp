// Problem 2: Quick Sort
// i. Implement Quick Sort with three pivot strategies (data stored in an 1D array):
// o First element as pivot.
// o Last element as pivot.
// o Median-of-three as pivot.
// ii. For each pivot strategy:
// o Show the partitioning steps (print subarrays at each recursive stage).
// o Count the number of comparisons and swaps.
// iii. Compare the performance of the three strategies on:
// o A sorted array (best/worst case).
// o A reverse-sorted array.
// o A random array.
// Learning Outcome:
// > Role of pivot selection in divide-and-conquer efβiciency.
// > Why Quick Sort’s best/average case is O(n log n) but worst case is O(n2).
// > Practical impact of input data distribution.


#include <iostream>
using namespace std;

int comp = 0, swp = 0;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    swp++;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int choosePivot(int arr[], int l, int h, int type) {
    if (type == 1) return l;          // first element
    if (type == 2) return h;          // last element
    int m = (l + h) / 2;              // median of three
    if ((arr[l] <= arr[m] && arr[m] <= arr[h]) || (arr[h] <= arr[m] && arr[m] <= arr[l])) return m;
    if ((arr[m] <= arr[l] && arr[l] <= arr[h]) || (arr[h] <= arr[l] && arr[l] <= arr[m])) return l;
    return h;
}

int partition(int arr[], int l, int h, int type) {
    int p = choosePivot(arr, l, h, type);
    swap(arr[l], arr[p]);   // pivot ko left me lao
    int pivot = arr[l];
    int i = l + 1, j = h;

    while (true) {
        while (i <= h && arr[i] <= pivot) { i++; comp++; }
        while (j >= l+1 && arr[j] > pivot) { j--; comp++; }
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);

    print(arr, h+1);
    return j;
}

void quickSort(int arr[], int l, int h, int type) {
    if (l < h) {
        int p = partition(arr, l, h, type);
        quickSort(arr, l, p - 1, type);
        quickSort(arr, p + 1, h, type);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = 5;

    cout << "Original array: ";
    print(arr, n);

    for (int type = 1; type <= 3; type++) {
        int temp[5];
        for (int i = 0; i < n; i++) temp[i] = arr[i];

        comp = swp = 0;
        cout << "\nQuick Sort using ";
        if (type == 1) cout << "First element as pivot\n";
        else if (type == 2) cout << "Last element as pivot\n";
        else cout << "Median-of-three as pivot\n";

        quickSort(temp, 0, n - 1, type);

        cout << "Sorted array: ";
        print(temp, n);
        cout << "Comparisons = " << comp << ", Swaps = " << swp << "\n";
    }
    return 0;
}
