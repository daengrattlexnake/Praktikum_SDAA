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

void push(Pasien **top, int NomorAntrian, string NamaLengkap, string KeluhanSakit)
{
    Pasien *pasienBaru = new Pasien;
    pasienBaru->NomorAntrian = NomorAntrian;
    pasienBaru->NamaLengkap = NamaLengkap;
    pasienBaru->KeluhanSakit = KeluhanSakit;
    pasienBaru->next = *top;
    *top = pasienBaru;
    cout << "Pasien berhasil ditambahkan ke stack." << endl;
}

void pop(Pasien **top)
{
    if (*top == nullptr)
    {
        cout << "Stack kosong, tidak ada pasien untuk dihapus." << endl;
        return;
    }

    Pasien *temp = *top;
    *top = (*top)->next;
    cout << "Pasien dengan nomor antrian " << temp->NomorAntrian << " dihapus dari stack." << endl;
    delete temp;
}

void hapus(Pasien **head)
{
    if (*head == nullptr)
    {
        cout << "Queue kosong, tidak ada pasien untuk dihapus." << endl;
        return;
    }

    Pasien *temp = *head;
    *head = (*head)->next;
    cout << "Pasien dengan nomor antrian " << temp->NomorAntrian << " dihapus dari queue." << endl;
    delete temp;
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

void lihatStack(Pasien *top)
{
    if (top == nullptr)
    {
        cout << "Stack kosong" << endl;
        return;
    }

    cout << "Daftar Antrian Pasien:" << endl;
    Pasien *temp = top;
    while (temp != nullptr)
    {
        cout << "Nomor Antrian: " << temp->NomorAntrian << endl;
        cout << "Nama Lengkap: " << temp->NamaLengkap << endl;
        cout << "Keluhan Sakit: " << temp->KeluhanSakit << endl;
        cout << "----------------------------" << endl;
        temp = temp->next;
    }
}

void lihatSemua(Pasien *head, Pasien *top) {
    cout << "Daftar Pasien dalam Queue:" << endl;
    lihat(head); 

    cout << "Daftar Pasien dalam Stack:" << endl;
    lihatStack(top);  
}

int main()
{
    Pasien *head = nullptr; 
    Pasien *top = nullptr;  
    int pilihan;

    do {
        cout << "==============================" << endl;
        cout << "Sistem Antrian Rumah Sakit" << endl;
        cout << "==============================" << endl;
        cout << "1. Tambah Pasien ke Queue" << endl;
        cout << "2. Tampilkan Semua Pasien (Queue dan Stack)" << endl; 
        cout << "3. Tambah Pasien ke Stack (Push)" << endl;
        cout << "4. Hapus Pasien dari Stack (Pop)" << endl;
        cout << "5. Hapus Pasien dari Queue" << endl; 
        cout << "6. Keluar" << endl;
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

            tambah(&head, NomorAntrian, NamaLengkap, KeluhanSakit);
            cout << "Data pasien berhasil ditambahkan ke queue." << endl;
        }

        else if (pilihan == 2) {  
            lihatSemua(head, top);
        }
        else if (pilihan == 3) {
            int NomorAntrian;
            string NamaLengkap, KeluhanSakit;
            cout << "Masukkan nomor antrian: ";
            cin >> NomorAntrian;
            cin.ignore();
            cout << "Masukkan nama lengkap: ";
            getline(cin, NamaLengkap);
            cout << "Masukkan keluhan sakit: ";
            getline(cin, KeluhanSakit);

            push(&top, NomorAntrian, NamaLengkap, KeluhanSakit);
        }
        else if (pilihan == 4) {
            pop(&top);
        }
        else if (pilihan == 5) {  
            hapus(&head);
        }

    } while (pilihan != 6);

    while (head != nullptr)
    {
        Pasien *temp = head;
        head = head->next;
        delete temp;
    }

    while (top != nullptr)
    {
        Pasien *temp = top;
        top = top->next;
        delete temp;
    }

    return 0;
}
