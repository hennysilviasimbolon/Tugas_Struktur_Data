#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

//meyimpan data film
struct Film {
    int idFilm;
    string judul;
    int tahun;
};

//meyimpan data
struct Aktor {
    int idAktor;
    string nama;
};

//meyimpan data
struct Peran {
    string namaPeran;
};

struct ElmFilm;
struct ElmAktor;
struct ElmPeran;

typedef ElmFilm* adrFilm;
typedef ElmAktor* adrAktor;
typedef ElmPeran* adrPeran;

//node untuk list film
struct ElmFilm {
    Film info;
    adrFilm next;
};

//node untuk list aktor
struct ElmAktor {
    Aktor info;
    adrAktor next;
};

//node penghubung(relasi)
struct ElmPeran {
    Peran info;
    adrPeran next;
    adrFilm film;
    adrAktor aktor;
};

//(menyimpan alamat film pertama)
struct ListFilm {
    adrFilm first;
};

//Menyimpan alamat aktor pertama.
struct ListAktor {
    adrAktor first;
};

//menyimpan alamat relasi peran pertama
struct ListPeran {
    adrPeran first;
};

void createListFilm(ListFilm &LF);
void createListAktor(ListAktor &LA);
void createListPeran(ListPeran &LP);

adrFilm newFilm(Film x);
adrAktor newAktor(Aktor x);
adrPeran newPeran(Peran x, adrFilm F, adrAktor A);

void insertFilm(ListFilm &LF, adrFilm P);
void insertAktor(ListAktor &LA, adrAktor P);
void insertPeran(ListPeran &LP, adrPeran P);

void deleteFilm(ListFilm &LF, int idFilm);
void deleteAktor(ListAktor &LA, int idAktor);
void deletePeran(ListPeran &LP, int idFilm, int idAktor);

adrFilm findFilm(ListFilm LF, int idFilm);
adrAktor findAktor(ListAktor LA, int idAktor);
bool isRelated(ListPeran LP, int idFilm, int idAktor);

void showFilm(ListFilm LF);
void showAktor(ListAktor LA);
void showAktorByFilm(ListPeran LP, int idFilm);
void showFilmByAktor(ListPeran LP, int idAktor);
void showAllFilmWithAktor(ListFilm LF, ListPeran LP);
void showAllAktorWithFilm(ListAktor LA, ListPeran LP);

int countAktorByFilm(ListPeran LP, int idFilm);
int countFilmByAktor(ListPeran LP, int idAktor);
int countFilmNoAktor(ListFilm LF, ListPeran LP);
int countAktorNoFilm(ListAktor LA, ListPeran LP);

void editPeran(
    ListPeran &LP,
    int oldIdFilm,
    int oldIdAktor,
    int newIdFilm,
    int newIdAktor
);


#endif // MLL_H_INCLUDED
