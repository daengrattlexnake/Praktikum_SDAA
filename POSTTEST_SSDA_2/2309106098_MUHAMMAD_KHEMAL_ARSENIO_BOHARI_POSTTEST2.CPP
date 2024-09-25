#include <iostream>
#include <string>
using namespace std;


struct Pasien {
    int NomorAntrian;
    string NamaLengkap;
    string KeluhanSakit;
};


void tambah(Pasien* pasienArray, int* jumlahPasien, int NomorAntrian, string NamaLengkap, string KeluhanSakit) {
    Pasien pasienBaru;
    pasienBaru.NomorAntrian = NomorAntrian;
    pasienBaru.NamaLengkap = NamaLengkap;
    pasienBaru.KeluhanSakit = KeluhanSakit;
    
    pasienArray[*jumlahPasien] = pasienBaru;
    (*jumlahPasien)++;
}


void lihat(Pasien* pasienArray, int jumlahPasien) {
    if (jumlahPasien == 0) {
        cout << "Tidak ada ntrian" << endl;
        return;
    }

    cout << "Daftar Antrian Pasien:" << endl;
    for (int i = 0; i < jumlahPasien; i++) {
        cout << "Nomor Antrian: " << pasienArray[i].NomorAntrian << endl;
        cout << "Nama Lengkap: " << pasienArray[i].NamaLengkap << endl;
        cout << "Keluhan Sakit: " << pasienArray[i].KeluhanSakit << endl;
        cout << "----------------------------" << endl;
    }
}


void update(Pasien* pasienArray, int jumlahPasien, int NomorAntrian) {
    for (int i = 0; i < jumlahPasien; i++) {
        if (pasienArray[i].NomorAntrian == NomorAntrian) {
            cout << "Masukkan nama lengkap baru: ";
            cin.ignore();
            getline(cin, pasienArray[i].NamaLengkap);
            cout << "Masukkan keluhan sakit baru: ";
            getline(cin, pasienArray[i].KeluhanSakit);
            cout << "Data pasien berhasil diubah" << endl;
            return;
        }
    }
    cout << "Tidak dapat menemukan nomor antrian" << endl;
}


void hapus(Pasien* pasienArray, int* jumlahPasien, int NomorAntrian) {
    for (int i = 0; i < *jumlahPasien; i++) {
        if (pasienArray[i].NomorAntrian == NomorAntrian) {
            
            for (int j = i; j < *jumlahPasien - 1; j++) {
                pasienArray[j] = pasienArray[j + 1];
            }
            (*jumlahPasien)--;
            cout << "Data pasien berhasil dihapus dari antrian" << endl;
            return;
        }
    }
    cout << "Nomor antrian tidak ditemukan" << endl;
}

int main() {
    const int MAX_PASIEN = 100;
    Pasien pasienArray[MAX_PASIEN]; 
    int jumlahPasien = 0;            

    int pilihan;
    do {
        cout << "Sistem Antrian Rumah Sakit" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Tampilkan Pasien" << endl;
        cout << "3. Edit Pasien" << endl;
        cout << "4. Hapus Pasien" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int NomorAntrian;
            string NamaLengkap, KeluhanSakit;
            cout << "Masukkan nomor antrian: ";
            cin >> NomorAntrian;
            cin.ignore();
            cout << "Masukkan nama lengkap: ";
            getline(cin, NamaLengkap);
            cout << "Masukkan keluhan sakit: ";
            getline(cin, KeluhanSakit);

            tambah(pasienArray, &jumlahPasien, NomorAntrian, NamaLengkap, KeluhanSakit);
            cout << "Data pasien berhasil ditambahkan." << endl;
        } else if (pilihan == 2) {
            lihat(pasienArray, jumlahPasien);
        } else if (pilihan == 3) {
            int NomorAntrian;
            cout << "Masukkan nomor antrian yang ingin diubah: ";
            cin >> NomorAntrian;
            update(pasienArray, jumlahPasien, NomorAntrian);
        } else if (pilihan == 4) {
            int NomorAntrian;
            cout << "Masukkan nomor antrian yang ingin dihapus: ";
            cin >> NomorAntrian;
            hapus(pasienArray, &jumlahPasien, NomorAntrian);
        }
    } while (pilihan != 5);

    return 0;
}
