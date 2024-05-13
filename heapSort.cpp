#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index i
int heapify(vector<int>& arr, int n, int i, int& comparisons) {
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        comparisons++;
        heapify(arr, n, largest, comparisons);
    }

    return comparisons;
}

// Main function to perform heap sort
int heapSort(vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        comparisons += heapify(arr, n, i, comparisons);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        comparisons += heapify(arr, i, 0, comparisons);
    }

    return comparisons;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int comparisons = heapSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
