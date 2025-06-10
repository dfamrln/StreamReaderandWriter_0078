#include <iostream>
using namespace std;

int main()
{
   try
    {
        cout << "Selamat Belajar di Prodi TI UMY" << endl;
        throw 5; // melemparkan sebuah integer maka
        cout << "Pernyataan tidak akan dieksekusi" << endl;
    }
    catch (int a)
    {
        // blok ini akan dieksekusi
        cout << "Pengecualian akan dieksekusi" << endl;
    }
     catch (...)
}
