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
class FileManager;

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
    ~Transaksi();

    // Lifecycle
    void mulaiTransaksi(Kendaraan& kendaraan, int durasi);
    void selesaikanTransaksi();

    // Tampilan
    void tampilkanRingkasan() const;
    void tampilkanRincianPembayaran(double tarifPerHari) const;

    // Perhitungan
    double hitungTotalBiaya() const;              // sewa
    int hitungHariTerlambat() const;
    double getDenda(double tarifPerHari) const;
    double getBiayaSewa() const;
    double getTotalBayar(double tarifPerHari) const;

    // Pembayaran
    bool prosesPembayaran(const std::string& metode);
    bool bayarDenda(const std::string& metode, double tarifPerHari);
    void cetakBuktiPembayaran() const;

    // Status
    bool isTerlambat() const;
    bool sudahDibayar() const;
    bool sudahBayarDenda() const;
    bool isAktif() const;
    bool isSelesai() const;
    StatusTransaksi getStatus() const;

    // Getter
    int getId() const;
    Kendaraan& getKendaraan() const;
    Kendaraan* getKendaraanPtr() const;
    time_t getTanggalKembali() const;

    // File restore
    friend class FileManager;
    void setIdDariFile(int id);
    void restoreDariFile(Kendaraan& k, time_t tglKembali, StatusTransaksi status);

private:
    int transaksiId;
    int durasiSewa;
    time_t tanggalSewa;
    time_t tanggalKembali;
    double totalBiaya;
    bool dendaLunas;

    static int nextId;

    StatusTransaksi status;
    Kendaraan* kendaraan;
    Pembayaran* pembayaran;
};


#endif // !defined(EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_)
