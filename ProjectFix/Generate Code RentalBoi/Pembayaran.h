///////////////////////////////////////////////////////////
//  Pembayaran.h
//  Implementation of the Class Pembayaran
//  Created on:      14-Dec-2025 1:15:22 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_A67D9014_FAB6_4088_805D_6146E50D3B5F__INCLUDED_)
#define EA_A67D9014_FAB6_4088_805D_6146E50D3B5F__INCLUDED_

#include <string>

enum class MetodePembayaran
{
    CASH,
    TRANSFER,
    EWALLET,
    INVALID
};

class Pembayaran
{
public:
    Pembayaran();

    bool prosesPembayaran(const std::string& metodeInput, double jumlah);
    void cetakBukti() const;

    double getJumlah() const;
    MetodePembayaran getMetode() const;
    bool sudahDibayar() const;

private:
    MetodePembayaran metode;
    double jumlahBayar;

    MetodePembayaran parseMetode(const std::string& input) const;
};

#endif // !defined(EA_A67D9014_FAB6_4088_805D_6146E50D3B5F__INCLUDED_)
