#include <iostream>

// Fungsi untuk mengecek apakah titik (x, y) berada di dalam Sierpinski Triangle
bool isSierpinski(int x, int y) {
    while (x > 0 && y > 0) { 
        if ((x % 2 == 1) && (y % 2 == 1)) {
            return false;
        }
        x /= 2;
        y /= 2;
    }
    return true;
}

void generateSierpinski(int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < 2 * height - 1; x++) {
            // Mencari titik tengah segitiga
            int mid = (2 * height - 1) / 2;
            // Memeriksa apakah titik berada dalam batas segitiga
            if (x >= mid - y && x <= mid + y) {
                if (isSierpinski(x - mid, y - (height - 1))) { 
                    std::cout << "*";
                } else {
                    std::cout << " ";
                }
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::cout << "=========================" << std::endl;
    std::cout << "Nama  : Zaidin Zidan" << std::endl;
    std::cout << "NIM   : 231011401183" << std::endl;
    std::cout << "Kelas : 03TPLP029" << std::endl;
    std::cout << "=========================" << std::endl << std::endl;

    int height = 8; // Tinggi segitiga
    std::cout << "Sierpinski Triangle Fractal:\n";
    generateSierpinski(height);
    return 0;
}