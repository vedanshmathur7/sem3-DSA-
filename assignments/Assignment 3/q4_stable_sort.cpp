#include <iostream>
#include <string>
using namespace std;

struct Student {
    int marks;
    string name;
};

// Bubble Sort (Stable)
void bubble_sort(Student arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j].marks > arr[j+1].marks) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Bubble Sort (Stable) -> ";
    for (int i=0; i<n; i++) {
        cout << "(" << arr[i].marks << "," << arr[i].name << ") ";
    }
    cout << endl;
}

// Insertion Sort (Stable)
void insertion_sort(Student arr[], int n) {
    for (int i=1; i<n; i++) {
        Student curr = arr[i];
        int prev = i-1;
        while (prev >=0 && arr[prev].marks > curr.marks) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    cout << "Insertion Sort (Stable) -> ";
    for (int i=0; i<n; i++) {
        cout << "(" << arr[i].marks << "," << arr[i].name << ") ";
    }
    cout << endl;
}

// Selection Sort (NOT Stable)
void selection_sort(Student arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j].marks < arr[minIndex].marks) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    cout << "Selection Sort (Not Stable) -> ";
    for (int i=0; i<n; i++) {
        cout << "(" << arr[i].marks << "," << arr[i].name << ") ";
    }
    cout << endl;
}

int main() {
    int n = 5;
    Student arr[5] = {
        {50, "A"}, {40, "B"}, {50, "C"}, {30, "D"}, {40, "E"}
    };

    Student b[5], ins[5], sel[5];
    for (int i=0; i<n; i++) {
        b[i]=arr[i];
        ins[i]=arr[i];
        sel[i]=arr[i];
    }

    bubble_sort(b, n);
    insertion_sort(ins, n);
    selection_sort(sel, n);

    return 0;
}
