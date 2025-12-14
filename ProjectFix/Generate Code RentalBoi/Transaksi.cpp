///////////////////////////////////////////////////////////
//  Transaksi.cpp
//  Implementation of the Class Transaksi
//  Created on:      14-Dec-2025 1:15:18 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////
#include "Pembayaran.h"
#include "Transaksi.h"
#include "Kendaraan.h"
#include <iostream>
#include <ctime>
#include <stdexcept>

int Transaksi::nextId = 1;
// Constructor
Transaksi::Transaksi()
    : transaksiId(nextId++),
      durasiSewa(0),
      tanggalSewa(0),
      tanggalKembali(0),
      totalBiaya(0.0),
      status(StatusTransaksi::DISEWA),
      kendaraan(nullptr),
      pembayaran(nullptr)
{
}


// Destructor
Transaksi::~Transaksi()
{
    delete pembayaran;
}

// Mulai transaksi penyewaan
void Transaksi::mulaiTransaksi(Kendaraan& kendaraanRef, int durasi)
{
    kendaraan = &kendaraanRef;
    durasiSewa = durasi;
    tanggalSewa = std::time(nullptr);
    tanggalKembali = tanggalSewa + (durasiSewa * 24 * 60 * 60);
    status = StatusTransaksi::DISEWA;
}

// Tampilkan ringkasan transaksi
void Transaksi::tampilkanRingkasan() const
{
    std::cout << "ID Transaksi : " << transaksiId << "\n";
    std::cout << "Durasi       : " << durasiSewa << " hari\n";
    std::cout << "Total Biaya  : "
              << (status == StatusTransaksi::DISEWA
                    ? hitungTotalBiaya()
                    : totalBiaya)
              << "\n";

    std::cout << "Status       : ";
    switch (status)
    {
        case StatusTransaksi::DISEWA:
            std::cout << "Disewa (Belum Dibayar)";
            break;
        case StatusTransaksi::DIBAYAR:
            std::cout << "Sudah Dibayar";
            break;
        case StatusTransaksi::SELESAI:
            std::cout << "Selesai";
            break;
    }
    std::cout << "\n";
}

// Selesaikan transaksi
void Transaksi::selesaikanTransaksi()
{
    status = StatusTransaksi::SELESAI;
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
    return std::time(nullptr) > tanggalKembali;
}

// Getter
int Transaksi::getId() const
{
    return transaksiId;
}

Kendaraan* Transaksi::getKendaraanPtr() const
{
    return kendaraan;
}

Kendaraan& Transaksi::getKendaraan() const
{
    if (!kendaraan)
        throw std::runtime_error("Kendaraan belum diset");
    return *kendaraan;
}

time_t Transaksi::getTanggalKembali() const
{
    return tanggalKembali;
}

// Status helpers
StatusTransaksi Transaksi::getStatus() const
{
    return status;
}

bool Transaksi::isAktif() const
{
    return status == StatusTransaksi::DISEWA ||
           status == StatusTransaksi::DIBAYAR;
}

bool Transaksi::isSelesai() const
{
    return status == StatusTransaksi::SELESAI;
}

// Pembayaran
bool Transaksi::prosesPembayaran(const std::string& metode)
{
    if (pembayaran != nullptr)
    {
        std::cout << "Pembayaran sudah dilakukan.\n";
        return false;
    }

    totalBiaya = hitungTotalBiaya();

    pembayaran = new Pembayaran();
    bool berhasil = pembayaran->prosesPembayaran(metode, totalBiaya);

    if (berhasil)
        status = StatusTransaksi::DIBAYAR;

    return berhasil;
}

void Transaksi::cetakBuktiPembayaran() const
{
    if (pembayaran)
        pembayaran->cetakBukti();
    else
        std::cout << "Belum ada pembayaran.\n";
}

bool Transaksi::sudahDibayar() const
{
    return status == StatusTransaksi::DIBAYAR ||
           status == StatusTransaksi::SELESAI;
}
