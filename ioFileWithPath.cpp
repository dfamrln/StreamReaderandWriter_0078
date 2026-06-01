#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string baris;
    string NamaFile;

    cout << "Masukkan Nama File : ";
    cin >> NamaFile;

    //membuka file dalam mode menulis.
    ofstream outfile;
    //menunjuk ke sebuah nama file
    outfile.open(NamaFile + ".txt", ios::out);

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;
    
    //unlimited loop untuk menulis
    while (true) {
        cout << "- ";
        //mendapatkan etiap karakter dalam satu baris
        getline(cin, baris);
        //loop akan berhneti jika anda memasukkan karakter q
        if (baris == "q") break;
        //menulis dan memasukkan nilai dari 'baris' kedalam file
        outfile << baris << endl;
    }
    //selesai dalam menulis sekarang tutp filenya
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;

    //menunjuk kesebuah file
    infile.open(NamaFile + ".txt", ios::in);

    cout << endl << ">= membuka dan membaca file " << endl;
    //jika file ada maka
    if (infile.is_open())
    {
        //melakukkan perulangan setiap baris
        while (getline(infile, baris))
        {
            //dan tampilkan di sini
            cout << baris << '\n';
        }
        //tutup file tersebut setelah selesai
        infile.close();
    }

    //jik tidak ditemukan file maka akan menampilkan ini
    else cout << "unable to opne file";
    return 0;
}