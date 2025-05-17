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
    void setPangkat(std::string pkt) {
        pangkat = pkt;
    }

    void lihatNilaiMahasiswa(const Mahasiswa& mhs) const {
        std::cout << "Nilai Mahasiswa " << mhs.nama << " (" << mhs.nim << "): " << mhs.nilai << std::endl;
    }
}