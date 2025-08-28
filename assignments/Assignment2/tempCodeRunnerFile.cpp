    #include <iostream>
    #include <chrono>   // for timing
    using namespace std;
    using namespace std::chrono;

    // Iterative Binary Search
    int binarySearchIterative(int arr[], int n, int key) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // Recursive Binary Search
    int binarySearchRecursive(int arr[], int low, int high, int key) {
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key);
        else
            return binarySearchRecursive(arr, low, mid - 1, key);
    }

    int main() {
        // Step 1: Define sorted array
        int arr[10] = {5, 12, 23, 34, 45, 56, 67, 78, 89, 99};
        int n = 10;

        cout << "Sorted Array elements: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";

        int key;
        cout << "Enter element to search: ";
        cin >> key;

        // Step 2: Iterative Search Timing
        auto start1 = high_resolution_clock::now();
        int index1 = binarySearchIterative(arr, n, key);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

        // Step 3: Recursive Search Timing
        auto start2 = high_resolution_clock::now();
        int index2 = binarySearchRecursive(arr, 0, n - 1, key);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

        // Step 4: Display results
        if (index1 != -1)
            cout << "Iterative Binary Search: Element " << key << " found at index " << index1 << endl;
        else
            cout << "Iterative Binary Search: Element " << key << " not found\n";

        if (index2 != -1)
            cout << "Recursive Binary Search: Element " << key << " found at index " << index2 << endl;
        else
            cout << "Recursive Binary Search: Element " << key << " not found\n";

        cout << "Running time (Iterative): " << duration1.count() << " nanoseconds\n";
        cout << "Running time (Recursive): " << duration2.count() << " nanoseconds\n";

        return 0;
    }