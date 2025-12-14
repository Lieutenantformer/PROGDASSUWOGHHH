///////////////////////////////////////////////////////////
//  Admin.h
//  Implementation of the Class Admin
//  Created on:      14-Dec-2025 1:15:12 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_0BE0888E_6E96_45a5_B032_339179260F5F__INCLUDED_)
#define EA_0BE0888E_6E96_45a5_B032_339179260F5F__INCLUDED_

#include <string>
#include <vector>

#include "User.h"
#include "Transaksi.h"
#include "Kendaraan.h"

class Admin : public User
{
public:
    Admin();
    Admin(int inputUserId,
          const std::string& inputUsername,
          const std::string& inputPassword);

    virtual ~Admin();

    void kelolaDataKendaraan();
    void kelolaTransaksi();

    void loadData(const std::string& namaFile);
    void simpanData(const std::string& namaFile);

private:
    std::vector<Transaksi> daftarTransaksi;
    std::vector<Kendaraan> daftarKendaraan;
    std::vector<User> daftarUser;
};

#endif // !defined(EA_0BE0888E_6E96_45a5_B032_339179260F5F__INCLUDED_)
