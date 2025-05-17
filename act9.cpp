#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int nim;
    float nilai;
public:
    Mahasiswa(string pNama, int pNim) : nama(pNama), nim(pNim), nilai(0.0f) 
    {}

    friend class Dosen;
    void setNilai(float val) {
        nilai = val;
    }
    
    void displayInfo() {
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "Nilai: " << nilai << endl;
    }

};

class Dosen {
private:
    string nama;
    string nidn;
    string pangkat;
    float gaji;
public:
    Dosen(string pNama, string pNidn, string pPangkat, float pGaji)
    : nama(pNama), nidn(pNidn), pangkat(pPangkat), gaji(pGaji) {}

    friend class Staff;
    void setPangkat(string pkt) {
        pangkat = pkt;
    }

    void lihatNilaiMahasiswa(const Mahasiswa& mhs) {
    cout << "Nilai Mahasiswa " << mhs.nama << " (" << mhs.nim << "): " << mhs.nilai << endl;
    }

    void displayInfo() {
        cout << "Nama Dosen: " << nama << endl;
        cout << "NIDN: " << nidn << endl;
        cout << "Pangkat: " << pangkat << endl;
        cout << "Gaji: " << gaji << endl;
    }
};

class Staff {
private:
    string nama;
    int idStaff;
    float gaji;
public:
    Staff(string pNama, int pId, float pGaji) : nama(pNama), idStaff(pId), gaji(pGaji) {}
}