#include <iostream>
#include <string>
using namespace std;

struct Pasien
{
    int NomorAntrian;
    string NamaLengkap;
    string KeluhanSakit;
    Pasien *next;
};

void tambah(Pasien **head, int NomorAntrian, string NamaLengkap, string KeluhanSakit)
{
    Pasien *pasienBaru = new Pasien;
    pasienBaru->NomorAntrian = NomorAntrian;
    pasienBaru->NamaLengkap = NamaLengkap;
    pasienBaru->KeluhanSakit = KeluhanSakit;
    pasienBaru->next = nullptr;

    if (*head == nullptr)
    {
        *head = pasienBaru;
    }
    else
    {
        Pasien *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = pasienBaru;
    }
}

void lihat(Pasien *head)
{
    if (head == nullptr)
    {
        cout << "Tidak ada antrean" << endl;
        return;
    }

    cout << "Daftar Antrian Pasien:" << endl;
    Pasien *temp = head;
    while (temp != nullptr)
    {
        cout << "Nomor Antrian: " << temp->NomorAntrian << endl;
        cout << "Nama Lengkap: " << temp->NamaLengkap << endl;
        cout << "Keluhan Sakit: " << temp->KeluhanSakit << endl;
        cout << "----------------------------" << endl;
        temp = temp->next;
    }
}

void update(Pasien *head, int NomorAntrian)
{
    Pasien *temp = head;
    while (temp != nullptr)
    {
        if (temp->NomorAntrian == NomorAntrian)
        {
            cout << "Masukkan nama lengkap baru: ";
            cin.ignore();
            getline(cin, temp->NamaLengkap);
            cout << "Masukkan keluhan sakit baru: ";
            getline(cin, temp->KeluhanSakit);
            cout << "Data pasien berhasil diubah" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Tidak dapat menemukan nomor antrian" << endl;
}

void hapus(Pasien **head, int NomorAntrian)
{
    Pasien *temp = *head;
    Pasien *prev = nullptr;

    if (temp != nullptr && temp->NomorAntrian == NomorAntrian)
    {
        *head = temp->next;
        delete temp;
        cout << "Data pasien berhasil dihapus dari antrian" << endl;
        return;
    }

    while (temp != nullptr && temp->NomorAntrian != NomorAntrian)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Nomor antrian tidak ditemukan" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp; 
    cout << "Data pasien berhasil dihapus dari antrian" << endl;
}

int main()
{
    Pasien *head = nullptr; 
    int pilihan;

    do
    {
        cout << "Sistem Antrian Rumah Sakit" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Tampilkan Pasien" << endl;
        cout << "3. Edit Pasien" << endl;
        cout << "4. Hapus Pasien" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            int NomorAntrian;
            string NamaLengkap, KeluhanSakit;
            cout << "Masukkan nomor antrian: ";
            cin >> NomorAntrian;
            cin.ignore();
            cout << "Masukkan nama lengkap: ";
            getline(cin, NamaLengkap);
            cout << "Masukkan keluhan sakit: ";
            getline(cin, KeluhanSakit);

            tambah(&head, NomorAntrian, NamaLengkap, KeluhanSakit);
            cout << "Data pasien berhasil ditambahkan." << endl;
        }
        else if (pilihan == 2)
        {
            lihat(head);
        }
        else if (pilihan == 3)
        {
            int NomorAntrian;
            cout << "Masukkan nomor antrian yang ingin diubah: ";
            cin >> NomorAntrian;
            update(head, NomorAntrian);
        }
        else if (pilihan == 4)
        {
            int NomorAntrian;
            cout << "Masukkan nomor antrian yang ingin dihapus: ";
            cin >> NomorAntrian;
            hapus(&head, NomorAntrian);
        }
    } while (pilihan != 5);

    while (head != nullptr)
    {
        Pasien *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
