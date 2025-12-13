///////////////////////////////////////////////////////////
//  Transaksi.cpp
//  Implementation of the Class Transaksi
//  Created on:      14-Dec-2025 1:15:18 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Transaksi.h"
#include "Kendaraan.h"
#include <ctime>

// Constructor
Transaksi::Transaksi()
    : transaksiId(0),
      durasiSewa(0),
      tanggalSewa(0),
      tanggalKembali(0),
      totalBiaya(0.0),
      status(false),
      kendaraan(nullptr),
      pembayaran(nullptr)
{
}

// Destructor
Transaksi::~Transaksi()
{
    // pembayaran bisa dibersihkan di sini jika dimiliki Transaksi
    // delete pembayaran;
}

// Mulai transaksi penyewaan
void Transaksi::mulaiTransaksi(Kendaraan& kendaraanRef, int durasi)
{
    kendaraan = &kendaraanRef;
    durasiSewa = durasi;
    tanggalSewa = std::time(nullptr);

    // tanggal kembali = tanggal sewa + durasi (hari)
    tanggalKembali = tanggalSewa + (durasiSewa * 24 * 60 * 60);

    status = true;
}

// Selesaikan transaksi
void Transaksi::selesaikanTransaksi()
{
    status = false;
}

// Hitung total biaya sewa
double Transaksi::hitungTotalBiaya() const
{
    if (!kendaraan)
        return 0.0;

    return kendaraan->getHargaSewa() * durasiSewa;
}

// Cek apakah terlambat
bool Transaksi::isTerlambat() const
{
    time_t sekarang = std::time(nullptr);
    return sekarang > tanggalKembali;
}

// Ambil ID transaksi
int Transaksi::getId() const
{
    return transaksiId;
}

// Ambil kendaraan yang disewa
Kendaraan& Transaksi::getKendaraan() const
{
    return *kendaraan;
}
