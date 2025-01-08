#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Fungsi untuk menemukan pasangan bilangan
vector<pair<int, int>> findPairs(const vector<int>& A, const vector<int>& B, int K) {
    unordered_map<int, int> hashMap; // Untuk menyimpan nilai K - a
    vector<pair<int, int>> result;  // Untuk menyimpan pasangan hasil

    // Masukkan semua elemen dari A ke dalam hashMap
    for (int a : A) {
        hashMap[K - a]++;
    }

    // Periksa elemen di B
    for (int b : B) {
        if (hashMap[b] > 0) { // Jika b ditemukan di hashMap
            result.push_back({K - b, b});
        }
    }

    return result;
}

int main() {
    cout << "=========================" <<endl;
	cout << "Nama  : Zaidin Zidan" <<endl;
	cout << "NIM   : 231011401183" <<endl;
	cout << "Kelas : 03TPLP029" <<endl;
	cout << "=========================" <<endl <<endl;
    
    vector<int> A = {1, 2, 3, 4, 5};  // Contoh array A
    vector<int> B = {6, 7, 8, 9, 10}; // Contoh array B
    int K = 10;                       // Nilai K

    // Cari pasangan bilangan
    vector<pair<int, int>> pairs = findPairs(A, B, K);

    // Cetak hasil
    cout << "Pasangan yang jumlahnya sama dengan " << K << ":\n";
    for (auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
