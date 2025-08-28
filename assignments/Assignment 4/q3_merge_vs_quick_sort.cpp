// Problem 3: Merge Sort vs. Quick Sort: A Comparative Study
// Apply both algorithms and analyze efβiciency using divide-and-conquer principles.
// i. Implement both Merge Sort and Quick Sort in the same program.
// ii. Generate test arrays of increasing size (n = 1000, 3000, 5000, 8000).
// iii. Measure and compare:
// o Execution time.
// o Number of recursive calls.
// o Memory usage (for Merge Sort vs. Quick Sort).
// iv. Write a short report answering:
// o Which algorithm uses more memory and why?
// o Which algorithm performs better on random vs. nearly-sorted data?
// o How divide-and-conquer ensures scalability of these algorithms.
// Learning Outcome:
//  Trade-offs between the two algorithms.
//  Deep understanding of divide-and-conquer efβiciency.
//  Realization that practical performance depends on both algorithm design and data
// characteristics.

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Global counters for recursive calls
int mergeCalls = 0;
int quickCalls = 0;

// ---------------- Merge Sort ----------------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; // extra memory used

    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int i = 0; i < n2; i++) R[i] = arr[m+1+i];

    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    mergeCalls++;
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// ---------------- Quick Sort ----------------
int partition(int arr[], int l, int h){
    int pivot = arr[h]; // last element pivot
    int i = l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return i+1;
}

void quickSort(int arr[], int l, int h){
    quickCalls++;
    if(l<h){
        int pi = partition(arr,l,h);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,h);
    }
}

// ---------------- Helper Function ----------------
void generateArray(int arr[], int n, int type){
    // type=0: random, type=1: sorted, type=2: reverse
    for(int i=0;i<n;i++){
        if(type==0) arr[i] = rand()%10000;
        else if(type==1) arr[i] = i+1;
        else arr[i] = n-i;
    }
}

int main(){
    vector<int> sizes = {1000,3000,5000,8000};
    srand(time(0));

    for(int n : sizes){
        int arr1[n], arr2[n];
        cout << "\nArray size = " << n << "\n";

        generateArray(arr1,n,0); // random
        for(int i=0;i<n;i++) arr2[i]=arr1[i]; // same array for Quick Sort

        // Merge Sort
        mergeCalls=0;
        auto start = high_resolution_clock::now();
        mergeSort(arr1,0,n-1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end-start).count();
        cout << "Merge Sort -> Time: " << duration << " ms, Recursive Calls: " << mergeCalls << endl;

        // Quick Sort
        quickCalls=0;
        start = high_resolution_clock::now();
        quickSort(arr2,0,n-1);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end-start).count();
        cout << "Quick Sort -> Time: " << duration << " ms, Recursive Calls: " << quickCalls << endl;
    }
    return 0;
}
