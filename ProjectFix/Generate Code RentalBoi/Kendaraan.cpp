///////////////////////////////////////////////////////////
//  Kendaraan.cpp
//  Implementation of the Class Kendaraan
//  Created on:      14-Dec-2025 1:15:16 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Kendaraan.h"
#include <iostream>

// Default constructor
Kendaraan::Kendaraan()
    : kendaraanId(0),
      nama(""),
      jenis(""),
      hargaSewa(0.0),
      status(true)   // default tersedia
{
}

// Parameterized constructor
Kendaraan::Kendaraan(int inputId,
                     const std::string& inputNama,
                     const std::string& inputJenis,
                     double inputHargaSewa)
    : kendaraanId(inputId),
      nama(inputNama),
      jenis(inputJenis),
      hargaSewa(inputHargaSewa),
      status(true)
{
}

// Destructor
Kendaraan::~Kendaraan()
{
}

// Ambil harga sewa
double Kendaraan::getHargaSewa() const
{
    return hargaSewa;
}

// Cek ketersediaan
bool Kendaraan::isTersedia() const
{
    return status;
}

// Ubah status kendaraan
void Kendaraan::setStatus(bool statusBaru)
{
    status = statusBaru;
}

// Tampilkan informasi kendaraan
void Kendaraan::tampilkanInfo() const
{
    std::cout << "ID Kendaraan   : " << kendaraanId << std::endl;
    std::cout << "Nama           : " << nama << std::endl;
    std::cout << "Jenis          : " << jenis << std::endl;
    std::cout << "Harga Sewa     : " << hargaSewa << std::endl;
    std::cout << "Status         : "
              << (status ? "Tersedia" : "Disewa") << std::endl;
}

int Kendaraan::getId() const
{
    return kendaraanId;
}
