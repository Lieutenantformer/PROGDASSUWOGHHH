///////////////////////////////////////////////////////////
//  Customer.cpp
//  Implementation of the Class Customer
//  Created on:      14-Dec-2025 1:15:14 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

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
        return false;
    }

    Transaksi* transaksiBaru = new Transaksi();
    transaksiBaru->mulaiTransaksi(kendaraan, durasi);

    daftarTransaksi.push_back(transaksiBaru);
    kendaraan.setStatus(false);

    return true;
}

bool Customer::kembalikanKendaraan(int transaksiId)
{
    for (Transaksi* t : daftarTransaksi)
    {
        if (!t) continue;

        if (t->getId() == transaksiId)
        {
            if (t->isSelesai())
            {
                std::cout << "Transaksi ini sudah selesai.\n";
                std::cout << "Terima kasih telah menggunakan layanan kami.\n";
                return false;
            }

            // BELUM DIBAYAR
            if (!t->sudahDibayar())
            {
                std::cout << "Kendaraan belum dibayar. Silakan lakukan pembayaran terlebih dahulu.\n";
                return false;
            }

            //  AMAN DIKEMBALIKAN
            t->selesaikanTransaksi();
            t->getKendaraan().setStatus(true);

            std::cout << "Kendaraan berhasil dikembalikan.\n";
            return true;
        }
    }

    std::cout << "Transaksi tidak ditemukan.\n";
    return false;
}


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


Transaksi* Customer::getTransaksiTerakhir() const
{
    if (daftarTransaksi.empty())
        return nullptr;

    return daftarTransaksi.back();
}

bool Customer::punyaTransaksiAktif() const
{
    for (Transaksi* t : daftarTransaksi)
    {
        if (t && t->isAktif())
            return true;
    }
    return false;
}

