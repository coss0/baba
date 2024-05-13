#include <iostream>
#include <vector>

using namespace std;

// Merge function to merge two subarrays
int merge(vector<int>& arr, int left, int mid, int right) {
    int comparisons = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return comparisons;
}

// Merge sort function
int mergeSort(vector<int>& arr, int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        comparisons += merge(arr, left, mid, right);
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

    int comparisons = mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
