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

    if (isTerlambat())
    {
        std::cout << "⚠ TERLAMBAT! Segera kembalikan kendaraan\n";
    }

    std::cout << "-----------------------------\n";
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

double Transaksi::hitungTotalBayar(double tarifDendaPerHari) const
{
    double total = hitungTotalBiaya();

    int hariTerlambat = hitungHariTerlambat();
    if (hariTerlambat > 0)
    {
        total += hariTerlambat * tarifDendaPerHari;
    }

    return total;
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

    totalBiaya = hitungTotalBiaya(); //  TANPA DENDA

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

int Transaksi::hitungHariTerlambat() const
{
    if (status == StatusTransaksi::SELESAI)
        return 0;

    time_t sekarang = std::time(nullptr);

    if (sekarang <= tanggalKembali)
        return 0;

    double selisih = difftime(sekarang, tanggalKembali);
    return static_cast<int>(selisih / (24 * 60 * 60));
}

double Transaksi::getBiayaSewa() const
{
    return hitungTotalBiaya();
}

double Transaksi::getDenda(double tarifPerHari) const
{
    int hariTerlambat = hitungHariTerlambat();
    return hariTerlambat > 0 ? hariTerlambat * tarifPerHari : 0;
}

double Transaksi::getTotalBayar(double tarifPerHari) const
{
    return getBiayaSewa() + getDenda(tarifPerHari);
}

void Transaksi::tampilkanRincianPembayaran(double tarifPerHari) const
{
    double sewa  = getBiayaSewa();
    double denda = getDenda(tarifPerHari);
    double total = sewa + denda;

    std::cout << "Total sewa  : Rp " << sewa << "\n";
    std::cout << "Denda       : Rp " << denda << "\n";
    std::cout << "-------------------------\n";
    std::cout << "Total bayar : Rp " << total << "\n";
}

bool Transaksi::bayarDenda(const std::string& metode, double tarifPerHari)
{
    int hari = hitungHariTerlambat();
    if (hari <= 0)
        return true; // tidak ada denda

    double totalDenda = hari * tarifPerHari;

    std::cout << "\n=== PEMBAYARAN DENDA ===\n";
    std::cout << "Terlambat : " << hari << " hari\n";
    std::cout << "Denda     : Rp " << totalDenda << "\n";

    Pembayaran bayar;
    if (!bayar.prosesPembayaran(metode, totalDenda))
        return false;

    dendaLunas = true;
    return true;
}

