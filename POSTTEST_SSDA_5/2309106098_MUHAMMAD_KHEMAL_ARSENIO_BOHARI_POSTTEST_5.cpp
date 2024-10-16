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

Pasien* merge(Pasien* left, Pasien* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->NomorAntrian < right->NomorAntrian) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(Pasien* source, Pasien** front, Pasien** back) {
    Pasien* slow;
    Pasien* fast;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

Pasien* mergeSort(Pasien* head) {
    if (!head || !head->next) return head;

    Pasien* front;
    Pasien* back;

    split(head, &front, &back);

    return merge(mergeSort(front), mergeSort(back));
}

Pasien* partition(Pasien* low, Pasien* high) {
    int pivot = high->NomorAntrian;
    Pasien* i = low->next;
    
    for (Pasien* j = low; j != high; j = j->next) {
        if (j->NomorAntrian > pivot) { 
            swap(i->NomorAntrian, j->NomorAntrian);
            swap(i->NamaLengkap, j->NamaLengkap);
            swap(i->KeluhanSakit, j->KeluhanSakit);
            i = i->next;
        }
    }
    swap(i->NomorAntrian, high->NomorAntrian);
    swap(i->NamaLengkap, high->NamaLengkap);
    swap(i->KeluhanSakit, high->KeluhanSakit);
    return i;
}

void quickSort(Pasien* low, Pasien* high) {
    if (high != nullptr && low != high && low != high->next) {
        Pasien* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}

void urutkanPasien(Pasien** head, bool ascending) {
    if (ascending) {
        *head = mergeSort(*head);
    } else {
        Pasien* tail = *head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        quickSort(*head, tail);
    }
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
        cout << "6. Urutkan Pasien" << endl; 
        cout << "7. Keluar" << endl;
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
        else if (pilihan == 6) {
            int mode;
            cout << "Pilih mode pengurutan: 1. Ascending (Merge Sort) 2. Descending (Quick Sort): ";
            cin >> mode;

            if (mode == 1) {
                urutkanPasien(&head, true);
                cout << "Pasien telah diurutkan dalam urutan ascending." << endl;
            } else if (mode == 2) {
                urutkanPasien(&head, false);
                cout << "Pasien telah diurutkan dalam urutan descending." << endl;
            } else {
                cout << "Pilihan tidak valid." << endl;
            }
        }
    } while (pilihan != 7);

    return 0;
}
