///////////////////////////////////////////////////////////
//  FileManager.cpp
//  Implementation of the Class FileManager
//  Created on:      14-Dec-2025 1:15:24 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "FileManager.h"
#include "Kendaraan.h"
#include "Transaksi.h"


#include <fstream>
#include <sstream>
#include <iostream>

// ================== KENDARAAN ==================

void FileManager::simpanKendaraan(const std::vector<Kendaraan>& data)
{
    std::ofstream file("kendaraan.txt");
    if (!file.is_open())
    {
        std::cerr << "❌ Gagal membuka file kendaraan.txt\n";
        return;
    }

    for (const Kendaraan& k : data)
    {
        file << k.getId() << "|"
             << k.getNama() << "|"
             << k.getJenis() << "|"
             << k.getHargaSewa() << "|"
             << (k.isTersedia() ? 1 : 0)
             << "\n";
    }

    file.close();
    std::cout << "✅ Data kendaraan berhasil disimpan\n";
}

std::vector<Kendaraan> FileManager::muatKendaraan()
{
    std::vector<Kendaraan> hasil;
    std::ifstream file("kendaraan.txt");

    if (!file.is_open())
    {
        std::cerr << "⚠ File kendaraan.txt belum ada\n";
        return hasil;
    }

    std::string baris;
    while (std::getline(file, baris))
    {
        std::stringstream ss(baris);
        std::string token;

        int id;
        std::string nama;
        std::string jenis;
        double harga;
        bool tersedia;

        std::getline(ss, token, '|'); id = std::stoi(token);
        std::getline(ss, nama, '|');
        std::getline(ss, jenis, '|');
        std::getline(ss, token, '|'); harga = std::stod(token);
        std::getline(ss, token, '|'); tersedia = (token == "1");

        Kendaraan k(id, nama, jenis, harga);
        k.setStatus(tersedia);

        hasil.push_back(k);
    }

    file.close();
    std::cout << "✅ Data kendaraan berhasil dimuat\n";
    return hasil;
}

void FileManager::simpanTransaksi(const std::vector<Transaksi*>& data)
{
    std::ofstream file("transaksi.txt");
    if (!file.is_open())
    {
        std::cerr << "❌ Gagal membuka transaksi.txt\n";
        return;
    }

    for (const Transaksi* t : data)
    {
        if (!t) continue;

        file << t->getId() << "|"
             << t->getKendaraan().getId() << "|"
             << t->getTanggalKembali() << "|"
             << static_cast<int>(t->getStatus()) << "\n";
    }

    file.close();
    std::cout << "✅ Data transaksi disimpan\n";
}
std::vector<Transaksi*> FileManager::muatTransaksi(const std::vector<Kendaraan>& daftarKendaraan)
{
    std::vector<Transaksi*> hasil;
    std::ifstream file("transaksi.txt");

    if (!file.is_open())
    {
        std::cerr << "⚠ File transaksi.txt belum ada\n";
        return hasil;
    }

    std::string baris;
    while (std::getline(file, baris))
    {
        std::stringstream ss(baris);
        std::string token;

        int idTransaksi;
        int kendaraanId;
        time_t tanggalKembali;
        int statusInt;
        (void)idTransaksi;


        std::getline(ss, token, '|'); idTransaksi = std::stoi(token);
        std::getline(ss, token, '|'); kendaraanId = std::stoi(token);
        std::getline(ss, token, '|'); tanggalKembali = std::stol(token);
        std::getline(ss, token, '|'); statusInt = std::stoi(token);

        // Cari kendaraan
        Kendaraan* kendaraanPtr = nullptr;
        for (const auto& k : daftarKendaraan)
        {
            if (k.getId() == kendaraanId)
            {
                kendaraanPtr = const_cast<Kendaraan*>(&k);
                break;
            }
        }

        if (!kendaraanPtr) continue;

        Transaksi* t = new Transaksi();
        t->setIdDariFile(idTransaksi);

        t->restoreDariFile(
            *kendaraanPtr,
            tanggalKembali,
            static_cast<StatusTransaksi>(statusInt)
        );

        hasil.push_back(t);


    }

    file.close();
    std::cout << "✅ Data transaksi dimuat\n";
    return hasil;
}
