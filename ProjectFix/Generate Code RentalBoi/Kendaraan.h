///////////////////////////////////////////////////////////
//  Kendaraan.h
//  Implementation of the Class Kendaraan
//  Created on:      14-Dec-2025 1:15:16 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_CA0E3458_7482_4ca3_BC1F_C86A62331C94__INCLUDED_)
#define EA_CA0E3458_7482_4ca3_BC1F_C86A62331C94__INCLUDED_

#include <string>

class Kendaraan
{
public:
    Kendaraan();
    Kendaraan(int inputId,
              const std::string& inputNama,
              const std::string& inputJenis,
              double inputHargaSewa);

    virtual ~Kendaraan();
    
    std::string getNama() const;
    std::string getJenis() const;
    int getId() const;
    double getHargaSewa() const;
    bool isTersedia() const;
    void setStatus(bool statusBaru);
    void tampilkanInfo() const;

private:
    int kendaraanId;
    std::string nama;
    std::string jenis;
    double hargaSewa;
    bool status;
};

#endif // !defined(EA_CA0E3458_7482_4ca3_BC1F_C86A62331C94__INCLUDED_)
