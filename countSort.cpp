#include <iostream>
#include <vector>
#include <algorithm> // for std::min_element

void countSort(std::vector<int>& arr) {
    // Find the range of the elements
    int min_element = *std::min_element(arr.begin(), arr.end());
    int max_element = *std::max_element(arr.begin(), arr.end());
    int range = max_element - min_element + 1;

    // Create a count array to store count of each element
    std::vector<int> count(range, 0);

    // Store count of each element
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min_element]++;

    // Modify the count array to store the actual position of each element in the sorted array
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Create a temporary array to store the sorted elements
    std::vector<int> output(arr.size());

    // Build the sorted array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_element] - 1] = arr[i];
        count[arr[i] - min_element]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    countSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
