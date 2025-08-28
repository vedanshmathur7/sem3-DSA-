#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for (int i = 1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >=0 && curr < arr[prev]){
            arr[prev +1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;

        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "Final Output: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


}

int main () {
    int arr[] = {56, 25, 2, 32, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    return 0;
}