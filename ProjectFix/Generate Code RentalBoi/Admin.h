///////////////////////////////////////////////////////////
//  Admin.h
//  Implementation of the Class Admin
//  Created on:      14-Dec-2025 1:15:12 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_0BE0888E_6E96_45a5_B032_339179260F5F__INCLUDED_)
#define EA_0BE0888E_6E96_45a5_B032_339179260F5F__INCLUDED_

#include <string>
#include "User.h"

class FileManager;   // forward declaration
class Kendaraan;
class Transaksi;

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
};
#endif // !defined(EA_0BE0888E_6E96_45a5_B032_339179260F5F__INCLUDED_)
