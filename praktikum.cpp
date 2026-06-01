#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <stdexcept>

using namespace std;

class TokoElektronik
{
private:
    array<string, 3> etalase;

public:
    TokoElektronik()
    {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }

    string ambilProduk(size_t nomorRak)
    {
        try
        {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&)
        {
            throw string(
                "Gagal Mengambil Barang : Rak nomor " +
                to_string(nomorRak) +
                " kosong atau tidak tersedia!");
        }
    }
};

void tampilkanBarang()
{
    ifstream file("gudang.txt");

    cout << "\n===== DAFTAR BARANG DI GUDANG =====\n";

    if (!file)
    {
        cout << "Belum ada data barang.\n";
        return;
    }

    string barang;
    int no = 1;

    while (getline(file, barang))
    {
        cout << no++ << ". " << barang << endl;
    }

    file.close();
}

vector<string> bacaSemuaBarang()
{
    vector<string> data;
    ifstream file("gudang.txt");

    string barang;

    while (getline(file, barang))
    {
        data.push_back(barang);
    }

    file.close();
    return data;
}