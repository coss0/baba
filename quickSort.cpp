#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }
    swap(arr[i + 1], arr[high]);
    comparisons++;
    return i + 1;
}

// Function to implement Quick Sort algorithm
int quickSort(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot_index;
    if (low < high) {
        pivot_index = partition(arr, low, high, comparisons);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pivot_index - 1, comparisons);
        quickSort(arr, pivot_index + 1, high, comparisons);
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

    int comparisons = 0;
    quickSort(arr, 0, n - 1, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
