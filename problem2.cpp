#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v) {
    int size = v.size();
    for (int i = 1; i < size; i++) {
        int temp = v[i];
        int j = i - 1;
        while(j>=0 && v[j] < temp) {
             v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }
}


int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    insertionSort(v);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
