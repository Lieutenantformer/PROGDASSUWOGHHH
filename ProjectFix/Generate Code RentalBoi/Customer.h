///////////////////////////////////////////////////////////
//  Customer.h
//  Implementation of the Class Customer
//  Created on:      14-Dec-2025 1:15:14 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_173CE692_FEB1_441a_B410_0CD680259A4C__INCLUDED_)
#define EA_173CE692_FEB1_441a_B410_0CD680259A4C__INCLUDED_

#include <string>
#include <vector>
#include "User.h"

// forward declaration
class Kendaraan;
class Transaksi;

class Customer : public User
{
public:
    Customer();
    Customer(int inputUserId,
             const std::string& inputUsername,
             const std::string& inputPassword);

    virtual ~Customer();
    
    bool sewaKendaraan(int durasi, Kendaraan& kendaraan);
    bool kembalikanKendaraan(int transaksiId);
    void lihatStatusPenyewaan();
    Transaksi* getTransaksiTerakhir() const;
    bool punyaTransaksiAktif() const;
    const std::vector<Transaksi*>& getDaftarTransaksi() const;


private:
    std::vector<Transaksi*> daftarTransaksi;
};
#endif // !defined(EA_173CE692_FEB1_441a_B410_0CD680259A4C__INCLUDED_)
