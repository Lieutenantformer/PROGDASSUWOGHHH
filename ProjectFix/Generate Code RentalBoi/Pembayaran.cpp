///////////////////////////////////////////////////////////
//  Pembayaran.cpp
//  Implementation of the Class Pembayaran
//  Created on:      14-Dec-2025 1:15:22 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Pembayaran.h"
#include <iostream>
#include <algorithm>

Pembayaran::Pembayaran()
    : metode(MetodePembayaran::INVALID),
      jumlahBayar(0.0)
{
}

MetodePembayaran Pembayaran::parseMetode(const std::string& input) const
{
    std::string m = input;
    std::transform(m.begin(), m.end(), m.begin(), ::toupper);

    if (m == "CASH")
        return MetodePembayaran::CASH;
    if (m == "TRANSFER")
        return MetodePembayaran::TRANSFER;
    if (m == "E-WALLET" || m == "EWALLET")
        return MetodePembayaran::EWALLET;

    return MetodePembayaran::INVALID;
}

bool Pembayaran::prosesPembayaran(const std::string& metodeInput, double jumlah)
{
    metode = parseMetode(metodeInput);

    if (metode == MetodePembayaran::INVALID)
    {
        std::cout << "❌ Metode pembayaran tidak valid.\n";
        return false;
    }

    jumlahBayar = jumlah;
    return true;
}

void Pembayaran::cetakBukti() const
{
    std::cout << "===== BUKTI PEMBAYARAN =====\n";
    std::cout << "Jumlah : Rp " << jumlahBayar << "\n";
    std::cout << "Metode : ";

    switch (metode)
    {
    case MetodePembayaran::CASH:
        std::cout << "Cash";
        break;
    case MetodePembayaran::TRANSFER:
        std::cout << "Transfer";
        break;
    case MetodePembayaran::EWALLET:
        std::cout << "E-Wallet";
        break;
    default:
        std::cout << "Tidak diketahui";
    }

    std::cout << "\n============================\n";
}

double Pembayaran::getJumlah() const
{
    return jumlahBayar;
}

MetodePembayaran Pembayaran::getMetode() const
{
    return metode;
}

bool Pembayaran::sudahDibayar() const
{
    return jumlahBayar > 0;
}
