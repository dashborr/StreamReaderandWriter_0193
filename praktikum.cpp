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

void tambahBarang()
{
    ofstream file("gudang.txt", ios::app);

    string barang;

    cin.ignore();

    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Data berhasil ditambahkan.\n";
}

void updateBarang()
{
    vector<string> data = bacaSemuaBarang();

    if (data.empty())
    {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang akan diubah : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size())
    {
        cout << "Nomor tidak valid.\n";
        return;
    }

    cin.ignore();

    string barangBaru;
    cout << "Masukkan nama barang baru : ";
    getline(cin, barangBaru);

    data[nomor - 1] = barangBaru;

    ofstream file("gudang.txt");

    for (string barang : data)
    {
        file << barang << endl;
    }

    file.close();

    cout << "Data berhasil diperbarui.\n";
}

void hapusBarang()
{
    vector<string> data = bacaSemuaBarang();

    if (data.empty())
    {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang akan dihapus : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size())
    {
        cout << "Nomor tidak valid.\n";
        return;
    }

    data.erase(data.begin() + nomor - 1);

    ofstream file("gudang.txt");

    for (string barang : data)
    {
        file << barang << endl;
    }

    file.close();

    cout << "Data berhasil dihapus.\n";
}

void simulasiEtalase()
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    try
    {
        cout << "\nSkenario 1 (Rak 1)\n";
        cout << "Barang ditemukan : "
             << toko.ambilProduk(1)
             << endl;
    }
    catch (string pesan)
    {
        cout << pesan << endl;
    }

    try
    {
        cout << "\nSkenario 2 (Rak 5)\n";
        cout << "Barang ditemukan : "
             << toko.ambilProduk(5)
             << endl;
    }
    catch (string pesan)
    {
        cout << pesan << endl;
    }
}