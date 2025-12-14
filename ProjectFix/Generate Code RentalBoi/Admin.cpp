///////////////////////////////////////////////////////////
//  Admin.cpp
//  Implementation of the Class Admin
//  Created on:      14-Dec-2025 1:15:12 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Admin.h"
#include "FileManager.h"

// Default constructor
Admin::Admin()
    : User()
{
    role = "admin";
}

// Parameterized constructor
Admin::Admin(int inputUserId,
             const std::string& inputUsername,
             const std::string& inputPassword)
    : User(inputUserId, inputUsername, inputPassword, "admin")
{
}

// Destructor
Admin::~Admin()
{
}

// Mengelola data kendaraan (placeholder)
void Admin::kelolaDataKendaraan()
{
    // Logika pengelolaan kendaraan
    // (tambah, edit, hapus, tampilkan)
}

// Mengelola transaksi (placeholder)
void Admin::kelolaTransaksi()
{
    // Logika monitoring / manajemen transaksi
}

// Load data dari file
void Admin::loadData(const std::string& namaFile)
{
    //FileManager fileManager;
    //fileManager.load(namaFile);
}

// Simpan data ke file
void Admin::simpanData(const std::string& namaFile)
{
    //FileManager fileManager;
    //sfileManager.save(namaFile);
}
