#include <iostream>
#include <vector>

#include "FileManager.h"
#include "Customer.h"
#include "Kendaraan.h"
#include "Transaksi.h"

// ================= REGISTER =================
void registerUser(std::vector<User*>& daftarUser)
{
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    int newId = daftarUser.size() + 1;
    daftarUser.push_back(new User(newId, username, password, "customer"));

    std::cout << "✅ Registrasi berhasil\n";
}

// ================= LOGIN =================
User* loginUser(std::vector<User*>& daftarUser)
{
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    for (User* u : daftarUser)
    {
        if (u->login(username, password))
        {
            std::cout << "✅ Login berhasil sebagai " << u->getRole() << "\n";
            return u;
        }
    }

    std::cout << "❌ Login gagal\n";
    return nullptr;
}

void menuAdmin(
    std::vector<Kendaraan>& daftarKendaraan,
    std::vector<Transaksi*>& daftarTransaksi
)
{
    int pilih;
    do
    {
        std::cout << "\n=== MENU ADMIN ===\n";
        std::cout << "1. Lihat Kendaraan\n";
        std::cout << "2. Lihat Semua Transaksi\n";
        std::cout << "3. Tambah Kendaraan\n";
        std::cout << "4. Edit Harga Kendaraan\n";
        std::cout << "5. Hapus Kendaraan\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih: ";
        std::cin >> pilih;

        switch (pilih)
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
                if (daftarTransaksi.empty())
                {
                    std::cout << "⚠ Belum ada transaksi\n";
                    break;
                }

                std::cout << "\n=== DAFTAR TRANSAKSI ===\n";
                for (const Transaksi* t : daftarTransaksi)
                {
                    if (!t) continue;

                    std::cout << "ID Transaksi : " << t->getId() << "\n";
                    std::cout << "Kendaraan    : " << t->getKendaraan().getNama() << "\n";
                    std::cout << "Status       : ";

                    switch (t->getStatus())
                    {
                    case StatusTransaksi::DISEWA:
                        std::cout << "DISEWA\n";
                        break;
                    case StatusTransaksi::DIBAYAR:
                        std::cout << "DIBAYAR\n";
                        break;
                    case StatusTransaksi::SELESAI:
                        std::cout << "SELESAI\n";
                        break;
                    }

                    std::cout << "-----------------------\n";

                    std::cout << "Masukkan ID Transaksi (0 untuk kembali): ";
                        int id;
                        std::cin >> id;

                        if (id == 0) break;

                        for (Transaksi* t : daftarTransaksi)
                        {
                            if (t && t->getId() == id)
                            {
                                t->tampilkanRingkasan();

                                if (!t->isSelesai())
                                {
                                    char konfirmasi;
                                    std::cout << "Tandai transaksi sebagai SELESAI? (y/n): ";
                                    std::cin >> konfirmasi;

                                    if (konfirmasi == 'y' || konfirmasi == 'Y')
                                    {
                                        t->selesaikanTransaksi();
                                        std::cout << "✅ Transaksi diselesaikan\n";
                                    }
                                }
                                break;
                            }
                        }

                }
                break;
            }

        case 3:
        {
            int id;
            std::cout << "Masukkan ID Kendaraan: ";
            std::cin >> id;

            bool ditemukan = false;
            for (auto& k : daftarKendaraan)
            {
                if (k.getId() == id)
                {
                    k.setStatus(!k.isTersedia());
                    std::cout << "✅ Status kendaraan diubah\n";
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
                std::cout << "❌ Kendaraan tidak ditemukan\n";

            break;
        }

        case 4:
        {
            int id;
            double hargaBaru;

            std::cout << "Masukkan ID Kendaraan: ";
            std::cin >> id;

            bool ditemukan = false;
            for (auto& k : daftarKendaraan)
            {
                if (k.getId() == id)
                {
                    std::cout << "Harga lama: Rp " << k.getHargaSewa() << "\n";
                    std::cout << "Harga baru: ";
                    std::cin >> hargaBaru;

                    k.setHargaSewa(hargaBaru);
                    std::cout << "✅ Harga berhasil diubah\n";
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
                std::cout << "❌ Kendaraan tidak ditemukan\n";

            break;
        }

        case 5:
        {
            int id;
            std::cout << "Masukkan ID Kendaraan yang akan dihapus: ";
            std::cin >> id;

            bool ditemukan = false;

            for (auto it = daftarKendaraan.begin(); it != daftarKendaraan.end(); ++it)
            {
                if (it->getId() == id)
                {
                    daftarKendaraan.erase(it);
                    std::cout << "✅ Kendaraan berhasil dihapus\n";
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
                std::cout << "❌ Kendaraan tidak ditemukan\n";

            break;
        }


        case 0:
            FileManager::simpanKendaraan(daftarKendaraan);
            std::cout << "💾 Data kendaraan disimpan\n";
            break;

        default:
            std::cout << "Pilihan tidak valid\n";
        }

    } while (pilih != 0);
}


int main()
{
    std::cout << "=== SISTEM PENYEWAAN KENDARAAN ===\n";

    // ===== LOAD KENDARAAN =====
    std::vector<Kendaraan> daftarKendaraan = FileManager::muatKendaraan();
    std::vector<Transaksi*> daftarTransaksi = FileManager::muatTransaksi(daftarKendaraan);

    if (daftarKendaraan.empty())
    {
        daftarKendaraan.emplace_back(1, "Avanza", "Mobil", 300000);
        daftarKendaraan.emplace_back(2, "Vario", "Motor", 100000);
    }

    std::vector<User*> daftarUser = FileManager::muatUser();
    

    if (daftarUser.empty())
    {
        daftarUser.push_back(new User(1, "admin", "admin123", "admin"));
    }
    
    int pilihAwal;
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "0. Keluar\n";
    std::cin >> pilihAwal;

    User* currentUser = nullptr;

    if (pilihAwal == 1)
        currentUser = loginUser(daftarUser);
    else if (pilihAwal == 2)
    {
        registerUser(daftarUser);
        currentUser = loginUser(daftarUser);
    }
    else
        return 0;

    if (!currentUser) return 0;

    if (currentUser->getRole() == "admin")
    {
        std::cout << "=== ADMIN MODE ===\n";
        menuAdmin(daftarKendaraan, daftarTransaksi);

    }

    else
    {
    std::cout << "=== CUSTOMER MODE ===\n";

    Customer customer(
        currentUser->getId(),
        currentUser->getUsername(),
        currentUser->getPassword()
    );

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
                daftarTransaksi.push_back(t);
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
            std::cout << "Menyimpan data...\n";

            FileManager::simpanUser(daftarUser);
            FileManager::simpanKendaraan(daftarKendaraan);
            FileManager::simpanTransaksi(daftarTransaksi);

            std::cout << "Data berhasil disimpan.\n";
            std::cout << "Terima kasih.\n";
            
            // bersihkan memory
            for (User* u : daftarUser)
                delete u;

            break;

        default:
            std::cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);
    }
    return 0;
}
