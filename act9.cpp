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

}