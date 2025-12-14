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
    : tarifDendaPerHari(50000.0)
{
}

// Destructor
Denda::~Denda()
{
}

// Constructor dengan tarif khusus
Denda::Denda(double inputTarifPerHari)
    : tarifDendaPerHari(inputTarifPerHari)
{
}

// Hitung jumlah hari keterlambatan
int Denda::hitungHariTerlambat(const Transaksi& transaksi) const
{
    time_t sekarang = std::time(nullptr);
    time_t batas = transaksi.getTanggalKembali();

    if (sekarang <= batas)
        return 0;

    double selisihDetik = difftime(sekarang, batas);

    int hariTerlambat =
        static_cast<int>(selisihDetik / (24 * 60 * 60));

    // Minimal 1 hari denda
    return (hariTerlambat < 1) ? 1 : hariTerlambat;
}

// Hitung total denda
double Denda::hitungDenda(const Transaksi& transaksi) const
{
    return hitungHariTerlambat(transaksi) * tarifDendaPerHari;
}