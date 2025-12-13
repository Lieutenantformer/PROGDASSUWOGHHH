///////////////////////////////////////////////////////////
//  FileManager.cpp
//  Implementation of the Class FileManager
//  Created on:      14-Dec-2025 1:15:24 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "FileManager.h"
#include "Transaksi.h"
#include "Kendaraan.h"
#include "User.h"

#include <fstream>
#include <iostream>

// Constructor
FileManager::FileManager()
{
}

// Destructor
FileManager::~FileManager()
{
}

// Load data dari file
void FileManager::loadData(const std::string& namaFile,
                           std::vector<Transaksi>& daftarTransaksi,
                           std::vector<Kendaraan>& daftarKendaraan,
                           std::vector<User>& daftarUser)
{
    std::ifstream file(namaFile);

    if (!file.is_open())
    {
        std::cerr << "Gagal membuka file input: " << namaFile << std::endl;
        return;
    }

    // ===== SIMULASI LOAD DATA =====
    // (untuk tugas OOP, tidak perlu parsing kompleks)

    std::cout << "Memuat data dari file: " << namaFile << std::endl;

    // Contoh: hanya sebagai placeholder
    // Parsing nyata bisa ditambahkan jika diminta dosen

    file.close();
}

// Simpan data ke file
void FileManager::saveData(const std::string& namaFile,
                           const std::vector<Transaksi>& daftarTransaksi,
                           const std::vector<Kendaraan>& daftarKendaraan,
                           const std::vector<User>& daftarUser)
{
    std::ofstream file(namaFile);

    if (!file.is_open())
    {
        std::cerr << "Gagal membuka file output: " << namaFile << std::endl;
        return;
    }

    std::cout << "Menyimpan data ke file: " << namaFile << std::endl;

    // ===== SIMULASI SAVE DATA =====
    file << "Jumlah Transaksi  : " << daftarTransaksi.size() << std::endl;
    file << "Jumlah Kendaraan  : " << daftarKendaraan.size() << std::endl;
    file << "Jumlah User       : " << daftarUser.size() << std::endl;

    file.close();
}
