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

    void ubahPangkatDosen(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    friend void lihatGajiStaff(const Staff& staf);

    void displayInfo() const {
        cout << "Nama Staff: " << nama << endl;
        cout << "ID Staff: " << idStaff << endl;
        cout << "Gaji: " << gaji << endl;
    }
};

int main() {
    // Membuat objek Mahasiswa
    Mahasiswa mhs1("Budi Santoso", "MHS001", 85.5);
    Mahasiswa mhs2("Siti Aminah", "MHS002", 92.0);

    // Membuat objek Dosen
    Dosen dsn1("Prof. Dr. Agus Setiawan", "DSN101", "Guru Besar", 5000000);
    Dosen dsn2("Dr. Rina Wijaya", "DSN102", "Lektor Kepala", 4000000);

    // Membuat objek Staff
    Staff staf1("Andi Kurniawan", "STF201", 3500000);
    Staff staf2("Dewi Lestari", "STF202", 3800000);

    cout << "--- Informasi Awal ---" << endl;
    mhs1.displayInfo();
    cout << endl;
    dsn1.displayInfo();
    cout << endl;
    staf1.displayInfo();
    cout << endl;

    // Dosen melihat nilai mahasiswa
    dsn1.lihatNilaiMahasiswa(mhs1);
    dsn2.lihatNilaiMahasiswa(mhs2);
    cout << endl;

    // Staff mengubah pangkat dosen
    staf1.ubahPangkatDosen(dsn2, "Profesor");
    cout << endl;
    dsn2.displayInfo();
    cout << endl;

    // Fungsi friend melihat gaji staff
    lihatGajiStaff(staf2);

    return 0;
}