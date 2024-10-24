#include <iostream>
#include <string>
#include <cmath>
#include <vector>
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

void lihatSemua(Pasien *head, Pasien *top)
{
    cout << "Daftar Pasien dalam Queue:" << endl;
    lihat(head);

    cout << "Daftar Pasien dalam Stack:" << endl;
    lihatStack(top);
}

Pasien *merge(Pasien *left, Pasien *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->NomorAntrian < right->NomorAntrian)
    {
        left->next = merge(left->next, right);
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(Pasien *source, Pasien **front, Pasien **back)
{
    Pasien *slow;
    Pasien *fast;
    slow = source;
    fast = source->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

Pasien *mergeSort(Pasien *head)
{
    if (!head || !head->next)
        return head;

    Pasien *front;
    Pasien *back;

    split(head, &front, &back);

    return merge(mergeSort(front), mergeSort(back));
}

Pasien *partition(Pasien *low, Pasien *high)
{
    int pivot = high->NomorAntrian;
    Pasien *i = low->next;

    for (Pasien *j = low; j != high; j = j->next)
    {
        if (j->NomorAntrian > pivot)
        {
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

int min(int x, int y) { return (x <= y) ? x : y; }

Pasien *fibonacciSearch(Pasien *head, int x, int n)
{
    // Inisialisasi angka Fibonacci
    int fibMMm2 = 0;              // (m-2)'th Fibonacci number
    int fibMMm1 = 1;              // (m-1)'th Fibonacci number
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci number

    // fibM adalah Fibonacci number yang paling kecil yang >= n
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Menyimpan pointer ke node
    Pasien *current = head;
    Pasien *prev = nullptr;

    // Menentukan jumlah elemen yang di-skip
    int offset = -1;

    // Iterasi selama masih ada Fibonacci numbers
    while (fibM > 1)
    {
        // Cek apakah fibMMm2 adalah posisi yang valid
        int i = min(offset + fibMMm2, n - 1);

        // Cek ke node yang diinginkan
        current = head;
        for (int k = 0; k < i; k++)
        {
            prev = current;
            current = current->next;
        }

        // Jika elemen ditemukan, kembalikan
        if (current != nullptr && current->NomorAntrian == x)
        {
            return current;
        }

        // Jika NomorAntrian lebih besar dari target, kurangi Fibonacci
        if (current != nullptr && current->NomorAntrian < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else
        { // Jika lebih kecil, update Fibonacci numbers
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
    }

    // Elemen terakhir
    if (fibMMm1 && current != nullptr && current->NomorAntrian == x)
    {
        return current;
    }

    // Jika tidak ditemukan, kembalikan null
    return nullptr;
}

Pasien *jumpSearch(Pasien *head, int x, int n)
{
    // Tentukan ukuran blok untuk melompat
    int step = sqrt(n);

    // Lakukan iterasi dengan melompat step-size
    Pasien *prev = nullptr;
    Pasien *current = head;
    int count = 0;

    // Melompat hingga kita melewati atau menemukan nilai yang lebih besar
    while (current != nullptr && current->NomorAntrian < x)
    {
        prev = current;
        for (int i = 0; i < step && current != nullptr; i++)
        {
            current = current->next;
            count++;
        }
        if (count >= n)
            break;
    }

    // Lakukan pencarian linier di dalam blok yang ditemukan
    while (prev != nullptr && prev->NomorAntrian < x)
    {
        prev = prev->next;
    }

    // Jika ditemukan, kembalikan node
    if (prev != nullptr && prev->NomorAntrian == x)
    {
        return prev;
    }

    // Jika tidak ditemukan, kembalikan null
    return nullptr;
}

// Fungsi untuk membuat tabel bad character heuristic
void badCharHeuristic(const string &str, vector<int> &badChar)
{
    int m = str.size();
    for (int i = 0; i < 256; i++)
    {
        badChar[i] = -1; // Inisialisasi semua karakter dengan -1
    }
    for (int i = 0; i < m; i++)
    {
        badChar[(int)str[i]] = i; // Set posisi terakhir karakter
    }
}

Pasien *boyerMooreSearch(Pasien *head, const string &keluhan)
{
    Pasien *current = head;

    // Panjang keluhan yang dicari
    int m = keluhan.size();
    vector<int> badChar(256, -1);

    // Inisialisasi bad character heuristic
    badCharHeuristic(keluhan, badChar);

    // Lakukan pencarian untuk setiap pasien
    while (current != nullptr)
    {
        string text = current->KeluhanSakit;
        int n = text.size();

        int s = 0; // s adalah pergeseran string
        while (s <= (n - m))
        {
            int j = m - 1;

            // Bandingkan dari belakang ke depan
            while (j >= 0 && keluhan[j] == text[s + j])
            {
                j--;
            }

            // Jika ditemukan kecocokan, kembalikan pasien
            if (j < 0)
            {
                return current;
            }
            else
            {
                // Geser string menggunakan bad character heuristic
                s += max(1, j - badChar[(int)text[s + j]]);
            }
        }

        current = current->next;
    }

    // Jika tidak ditemukan
    return nullptr;
}

void quickSort(Pasien *low, Pasien *high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        Pasien *pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}

void urutkanPasien(Pasien **head, bool ascending)
{
    if (ascending)
    {
        *head = mergeSort(*head);
    }
    else
    {
        Pasien *tail = *head;
        while (tail->next != nullptr)
        {
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

    do
    {
        cout << "==============================" << endl;
        cout << "Sistem Antrian Rumah Sakit" << endl;
        cout << "==============================" << endl;
        cout << "1. Tambah Pasien ke Queue" << endl;
        cout << "2. Tampilkan Semua Pasien (Queue dan Stack)" << endl;
        cout << "3. Tambah Pasien ke Stack (Push)" << endl;
        cout << "4. Hapus Pasien dari Stack (Pop)" << endl;
        cout << "5. Hapus Pasien dari Queue" << endl;
        cout << "6. Urutkan Pasien" << endl;
        cout << "7. Cari Pasien berdasarkan Nomor Antrian (Fibonacci Search)" << endl;
        cout << "8. Cari Pasien berdasarkan Nomor Antrian (Jump Search)" << endl;
        cout << "9. Cari Pasien berdasarkan Keluhan Sakit (Boyer-Moore Search)" << endl;
        cout << "10. Keluar" << endl;
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
            cout << "Data pasien berhasil ditambahkan ke queue." << endl;
        }

        else if (pilihan == 2)
        {
            lihatSemua(head, top);
        }
        else if (pilihan == 3)
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

            push(&top, NomorAntrian, NamaLengkap, KeluhanSakit);
        }
        else if (pilihan == 4)
        {
            pop(&top);
        }
        else if (pilihan == 5)
        {
            hapus(&head);
        }
        else if (pilihan == 6)
        {
            int mode;
            cout << "Pilih mode pengurutan: 1. Ascending (Merge Sort) 2. Descending (Quick Sort): ";
            cin >> mode;

            if (mode == 1)
            {
                urutkanPasien(&head, true);
                cout << "Pasien telah diurutkan dalam urutan ascending." << endl;
            }
            else if (mode == 2)
            {
                urutkanPasien(&head, false);
                cout << "Pasien telah diurutkan dalam urutan descending." << endl;
            }
            else
            {
                cout << "Pilihan tidak valid." << endl;
            }
        }
        else if (pilihan == 7)
        {
            int nomorAntrian;
            cout << "Masukkan nomor antrian yang ingin dicari: ";
            cin >> nomorAntrian;

            int jumlahPasien = 0;
            Pasien *temp = head;
            while (temp != nullptr)
            {
                jumlahPasien++;
                temp = temp->next;
            }

            Pasien *hasil = fibonacciSearch(head, nomorAntrian, jumlahPasien);
            if (hasil != nullptr)
            {
                cout << "Pasien ditemukan: " << endl;
                cout << "Nomor Antrian: " << hasil->NomorAntrian << endl;
                cout << "Nama Lengkap: " << hasil->NamaLengkap << endl;
                cout << "Keluhan Sakit: " << hasil->KeluhanSakit << endl;
            }
            else
            {
                cout << "Pasien dengan nomor antrian " << nomorAntrian << " tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 8)
        {
            int nomorAntrian;
            cout << "Masukkan nomor antrian yang ingin dicari: ";
            cin >> nomorAntrian;

            int jumlahPasien = 0;
            Pasien *temp = head;
            while (temp != nullptr)
            {
                jumlahPasien++;
                temp = temp->next;
            }

            Pasien *hasil = jumpSearch(head, nomorAntrian, jumlahPasien);
            if (hasil != nullptr)
            {
                cout << "Pasien ditemukan: " << endl;
                cout << "Nomor Antrian: " << hasil->NomorAntrian << endl;
                cout << "Nama Lengkap: " << hasil->NamaLengkap << endl;
                cout << "Keluhan Sakit: " << hasil->KeluhanSakit << endl;
            }
            else
            {
                cout << "Pasien dengan nomor antrian " << nomorAntrian << " tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 9)
        {
            string keluhan;
            cout << "Masukkan keluhan sakit yang ingin dicari: ";
            cin.ignore();
            getline(cin, keluhan);

            Pasien *hasil = boyerMooreSearch(head, keluhan);
            if (hasil != nullptr)
            {
                cout << "Pasien ditemukan: " << endl;
                cout << "Nomor Antrian: " << hasil->NomorAntrian << endl;
                cout << "Nama Lengkap: " << hasil->NamaLengkap << endl;
                cout << "Keluhan Sakit: " << hasil->KeluhanSakit << endl;
            }
            else
            {
                cout << "Pasien dengan keluhan sakit \"" << keluhan << "\" tidak ditemukan." << endl;
            }
        }

    } while (pilihan != 10);

    return 0;
}
