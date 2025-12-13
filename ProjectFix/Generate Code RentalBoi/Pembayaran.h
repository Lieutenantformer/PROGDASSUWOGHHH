///////////////////////////////////////////////////////////
//  Pembayaran.h
//  Implementation of the Class Pembayaran
//  Created on:      14-Dec-2025 1:15:22 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_A67D9014_FAB6_4088_805D_6146E50D3B5F__INCLUDED_)
#define EA_A67D9014_FAB6_4088_805D_6146E50D3B5F__INCLUDED_

#include <string>

class Pembayaran
{
public:
    Pembayaran();
    virtual ~Pembayaran();

    bool prosesPembayaran(const std::string& metode, double totalTagihan);
    void cetakBukti() const;

private:
    int pembayaranId;
    double jumlahBayar;
    std::string metode;
    bool status; // true = berhasil, false = gagal
};

#endif // !defined(EA_A67D9014_FAB6_4088_805D_6146E50D3B5F__INCLUDED_)
