#include <iostream>
#include "MLL.h"

using namespace std;

void judul() {
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*        S I S T E M   P E N D A T A A N         *" << endl;
    cout << "*                    F I L M                     *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
}

void menu() {
    cout << "+------------------------------------------------+" << endl;
    cout << "|                  MENU UTAMA                    |" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| 1. Tambah Film                                 |" << endl;
    cout << "| 2. Tambah Aktor                                |" << endl;
    cout << "| 3. Tambah Peran                                |" << endl;
    cout << "| 4. Tampilkan Semua Film                        |" << endl;
    cout << "| 5. Tampilkan Semua Aktor                       |" << endl;
    cout << "| 6. Tampilkan Aktor Berdasarkan Film            |" << endl;
    cout << "| 7. Tampilkan Film Berdasarkan Aktor            |" << endl;
    cout << "| 8. Edit Peran                                  |" << endl;
    cout << "| 9. Hapus Film                                  |" << endl;
    cout << "|10. Hapus Aktor                                 |" << endl;
    cout << "|11. Hapus Peran                                 |" << endl;
    cout << "| 0. Keluar                                      |" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "Pilih Menu : ";
}

void penutup() {
    cout << endl;
    cout << "==============================================" << endl;
    cout << " TERIMA KASIH TELAH MENGGUNAKAN APLIKASI INI  " << endl;
    cout << "      SISTEM PENDATAAN FILM                   " << endl;
    cout << "==============================================" << endl;
}

int main() {
    ListFilm LF;
    ListAktor LA;
    ListPeran LP;

    createListFilm(LF);
    createListAktor(LA);
    createListPeran(LP);

    Film f1 = {1, "Avengers", 2012};
    Film f2 = {2, "IronMan", 2008};
    Film f3 = {3, "Spiderman", 2019};

    adrFilm af1 = newFilm(f1);
    adrFilm af2 = newFilm(f2);
    adrFilm af3 = newFilm(f3);

    insertFilm(LF, af1);
    insertFilm(LF, af2);
    insertFilm(LF, af3);

    Aktor a1 = {101, "RDJ"};
    Aktor a2 = {102, "Chris"};
    Aktor a3 = {103, "Tom"};

    adrAktor aa1 = newAktor(a1);
    adrAktor aa2 = newAktor(a2);
    adrAktor aa3 = newAktor(a3);

    insertAktor(LA, aa1);
    insertAktor(LA, aa2);
    insertAktor(LA, aa3);

    Peran p1 = {"IronMan"};
    Peran p2 = {"Captain"};
    Peran p3 = {"Spiderman"};

    insertPeran(LP, newPeran(p1, af1, aa1));
    insertPeran(LP, newPeran(p2, af1, aa2));
    insertPeran(LP, newPeran(p1, af2, aa1));
    insertPeran(LP, newPeran(p3, af3, aa3));

    int pilih;

    do {
        judul();
        menu();
        cin >> pilih;

        if (pilih == 1) {
            Film f;
            cout << "ID Film : ";
            cin >> f.idFilm;
            cout << "Judul   : ";
            cin >> f.judul;
            cout << "Tahun   : ";
            cin >> f.tahun;
            insertFilm(LF, newFilm(f));
        }

        else if (pilih == 2) {
            Aktor a;
            cout << "ID Aktor : ";
            cin >> a.idAktor;
            cout << "Nama     : ";
            cin >> a.nama;
            insertAktor(LA, newAktor(a));
        }

        else if (pilih == 3) {
            int idF, idA;
            Peran p;
            cout << "ID Film   : ";
            cin >> idF;
            cout << "ID Aktor  : ";
            cin >> idA;
            cout << "Nama Peran: ";
            cin >> p.namaPeran;

            adrFilm F = findFilm(LF, idF);
            adrAktor A = findAktor(LA, idA);

            if (F != NULL && A != NULL) {
                insertPeran(LP, newPeran(p, F, A));
            }
        }

        else if (pilih == 4) {
            showFilm(LF);
        }

        else if (pilih == 5) {
            showAktor(LA);
        }

        else if (pilih == 6) {
            int idF;
            cout << "ID Film : ";
            cin >> idF;
            showAktorByFilm(LP, idF);
        }

        else if (pilih == 7) {
            int idA;
            cout << "ID Aktor : ";
            cin >> idA;
            showFilmByAktor(LP, idA);
        }

        else if (pilih == 8) {
            int of, oa, nf, na;
            cout << "ID Film Lama  : ";
            cin >> of;
            cout << "ID Aktor Lama : ";
            cin >> oa;
            cout << "ID Film Baru  : ";
            cin >> nf;
            cout << "ID Aktor Baru : ";
            cin >> na;
            editPeran(LP, of, oa, nf, na);
        }

        else if (pilih == 9) {
            int id;
            cout << "ID Film : ";
            cin >> id;
            deleteFilm(LF, id);
        }

        else if (pilih == 10) {
            int id;
            cout << "ID Aktor : ";
            cin >> id;
            deleteAktor(LA, id);
        }

        else if (pilih == 11) {
            int idF, idA;
            cout << "ID Film  : ";
            cin >> idF;
            cout << "ID Aktor : ";
            cin >> idA;
            deletePeran(LP, idF, idA);
        }

        if (pilih != 0) {
            cout << endl;
        }

    } while (pilih != 0);

    penutup();
    return 0;
}
