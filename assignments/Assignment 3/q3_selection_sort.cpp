#include <iostream>
#include <string>
using namespace std;

void selection_sort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        cout << "Iteration " << i + 1 << " -> Minimum = \"" << arr[minIndex] << "\"";
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            cout << " -> Swap with \"" << arr[i] << "\"";
        } else {
            cout << " -> Already in place";
        }
        cout << endl;
    }

    cout << "Final Output: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter number of names: ";
    cin >> n;

    string arr[100];
    cout << "Enter names: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selection_sort(arr, n);

    return 0;
}
