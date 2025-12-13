///////////////////////////////////////////////////////////
//  Pembayaran.cpp
//  Implementation of the Class Pembayaran
//  Created on:      14-Dec-2025 1:15:22 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Pembayaran.h"
#include <iostream>

// Constructor
Pembayaran::Pembayaran()
    : pembayaranId(0),
      jumlahBayar(0.0),
      metode(""),
      status(false)
{
}

// Destructor
Pembayaran::~Pembayaran()
{
}

// Proses pembayaran
bool Pembayaran::prosesPembayaran(const std::string& metodeBayar, double totalTagihan)
{
    metode = metodeBayar;
    jumlahBayar = totalTagihan;

    // Simulasi pembayaran selalu berhasil
    status = true;

    return status;
}

// Cetak bukti pembayaran
void Pembayaran::cetakBukti() const
{
    if (!status)
    {
        std::cout << "Pembayaran belum berhasil.\n";
        return;
    }

    std::cout << "=== Bukti Pembayaran ===\n";
    std::cout << "Metode   : " << metode << std::endl;
    std::cout << "Jumlah   : " << jumlahBayar << std::endl;
    std::cout << "Status   : Berhasil\n";
}
