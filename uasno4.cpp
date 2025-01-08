#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Fungsi untuk mendapatkan digit maksimum dalam array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Fungsi counting sort untuk Radix Sort
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Hitung frekuensi digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Ubah count[] agar berisi posisi akhir elemen
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Bangun array output
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Salin ke array asli
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Fungsi Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Fungsi Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

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
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    		cout << "=========================" <<endl;
	cout << "Nama  : Zaidin Zidan" <<endl;
	cout << "NIM   : 231011401183" <<endl;
	cout << "Kelas : 03TPLP029" <<endl;
	cout << "=========================" <<endl <<endl;

    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Array asli: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Radix Sort
    vector<int> radixArr = arr;
    radixSort(radixArr);
    cout << "Setelah Radix Sort: ";
    for (int num : radixArr) {
        cout << num << " ";
    }
    cout << endl;

    // Quick Sort
    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size() - 1);
    cout << "Setelah Quick Sort: ";
    for (int num : quickArr) {
        cout << num << " ";
    }
    cout << endl;

    // Merge Sort
    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "Setelah Merge Sort: ";
    for (int num : mergeArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
