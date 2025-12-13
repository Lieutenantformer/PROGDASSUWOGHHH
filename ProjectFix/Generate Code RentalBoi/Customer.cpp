///////////////////////////////////////////////////////////
//  Customer.cpp
//  Implementation of the Class Customer
//  Created on:      14-Dec-2025 1:15:14 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "Customer.h"
#include "Transaksi.h"
#include "Kendaraan.h"

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
    // Bersihkan transaksi jika perlu
    for (Transaksi* t : daftarTransaksi)
    {
        delete t;
    }
    daftarTransaksi.clear();
}

// Menyewa kendaraan
bool Customer::sewaKendaraan(int durasi, Kendaraan& kendaraan)
{
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

// Mengembalikan kendaraan
void Customer::kembalikanKendaraan(int transaksiId)
{
    for (Transaksi* t : daftarTransaksi)
    {
        if (t->getId() == transaksiId)
        {
            t->selesaikanTransaksi();
            t->getKendaraan().setStatus(true);
            break;
        }
    }
}

// Melihat status penyewaan
void Customer::lihatStatusPenyewaan()
{
    for (Transaksi* t : daftarTransaksi)
    {
        t->tampilkanRingkasan();
    }
}
