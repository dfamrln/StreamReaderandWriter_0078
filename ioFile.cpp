#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string baris;

    // membuka file dalam mode menulis
    ofstream outfile;
    // menunjuk ke sebuah nama file
    outfile.open("data.txt");

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

  // unlimited fule dalam mode menulis
    while (true){
        cout << "- ";
        // mendapatkan setiap karakter dalam sati baris
        getline(cin, baris);
        // loop akan berhenti jika anda memasukkan kerakter q
        if (baris == "q") break;
        // menulis dan memasukkan nilai dari 'baris' ke dalam file
        outfile << baris << endl;
    }
// selesai dalam menulis maka sekarang tutup filenya
    outfile.close();

    // membuka file dalam mode membaca
    ifstream infile;
    // menunjuk ke sebuah nama file
    infile.open("data.txt");

    cout << endl << "> = Membuka dan membaca file " << endl;

 // jika file ada maka
    if (infile.is_open())
    {
        // membaca file atau melakukan perulangan setiap baris
        while (getline(infile, baris))
        {
            // menampilkan baris yang telah dibaca disini
            cout << baris << '\n';
        }
        // tutup file tersebut setelah selesai
        infile.close();
    }
    // jika tdak ditemukan file maka akan menampilkan ini
    else cout << "Unable to open file";
    return 0;
};
