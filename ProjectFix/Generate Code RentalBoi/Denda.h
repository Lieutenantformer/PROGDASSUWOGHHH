///////////////////////////////////////////////////////////
//  Denda.h
//  Implementation of the Class Denda
//  Created on:      14-Dec-2025 1:15:20 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_F485FD10_E81A_4ea4_9054_9DAD27015B4E__INCLUDED_)
#define EA_F485FD10_E81A_4ea4_9054_9DAD27015B4E__INCLUDED_

class Transaksi;

class Denda
{
public:
    Denda();
    Denda(double inputTarifPerHari);
    virtual ~Denda();

    int hitungHariTerlambat(const Transaksi& transaksi) const;
    double hitungDenda(const Transaksi& transaksi) const;

private:
    double tarifDendaPerHari;
};

#endif // !defined(EA_F485FD10_E81A_4ea4_9054_9DAD27015B4E__INCLUDED_)
