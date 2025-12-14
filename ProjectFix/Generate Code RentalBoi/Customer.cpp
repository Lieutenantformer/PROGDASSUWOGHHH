#include "Customer.h"
#include "Transaksi.h"
#include "Kendaraan.h"
#include <iostream>

// Default constructor
Customer::Customer()
    : User()
{
    role = "customer";
}

// Parameterized constructor
Customer::Customer(int inputUserId,
                   const std::string& inputUsername,
                   const std::string& inputPassword)
    : User(inputUserId, inputUsername, inputPassword, "customer")
{
}

// Destructor
Customer::~Customer()
{
    for (Transaksi* t : daftarTransaksi)
    {
        delete t;
    }
    daftarTransaksi.clear();
}

// Menyewa kendaraan
bool Customer::sewaKendaraan(int durasi, Kendaraan& kendaraan)
{
    if (punyaTransaksiAktif())
    {
        std::cout << "Anda masih memiliki penyewaan aktif.\n";
        return false;
    }

    if (!kendaraan.isTersedia())
    {
        std::cout << "Kendaraan tidak tersedia.\n";
        return false;
    }

    Transaksi* transaksiBaru = new Transaksi();
    transaksiBaru->mulaiTransaksi(kendaraan, durasi);

    daftarTransaksi.push_back(transaksiBaru);
    kendaraan.setStatus(false);

    return true;
}

// Mengembalikan kendaraan
bool Customer::kembalikanKendaraan(int transaksiId)
{
    for (Transaksi* t : daftarTransaksi)
    {
        if (!t || t->getId() != transaksiId)
            continue;

        if (!t->sudahDibayar())
        {
            std::cout << "Sewa belum dibayar.\n";
            return false;
        }

        const double TARIF_DENDA = 50000;
        int hariTerlambat = t->hitungHariTerlambat();

        if (hariTerlambat > 0)
        {
            double denda = hariTerlambat * TARIF_DENDA;

            std::cout << "\n=== DENDA KETERLAMBATAN ===\n";
            std::cout << "Terlambat : " << hariTerlambat << " hari\n";
            std::cout << "Denda     : Rp " << denda << "\n";

            std::cout << "Bayar denda sekarang? (y/n): ";
            char pilih;
            std::cin >> pilih;

            if (pilih != 'y' && pilih != 'Y')
            {
                std::cout << "Denda belum dibayar.\n";
                return false;
            }

            if (!t->bayarDenda("CASH", TARIF_DENDA))
            {
                std::cout << "Pembayaran denda gagal.\n";
                return false;
            }
        }

        t->selesaikanTransaksi();
        t->getKendaraan().setStatus(true);

        std::cout << "Kendaraan berhasil dikembalikan.\n";
        return true;
    }

    std::cout << "Transaksi tidak ditemukan.\n";
    return false;
}


// Lihat status penyewaan
void Customer::lihatStatusPenyewaan()
{
    if (daftarTransaksi.empty())
    {
        std::cout << "Belum ada transaksi.\n";
        return;
    }

    for (Transaksi* t : daftarTransaksi)
    {
        if (t)
            t->tampilkanRingkasan();
    }
}

// Ambil transaksi terakhir
Transaksi* Customer::getTransaksiTerakhir() const
{
    if (daftarTransaksi.empty())
        return nullptr;

    return daftarTransaksi.back();
}

// Cek transaksi aktif
bool Customer::punyaTransaksiAktif() const
{
    for (Transaksi* t : daftarTransaksi)
    {
        if (t && t->isAktif())
            return true;
    }
    return false;
}


