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
