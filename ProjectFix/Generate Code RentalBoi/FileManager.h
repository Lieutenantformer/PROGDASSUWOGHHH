///////////////////////////////////////////////////////////
//  FileManager.h
//  Implementation of the Class FileManager
//  Created on:      14-Dec-2025 1:15:24 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_6F47406B_4219_44bb_9E07_9365A625F8A6__INCLUDED_)
#define EA_6F47406B_4219_44bb_9E07_9365A625F8A6__INCLUDED_

#include <vector>
#include <string>

// Forward declarations
class Kendaraan;
class Transaksi;
class User;

/*
 * FileManager
 * ------------
 * Utility class untuk menyimpan dan memuat data
 * (Kendaraan, Transaksi, User) dari file.
 *
 * Semua method bersifat static.
 */
class FileManager
{
public:
    // ===== KENDARAAN =====
    static void simpanKendaraan(const std::vector<Kendaraan>& data);
    static std::vector<Kendaraan> muatKendaraan();

    // ===== TRANSAKSI =====
    static void simpanTransaksi(const std::vector<Transaksi*>& data);
    static std::vector<Transaksi*> muatTransaksi(const std::vector<Kendaraan>& daftarKendaraan);

    

    // ===== USER =====
    static void simpanUser(const std::vector<User*>& data);
    static std::vector<User*> muatUser();

private:
    // Cegah instansiasi FileManager
    FileManager() = delete;
};


#endif // !defined(EA_6F47406B_4219_44bb_9E07_9365A625F8A6__INCLUDED_)
