#include <iostream>
#include <vector>

using namespace std;

void ascSort(vector<int>& arr, int start, int end) {
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

void descSort(vector<int>& arr, int start, int end) {
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

void sortAround(vector<int>& arr, int v) {
    int index = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == v) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Value not found" << endl;
        return;
    }

    descSort(arr, 0, index - 1);
    ascSort(arr, index + 1, arr.size() - 1);

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, v;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> v;

    sortAround(arr, v);

    return 0;
}
