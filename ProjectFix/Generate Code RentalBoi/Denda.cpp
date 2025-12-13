///////////////////////////////////////////////////////////
//  Denda.cpp
//  Implementation of the Class Denda
//  Created on:      14-Dec-2025 1:15:20 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Denda.h"
#include "Transaksi.h"
#include <ctime>

// Constructor default
Denda::Denda()
    : tarifDendaPerHari(50000.0) // contoh: Rp50.000 per hari
{
}

// Constructor dengan tarif khusus
Denda::Denda(double inputTarifPerHari)
    : tarifDendaPerHari(inputTarifPerHari)
{
}

// Destructor
Denda::~Denda()
{
}

// Hitung jumlah hari keterlambatan
int Denda::hitungHariTerlambat(const Transaksi& transaksi) const
{
    if (!transaksi.isTerlambat())
    {
        return 0;
    }

    time_t sekarang = std::time(nullptr);
    time_t batas = transaksi.getTanggalKembali();

    double selisihDetik = difftime(sekarang, batas);
    int hariTerlambat = static_cast<int>(selisihDetik / (24 * 60 * 60));

    if (hariTerlambat < 1)
        hariTerlambat = 1;

    return hariTerlambat;
}

// Hitung total denda
double Denda::hitungDenda(const Transaksi& transaksi) const
{
    int hariTerlambat = hitungHariTerlambat(transaksi);
    return hariTerlambat * tarifDendaPerHari;
}
