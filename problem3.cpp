#include <iostream>
#include <vector>

void insertionSortAscending(std::vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(std::vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortAroundValue(std::vector<int>& arr, int v) {
    int index = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == v) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cout << "Value not found" << std::endl;
        return;
    }

    insertionSortDescending(arr, 0, index - 1);
    insertionSortAscending(arr, index + 1, arr.size() - 1);

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n, v;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cin >> v;

    sortAroundValue(arr, v);

    return 0;
}
