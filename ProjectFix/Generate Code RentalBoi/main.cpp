#include <iostream>
#include <vector>

#include "Customer.h"
#include "Kendaraan.h"
#include "Transaksi.h"

int main()
{
    std::cout << "=== SISTEM PENYEWAAN KENDARAAN ===\n";

    std::vector<Kendaraan> daftarKendaraan;
    daftarKendaraan.emplace_back(1, "Avanza", "Mobil", 300000);
    daftarKendaraan.emplace_back(2, "Vario", "Motor", 100000);

    Customer customer(1, "budi", "123");

    int pilihan;
    do
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Lihat Kendaraan\n";
        std::cout << "2. Sewa Kendaraan\n";
        std::cout << "3. Lihat Status Penyewaan\n";
        std::cout << "4. Kembalikan Kendaraan\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih: ";
        std::cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            for (const auto& k : daftarKendaraan)
            {
                k.tampilkanInfo();
                std::cout << "------------------\n";
            }
            break;

        case 2:
            {
                int id;
                std::cout << "Masukkan ID kendaraan: ";
                std::cin >> id;

                Kendaraan* kendaraanDipilih = nullptr;
                for (auto& k : daftarKendaraan)
                {
                    if (k.getId() == id)
                    {
                        kendaraanDipilih = &k;
                        break;
                    }
                }

                if (!kendaraanDipilih)
                {
                    std::cout << "Kendaraan tidak ditemukan.\n";
                    break;
                }

                int durasi;
                std::cout << "Durasi sewa (hari): ";
                std::cin >> durasi;

                if (!customer.sewaKendaraan(durasi, *kendaraanDipilih))
                {
                    std::cout << "Gagal menyewa kendaraan.\n";
                    break;
                }

                Transaksi* t = customer.getTransaksiTerakhir();
                if (!t)
                {
                    std::cout << "Kesalahan transaksi.\n";
                    break;
                }

                std::cout << "Total biaya: Rp " << t->hitungTotalBiaya() << "\n";

                std::cout << "Pilih metode pembayaran:\n";
                std::cout << "1. Cash\n";
                std::cout << "2. Transfer\n";
                std::cout << "3. E-Wallet\n";
                std::cout << "Pilihan: ";

                int pilihBayar;
                std::cin >> pilihBayar;

                std::string metode;
                bool metodeValid = true;

                switch (pilihBayar)
                {
                case 1: metode = "CASH"; break;
                case 2: metode = "TRANSFER"; break;
                case 3: metode = "EWALLET"; break;
                default:
                    std::cout << "❌ Metode pembayaran tidak valid.\n";
                    metodeValid = false;
                    break;
                }

                if (!metodeValid)
                {
                    std::cout << "Transaksi dibatalkan. Kendaraan kembali tersedia.\n";

                    // rollback transaksi
                    customer.kembalikanKendaraan(t->getId());
                    break;
                }
                // === SEWA: BAYAR SEWA SAJA ===
                    std::cout << "Total sewa: Rp " << t->hitungTotalBiaya() << "\n";

                    std::cout << "Lanjutkan pembayaran? (y/n): ";
                    char konfirmasi;
                    std::cin >> konfirmasi;

                if (konfirmasi != 'y' && konfirmasi != 'Y')
                    {
                        std::cout << "Transaksi dibatalkan.\n";
                        customer.kembalikanKendaraan(t->getId()); // rollback
                        break;
                    }


                // === PROSES PEMBAYARAN (HANYA SEKALI) ===
                if (t->prosesPembayaran(metode))
                {
                    std::cout << "Pembayaran berhasil.\n";
                    std::cout << "ID Transaksi: " << t->getId() << "\n";
                    std::cout << "Silakan simpan ID Transaksi untuk pengembalian.\n";
                    t->cetakBuktiPembayaran();
                }
                else
                {
                    std::cout << "Pembayaran gagal.\n";
                }

                break;
            }


        case 3:
            customer.lihatStatusPenyewaan();
            break;

        case 4:
        {
            int idTransaksi;
            std::cout << "Masukkan ID transaksi: ";
            std::cin >> idTransaksi;

            customer.kembalikanKendaraan(idTransaksi);
            break;
        }

        case 0:
            std::cout << "Terima kasih.\n";
            break;

        default:
            std::cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
