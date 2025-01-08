#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi Quick Sort berbasis fungsional
vector<int> quickSort(const vector<int>& arr) {
    // Basis rekursi: jika array memiliki 0 atau 1 elemen, langsung kembalikan
    if (arr.size() <= 1) {
        return arr;
    }

    // Pilih pivot (di sini elemen pertama)
    int pivot = arr[0];

    // Partisi elemen ke dalam dua bagian: lebih kecil dari pivot dan lebih besar dari pivot
    vector<int> less, greater;
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] <= pivot) {
            less.push_back(arr[i]);
        } else {
            greater.push_back(arr[i]);
        }
    }

    // Rekursi untuk mengurutkan bagian 'less' dan 'greater'
    vector<int> sortedLess = quickSort(less);
    vector<int> sortedGreater = quickSort(greater);

    // Gabungkan hasil: less + pivot + greater
    sortedLess.push_back(pivot);
    sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end());

    return sortedLess;
}

int main() {
    	cout << "=========================" <<endl;
	cout << "Nama  : Zaidin Zidan" <<endl;
	cout << "NIM   : 231011401183" <<endl;
	cout << "Kelas : 03TPLP029" <<endl;
	cout << "=========================" <<endl <<endl;
    vector<int> arr = {10, 3, 5, 2, 8, 6, 1, 9, 4, 7};

    // Cetak array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Panggil fungsi quickSort
    vector<int> sortedArr = quickSort(arr);

    // Cetak array setelah diurutkan
    cout << "Array setelah diurutkan: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
