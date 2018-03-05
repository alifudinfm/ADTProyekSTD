#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
#include <string>

#define info(P) P->info
#define nim(P) P->info.nim
#define nama(P) P->info.nama
#define ipk(P) P->info.ipk
#define namaAyah(P) P->info.namaAyah
#define namaIbu(P) P->info.namaIbu
#define next(P) P->next
#define first(L) ((L).first)
#define nil NULL

#define firstMK(P) P->firstMK

#define kodeMK(M) M->infoMK.kodeMK
#define namaMK(M) M->infoMK.namaMK
#define semester(M) M->infoMK.semester
#define nilaiMK(M) M->infoMK.nilaiMK

#define nextMK(M) M->nextMK

using namespace std;

typedef struct elemen *address;
typedef struct elemenMK *addressMK;
struct mahasiswa
{
    string nim;
    string nama;
    int ipk;
    string namaAyah;
    string namaIbu;
};

struct dataMK
{
    string kodeMK;
    string namaMK;
    int semester;
    int nilaiMK;
};
struct elemen
{
    mahasiswa info;
    address next;
    addressMK firstMK;

};

struct elemenMK
{
    addressMK nextMK;
    dataMK infoMK;
};
struct list
{
    address first;
};

void input(string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu);
void alokasiMa(address &p,string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu);
address alokasuMK(char kodeMK[5],char namaMK[20],int semester,int nilaiMK);
void createList(list &l);
void insertFirst(list &l, address &p);
void insertAfter(list &l, address &prec, address &p);
void insertLast(list &l,address &q, address &p);
void deleteFirst(list &l);
void deleteLast(list &l);
void deleteAfter(list &l, address prec);
void printInfo(list l);

void insertFirstMK(list &l, addressMK &m, string &nim);
void printInfoMK(list &l,string &nim);
void createMK(list &l,string &nim);

void insertTerurut(list &L1, address &p,string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu);
void cari(list &l,string &nim);
void menuUtama(list &L1, address &p,string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu);


#endif // MULTILIST_H_INCLUDED
