///////////////////////////////////////////////////////////
//  Kendaraan.cpp
//  Implementation of the Class Kendaraan
//  Created on:      14-Dec-2025 1:15:16 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Kendaraan.h"
#include <iostream>

// Constructor default
Kendaraan::Kendaraan()
    : kendaraanId(0), hargaSewa(0), status(true)
{
}

// Constructor parameter
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

Kendaraan::~Kendaraan() {}

// ====== GETTER ======

std::string Kendaraan::getNama() const
{
    return nama;
}

std::string Kendaraan::getJenis() const
{
    return jenis;
}

int Kendaraan::getId() const
{
    return kendaraanId;
}

double Kendaraan::getHargaSewa() const
{
    return hargaSewa;
}

bool Kendaraan::isTersedia() const
{
    return status;
}

// ====== SETTER ======

void Kendaraan::setStatus(bool statusBaru)
{
    status = statusBaru;
}

// ====== DISPLAY ======

void Kendaraan::tampilkanInfo() const
{
    std::cout << "ID       : " << kendaraanId << "\n";
    std::cout << "Nama     : " << nama << "\n";
    std::cout << "Jenis    : " << jenis << "\n";
    std::cout << "Harga    : Rp " << hargaSewa << "\n";
    std::cout << "Status   : " << (status ? "Tersedia" : "Disewa") << "\n";
}

void Kendaraan::setHargaSewa(double harga)
{
    hargaSewa = harga;
}
