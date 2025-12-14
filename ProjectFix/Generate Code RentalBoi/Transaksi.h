///////////////////////////////////////////////////////////
//  Transaksi.h
//  Implementation of the Class Transaksi
//  Created on:      14-Dec-2025 1:15:18 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_)
#define EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_

#include <ctime>
#include <string>

class Kendaraan;
class Pembayaran;

// ================= ENUM STATUS =================
enum class StatusTransaksi
{
    DISEWA,
    DIBAYAR,
    SELESAI
};

class Transaksi
{
public:
    Transaksi();
    virtual ~Transaksi();

    // Lifecycle
    void mulaiTransaksi(Kendaraan& kendaraan, int durasi);
    void selesaikanTransaksi();

    // Tampilan
    void tampilkanRingkasan() const;

    // Perhitungan
    double hitungTotalBiaya() const;
    bool isTerlambat() const;

    // Getter dasar
    int getId() const;
    Kendaraan& getKendaraan() const;
    Kendaraan* getKendaraanPtr() const;
    time_t getTanggalKembali() const;

    // ===== STATUS (SATU KALI SAJA) =====
    StatusTransaksi getStatus() const;
    bool isAktif() const;
    bool isSelesai() const;
    bool sudahDibayar() const;

    // Pembayaran
    bool prosesPembayaran(const std::string& metode);
    void cetakBuktiPembayaran() const;

private:
    int transaksiId;
    int durasiSewa;
    time_t tanggalSewa;
    time_t tanggalKembali;
    double totalBiaya;
    static int nextId; 

    StatusTransaksi status;
    Kendaraan* kendaraan;
    Pembayaran* pembayaran;
};
#endif // !defined(EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_)
