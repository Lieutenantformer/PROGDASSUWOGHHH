///////////////////////////////////////////////////////////
//  FileManager.h
//  Implementation of the Class FileManager
//  Created on:      14-Dec-2025 1:15:24 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_6F47406B_4219_44bb_9E07_9365A625F8A6__INCLUDED_)
#define EA_6F47406B_4219_44bb_9E07_9365A625F8A6__INCLUDED_


#include <string>
#include <vector>

// forward declaration
class Transaksi;
class Kendaraan;
class User;

class FileManager
{
public:
    FileManager();
    virtual ~FileManager();

    void loadData(const std::string& namaFile,
                  std::vector<Transaksi>& daftarTransaksi,
                  std::vector<Kendaraan>& daftarKendaraan,
                  std::vector<User>& daftarUser);

    void saveData(const std::string& namaFile,
                  const std::vector<Transaksi>& daftarTransaksi,
                  const std::vector<Kendaraan>& daftarKendaraan,
                  const std::vector<User>& daftarUser);
};

#endif // !defined(EA_6F47406B_4219_44bb_9E07_9365A625F8A6__INCLUDED_)
