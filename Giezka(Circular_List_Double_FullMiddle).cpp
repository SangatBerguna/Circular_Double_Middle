#include <iostream>
#include <string>

using namespace std;

// struktur linked list untuk data tugas
struct DataTugas {
    string namaTugas, deadlineTugas;
    int nomorTugas;

    // pointer
    DataTugas *sebelum;
    DataTugas *selanjutnya;
};

DataTugas *kepala = nullptr, *ekor = nullptr, *saat_ini = nullptr, *hapus = nullptr, *nodeBaru = nullptr, *setelahNode = nullptr;

// fungsi membuat circular double linked list
void buatDataTugas(string namaTugas, int nomorTugas, string deadlineTugas) {
    kepala = new DataTugas();
    kepala->namaTugas = namaTugas;
    kepala->nomorTugas = nomorTugas;
    kepala->deadlineTugas = deadlineTugas;
    kepala->sebelum = kepala;
    kepala->selanjutnya = kepala;
    ekor = kepala;
}

// add First
void tambahawal(string namaTugas, int nomorTugas, string deadlineTugas) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        nodeBaru = new DataTugas();
        nodeBaru->namaTugas = namaTugas;
        nodeBaru->nomorTugas = nomorTugas;
        nodeBaru->deadlineTugas = deadlineTugas;
        nodeBaru->sebelum = ekor;
        nodeBaru->selanjutnya = kepala;
        kepala->sebelum = nodeBaru;
        ekor->selanjutnya = nodeBaru;
        kepala = nodeBaru;
    }
}

// add Last
void tambahakhir(string namaTugas, int nomorTugas, string deadlineTugas) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        nodeBaru = new DataTugas();
        nodeBaru->namaTugas = namaTugas;
        nodeBaru->nomorTugas = nomorTugas;
        nodeBaru->deadlineTugas = deadlineTugas;
        nodeBaru->sebelum = ekor;
        nodeBaru->selanjutnya = kepala;
        kepala->sebelum = nodeBaru;
        ekor->selanjutnya = nodeBaru;
        ekor = nodeBaru;
    }
}

// add Middle
void tambahtengah(string namaTugas, int nomorTugas, string deadlineTugas, int posisi) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        if (posisi == 1) {
            cout << "Posisi 1 bukan posisi tengah" << endl;
        } else {
            nodeBaru = new DataTugas();
            nodeBaru->namaTugas = namaTugas;
            nodeBaru->nomorTugas = nomorTugas;
            nodeBaru->deadlineTugas = deadlineTugas;

            // traversing
            saat_ini = kepala;
            int nomor = 1;
            while (nomor < posisi - 1 && saat_ini->selanjutnya != kepala) {
                saat_ini = saat_ini->selanjutnya;
                nomor++;
            }

            if (saat_ini->selanjutnya == kepala) {
                cout << "Posisi diluar jangkauan" << endl;
                return;
            }

            setelahNode = saat_ini->selanjutnya;
            saat_ini->selanjutnya = nodeBaru;
            nodeBaru->sebelum = saat_ini;
            nodeBaru->selanjutnya = setelahNode;
            setelahNode->sebelum = nodeBaru;
        }
    }
}

// remove First
void removeFirst() {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else if (kepala == ekor) { // hanya satu node
        delete kepala;
        kepala = nullptr;
        ekor = nullptr;
    } else {
        hapus = kepala;
        kepala = kepala->selanjutnya;
        ekor->selanjutnya = kepala;
        kepala->sebelum = ekor;
        delete hapus;
    }
}

// remove Last
void removeLast() {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else if (kepala == ekor) { // hanya satu node
        delete kepala;
        kepala = nullptr;
        ekor = nullptr;
    } else {
        hapus = ekor;
        ekor = ekor->sebelum;
        ekor->selanjutnya = kepala;
        kepala->sebelum = ekor;
        delete hapus;
    }
}

// remove Middle
void removeMiddle(int posisi) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else if (posisi == 1) {
        cout << "Posisi 1 bukan posisi tengah" << endl;
    } else {
        // traversing
        saat_ini = kepala;
        int nomor = 1;
        while (nomor < posisi - 1 && saat_ini->selanjutnya != kepala) {
            saat_ini = saat_ini->selanjutnya;
            nomor++;
        }

        if (saat_ini->selanjutnya == kepala || saat_ini->selanjutnya == ekor) {
            cout << "Posisi diluar jangkauan atau node terakhir" << endl;
            return;
        }

        hapus = saat_ini->selanjutnya;
        setelahNode = hapus->selanjutnya;
        saat_ini->selanjutnya = setelahNode;
        setelahNode->sebelum = saat_ini;
        delete hapus;
    }
}

// fungsi print
void printDataTugas() {
    if (kepala == nullptr) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        cout << "Data Tugas : " << endl;
        saat_ini = kepala;
        do {
            // print
            cout << "Nama Tugas: " << saat_ini->namaTugas << endl;
            cout << "Nomor Tugas: " << saat_ini->nomorTugas << endl;
            cout << "Deadline Tugas: " << saat_ini->deadlineTugas << "\n" << endl;

            // step
            saat_ini = saat_ini->selanjutnya;
        } while (saat_ini != kepala);
    }
}

int main() {
    buatDataTugas("Tugas 1", 1, "30 Mei 2024");
    printDataTugas();

    tambahawal("Tugas 2", 2, "25 Mei 2024");
    printDataTugas();

    tambahakhir("Tugas 3", 3, "1 Juni 2024");
    printDataTugas();

    tambahtengah("Tugas 4", 4, "28 Mei 2024", 2);
    printDataTugas();

    removeMiddle(2);
    printDataTugas();

    removeFirst();
    printDataTugas();

    removeLast();
    printDataTugas();

    return 0;
}
