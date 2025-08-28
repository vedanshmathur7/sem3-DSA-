#include <iostream>
using namespace std;

void sorting_arr(int arr[], int n){

    int comparisons = 0;
    int swaps = 0;

    for (int i =0; i<n-1; i++){
        comparisons++;
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaps++;
            }
        }
    }
    cout<<"The sorted array is: ";
    for (int i =0; i<n; i++){
        cout<<arr[i]<<" "<<endl;
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

int main () {
    
    int arr[100];
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i= 0; i<n; i++){
        cin>>arr[i];
    }

    sorting_arr (arr, n);

    return 0;
}