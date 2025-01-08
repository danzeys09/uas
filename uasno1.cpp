#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Struktur untuk simpul pohon Huffman
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Fungsi pembanding untuk priority_queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Fungsi untuk membangun pohon Huffman
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Masukkan semua karakter ke priority_queue
    for (auto pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Gabungkan simpul-simpul hingga tersisa satu simpul (akar)
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}

// Fungsi untuk menghasilkan kode Huffman dari pohon
void generateHuffmanCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Fungsi untuk melakukan encoding
string encode(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCodes.at(ch);
    }
    return encodedString;
}

// Fungsi untuk melakukan decoding
string decode(const string& encodedString, Node* root) {
    string decodedString;
    Node* current = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedString += current->ch;
            current = root;
        }
    }
    return decodedString;
}

int main() {

    	cout << "=========================" <<endl;
	cout << "Nama  : Zaidin Zidan" <<endl;
	cout << "NIM   : 231011401183" <<endl;
	cout << "Kelas : 03TPLP029" <<endl;
	cout << "=========================" <<endl <<endl;
    
    string text;
    cout << "Masukkan string: ";
    cin >> text;

    // Hitung frekuensi karakter
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Bangun pohon Huffman
    Node* root = buildHuffmanTree(freqMap);

    // Generate kode Huffman
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Cetak kode Huffman
    cout << "Kode Huffman:\n";
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Encode string
    string encodedString = encode(text, huffmanCodes);
    cout << "String terenkode: " << encodedString << "\n";

    // Decode string
    string decodedString = decode(encodedString, root);
    cout << "String terdekode: " << decodedString << "\n";

    return 0;
}
