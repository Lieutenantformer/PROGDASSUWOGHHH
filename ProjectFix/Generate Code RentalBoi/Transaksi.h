///////////////////////////////////////////////////////////
//  Transaksi.h
//  Implementation of the Class Transaksi
//  Created on:      14-Dec-2025 1:15:18 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_)
#define EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_

#include <ctime>

class Kendaraan;
class Pembayaran;

class Transaksi
{
public:
    Transaksi();
    virtual ~Transaksi();

    void mulaiTransaksi(Kendaraan& kendaraan, int durasi);
    void selesaikanTransaksi();

    double hitungTotalBiaya() const;
    bool isTerlambat() const;

    int getId() const;
    Kendaraan& getKendaraan() const;

private:
    int transaksiId;
    int durasiSewa;
    time_t tanggalSewa;
    time_t tanggalKembali;
    double totalBiaya;
    bool status; // true = aktif, false = selesai

    Kendaraan* kendaraan;
    Pembayaran* pembayaran;
};
#endif // !defined(EA_D8174133_CC3C_4997_88F3_85ED5105EDCE__INCLUDED_)
