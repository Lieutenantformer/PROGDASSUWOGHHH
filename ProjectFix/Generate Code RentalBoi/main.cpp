#include <iostream>
#include <vector>

// ===== INCLUDE SEMUA HEADER =====
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Kendaraan.h"
#include "Transaksi.h"
#include "Pembayaran.h"
#include "Denda.h"
#include "FileManager.h"

int main()
{
    std::cout << "=== SISTEM PENYEWAAN KENDARAAN ===\n";

    // Data awal kendaraan
    std::vector<Kendaraan> daftarKendaraan;
    daftarKendaraan.emplace_back(1, "Avanza", "Mobil", 300000);
    daftarKendaraan.emplace_back(2, "Vario", "Motor", 100000);

    // Customer
    Customer customer(1, "budi", "123");

    int pilihan;
    do
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Lihat Kendaraan\n";
        std::cout << "2. Sewa Kendaraan\n";
        std::cout << "3. Lihat Status\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih: ";
        std::cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            for (auto& k : daftarKendaraan)
            {
                k.tampilkanInfo();
                std::cout << "------------------\n";
            }
            break;

        case 2:
            if (customer.sewaKendaraan(2, daftarKendaraan[0]))
                std::cout << "Sewa berhasil\n";
            else
                std::cout << "Sewa gagal\n";
            break;

        case 3:
            customer.lihatStatusPenyewaan();
            break;

        case 0:
            std::cout << "Terima kasih.\n";
            break;

        default:
            std::cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
