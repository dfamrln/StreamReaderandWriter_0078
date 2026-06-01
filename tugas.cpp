#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

using namespace std;


class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop";
        etalase[1] = "Smartphone";
        etalase[2] = "Printer";
    }

    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (out_of_range&) {
            throw string(
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!"
            );
        }
    }
};

void tampilkanBarang() {
    ifstream file("gudang.txt");
    string barang;

    cout << "\n===== DATA GUDANG =====\n";

    if (!file.is_open()) {
        cout << "File belum tersedia.\n";
        return;
    }

    int nomor = 1;
    while (getline(file, barang)) {
        cout << nomor++ << ". " << barang << endl;
    }

    file.close();
}

void tambahBarang() {
    ofstream file("gudang.txt", ios::app);

    string barang;
    cin.ignore();

    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}

void updateBarang() {
    ifstream file("gudang.txt");
    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }
    file.close();

    int nomor;
    cout << "Nomor barang yang ingin diubah: ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    cin.ignore();
    cout << "Masukkan nama barang baru: ";
    getline(cin, data[nomor - 1]);

    ofstream out("gudang.txt");

    for (string item : data) {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil diperbarui.\n";
}

void hapusBarang() {
    ifstream file("gudang.txt");
    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    int nomor;
    cout << "Nomor barang yang ingin dihapus: ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    data.erase(data.begin() + (nomor - 1));

    ofstream out("gudang.txt");

    for (string item : data) {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil dihapus.\n";
}

void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    try {
        cout << "Skenario 1 (Rak 1)\n";
        cout << "Barang: "
             << toko.ambilProduk(1)
             << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }

    cout << endl;

    try {
        cout << "Skenario 2 (Rak 5)\n";
        cout << "Barang: "
             << toko.ambilProduk(5)
             << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n================================\n";
        cout << " TOKO ELEKTRONIK GIBRAN JAYA\n";
        cout << "================================\n";

        tampilkanBarang();

        cout << "\nMenu:\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";

        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;

        case 2:
            tampilkanBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}