#include "MLL.h"

//mengosongkan list film
void createListFilm(ListFilm &LF) {
    LF.first = NULL;
}

//mengosongkan list
void createListAktor(ListAktor &LA) {
    LA.first = NULL;
}

//mengosongkan list film-aktor(peran)
void createListPeran(ListPeran &LP) {
    LP.first = NULL;
}

//membuat node film baru
adrFilm newFilm(Film x) {
    adrFilm P = new ElmFilm; // alokasi memori, alamat memori disimpen di pointer P
    P->info = x; // data film diterima sebagai parameter x, di salin ke info milik p
    P->next = NULL; // node film baru belum terhubung, di set NULL sebagai akhir list
    return P; // mengembalikan alamat node film yg baru dibuat
}

//membuat node aktor baru
adrAktor newAktor(Aktor x) {
    adrAktor P = new ElmAktor;
    P->info = x;
    P->next = NULL;
    return P;
}


adrPeran newPeran(Peran x, adrFilm F, adrAktor A) {
    adrPeran P = new ElmPeran;
    P->info = x;
    P->film = F;
    P->aktor = A;
    P->next = NULL;
    return P;
}

void insertFilm(ListFilm &LF, adrFilm P) {
    if (LF.first == NULL) {
        LF.first = P; // kalo list film masih kosong, p menjadi list pertama dan terakhir (karena cm 1 node)
    } else {
        adrFilm Q = LF.first; // kalo list ga kosong, pointer q dipake buat ngecek list, mulai dari node pertama
        while (Q->next != NULL) {
            Q = Q->next; // kalo masih ada node setelah q, q terus maju ke node berikutnya, loop berhenti saat q ada di node terakhir
        }
        Q->next = P; // node terakhir q menunjuk ke node baru p, artinya p berhasil ditambahkan di ujung list
    }
}

void insertAktor(ListAktor &LA, adrAktor P) {
    if (LA.first == NULL) {
        LA.first = P;
    } else {
        adrAktor Q = LA.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertPeran(ListPeran &LP, adrPeran P) {
    if (LP.first == NULL) {
        LP.first = P;
    } else {
        adrPeran Q = LP.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrFilm findFilm(ListFilm LF, int idFilm) {
    adrFilm P = LF.first; // p diarahkan ke node pertama untuk ngecek data film satu satu
    while (P != NULL) { // selama p belom sampe akhir, program bakal terus meriksa node
        if (P->info.idFilm == idFilm) { // ngecek idfilm yang disini sama ga sama yg dicari
            return P; // kalo sama langsung balikin alamat node film
        }
        P = P->next; // kalo ga sama, ngecek ke node selanjutnya
    }
    return NULL; // setelah semua di cek dan gaada yang cocok, fungsi null sbg tanda data tidak ditemukan
}

adrAktor findAktor(ListAktor LA, int idAktor) {
    adrAktor P = LA.first;
    while (P != NULL) {
        if (P->info.idAktor == idAktor) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

bool isRelated(ListPeran LP, int idFilm, int idAktor) {
    adrPeran P = LP.first;
    while (P != NULL) {
        if (P->film->info.idFilm == idFilm &&
            P->aktor->info.idAktor == idAktor) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void deleteFilm(ListFilm &LF, int idFilm) {
    adrFilm P = LF.first; // p buat nunjuk node yang lagi di cek
    adrFilm Q = NULL; // q buat nyimpen node sebelumnya, awalnya masih null karena blm ada node sebelumnya
    while (P != NULL && P->info.idFilm != idFilm) { // selama p belum sampe akhir list dan idfilm belom sama sama yg lagi di cari
        Q = P; // q akan terus pindah ke p
        P = P->next; // p akan terus pindah ke node selanjutnya
    }
    if (P != NULL) { // jika p ga null, film dengan idfilm berhasil ditemukan
        if (Q == NULL) { // jika node film yang dihapus adalah node pertama
            LF.first = P->next; // pointer first dipindah ke node selanjutnya
        } else {
            Q->next = P->next; // node sebelumnya (q), disambung ke node setelah p, node p dilewati dari list
        }
        delete P; // node film yang sudah dilepas dihapus dari memori
    }
}

void deleteAktor(ListAktor &LA, int idAktor) {
    adrAktor P = LA.first;
    adrAktor Q = NULL;
    while (P != NULL && P->info.idAktor != idAktor) {
        Q = P;
        P = P->next;
    }
    if (P != NULL) {
        if (Q == NULL) {
            LA.first = P->next;
        } else {
            Q->next = P->next;
        }
        delete P;
    }
}

void deletePeran(ListPeran &LP, int idFilm, int idAktor) {
    adrPeran P = LP.first;
    adrPeran Q = NULL;
    while (P != NULL &&
          !(P->film->info.idFilm == idFilm &&
            P->aktor->info.idAktor == idAktor)) {
        Q = P;
        P = P->next;
    }
    if (P != NULL) {
        if (Q == NULL) {
            LP.first = P->next;
        } else {
            Q->next = P->next;
        }
        delete P;
    }
}

void showFilm(ListFilm LF) {
    adrFilm P = LF.first; // p diarahkan ke node pertama buat ngakses data film satu satu
    while (P != NULL) { // selama p belum sampe akhir list / selama masih ada film yang bisa ditampilkan
        cout << P->info.idFilm << " " << P->info.judul << " " << P->info.tahun << endl; // menampilkan idfilm, judul, dan tahun rilis, data diambil dari node yang lagi diakses
        P = P->next; // pointer berpindah ke node film berikutnya, agar semua data bisa ditampilkan satu satu
    }
}

void showAktor(ListAktor LA) {
    adrAktor P = LA.first;
    while (P != NULL) {
        cout << P->info.idAktor << " " << P->info.nama << endl;
        P = P->next;
    }
}

void showAktorByFilm(ListPeran LP, int idFilm) {
    adrPeran P = LP.first;
    while (P != NULL) {
        if (P->film->info.idFilm == idFilm) {
            cout << P->aktor->info.nama << " (" << P->info.namaPeran << ")" << endl;
        }
        P = P->next;
    }
}

void showFilmByAktor(ListPeran LP, int idAktor) {
    adrPeran P = LP.first;
    while (P != NULL) {
        if (P->aktor->info.idAktor == idAktor) {
            cout << P->film->info.judul << " (" << P->info.namaPeran << ")" << endl;
        }
        P = P->next;
    }
}

void showAllFilmWithAktor(ListFilm LF, ListPeran LP) {
    adrFilm F = LF.first;
    while (F != NULL) {
        cout << F->info.judul << endl;
        showAktorByFilm(LP, F->info.idFilm);
        F = F->next;
    }
}

void showAllAktorWithFilm(ListAktor LA, ListPeran LP) {
    adrAktor A = LA.first;
    while (A != NULL) {
        cout << A->info.nama << endl;
        showFilmByAktor(LP, A->info.idAktor);
        A = A->next;
    }
}

int countAktorByFilm(ListPeran LP, int idFilm) {
    int count = 0;
    adrPeran P = LP.first;
    while (P != NULL) {
        if (P->film->info.idFilm == idFilm) {
            count++;
        }
        P = P->next;
    }
    return count;
}

int countFilmByAktor(ListPeran LP, int idAktor) {
    int count = 0;
    adrPeran P = LP.first;
    while (P != NULL) {
        if (P->aktor->info.idAktor == idAktor) {
            count++;
        }
        P = P->next;
    }
    return count;
}

int countFilmNoAktor(ListFilm LF, ListPeran LP) {
    int count = 0;
    adrFilm F = LF.first;
    while (F != NULL) {
        if (countAktorByFilm(LP, F->info.idFilm) == 0) {
            count++;
        }
        F = F->next;
    }
    return count;
}

int countAktorNoFilm(ListAktor LA, ListPeran LP) {
    int count = 0;
    adrAktor A = LA.first;
    while (A != NULL) {
        if (countFilmByAktor(LP, A->info.idAktor) == 0) {
            count++;
        }
        A = A->next;
    }
    return count;
}

void editPeran(ListPeran &LP, int oldIdFilm, int oldIdAktor, int newIdFilm, int newIdAktor) {
    adrPeran P = LP.first;
    while (P != NULL) {
        if (P->film->info.idFilm == oldIdFilm &&
            P->aktor->info.idAktor == oldIdAktor) {
            P->film->info.idFilm = newIdFilm;
            P->aktor->info.idAktor = newIdAktor;
            return;
        }
        P = P->next;
    }
}
