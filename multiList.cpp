#include"multiList.h"
#include<conio.h>
#include <stdlib.h>
using namespace std;

void input(string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu)
{
    cout<<"Masukan NIM : ";
    cin>>nim;
    cout<<"Masukan nama : ";
    cin>>nama;
    cout<<"Masukan ipk : ";
    cin>>ipk;
    cout<<"Masukan nama ayah : ";
    cin>>namaAyah;
    cout<<"Masukan nama ibu : ";
    cin>>namaIbu;
}

void alokasiMa(address &p,string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu)
{
    p = new elemen;

    nim(p) = nim;
    nama(p) = nama;
    ipk(p) = ipk;
    namaAyah(p) = namaAyah;
    namaIbu(p) = namaIbu;

}
address alokasuMK(char kodeMK[5],char namaMK[20],int semester,int nilaiMK);
void createList(list &l)
{
    first(l) = NULL;
}
void insertFirst(list &l, address &p)
{
    next(p) = first(l);
    first(l) = p;
}
void insertAfter(list &l, address &prec, address &p)
{
    next(p) = next(prec);
    next(prec) = p;
}
void insertLast(list &l,address &q, address &p)
{
    next(p) = NULL;
    next(q) = p;
}
void deleteFirst(list &l)
{
    if(first(l)==NULL)
    {
        cout<<"TIDAK ADA DATA";
    }
    else
    {
        address p;
        p = first(l);
        first(l) = next(first(l));
        next(p) = NULL;
    }

}
void deleteLast(list &l)
{
    address u;
    u = first(l);
    while(next(next(u))!=NULL)
    {
        u = next(u);
    }
    next(u) = NULL;

}
void deleteAfter(list &l, address prec)
{
    address p;
    p = next(prec);
    next(prec) = next(p);
    next(p) = NULL;
}
void printInfo(list l)
{
    address p;
    p = first(l);
    int i=0;
    while(p != NULL)
    {
        i++;
        cout<<endl;
        cout<<i<<".Nim : "<<nim(p)<<endl;
        cout<<"  Nama : "<<nama(p)<<endl;
        cout<<"  IPK : "<<ipk(p)<<endl;
        cout<<"  Nama Ayah : "<<namaAyah(p)<<endl;
        cout<<"  Nama Ibu : "<<namaIbu(p)<<endl;
        cout<<endl;
        p = next(p);
    }
}

void insertFirstMK(list &l, addressMK &m, string &nim)
{
    address p;
    p = first(l);
    while(p!=NULL && nim(p)!=nim)
    {
        p = next(p);
    }
    nextMK(m) = firstMK(p);
    firstMK(p) = m;
}
void printInfoMK(list &l, string &nim)
{
    address p;
    p = first(l);
    while(p!=NULL && nim(p)!=nim)
    {
        p = next(p);
    }
    cout<<"NIM : "<<nim(p)<<endl;
    cout<<"Nama : "<<nama(p)<<endl;
    cout<<"IPK : "<<ipk(p)<<endl;
    cout<<"Nama ayah : "<<namaAyah(p)<<endl;
    cout<<"Nama ibu : "<<namaIbu(p)<<endl;
    cout<<endl;
    cout<<"Mata kuliah yang diambil"<<endl;
    addressMK m;
    m = firstMK(p);
    while (m!=NULL)
    {
        cout<<"Kode MK : "<<kodeMK(m)<<endl;
        cout<<"Nama MK : "<<namaMK(m)<<endl;
        cout<<"Semester : "<<semester(m)<<endl;
        cout<<"nilaiMK : "<<nilaiMK(m)<<endl;
        cout<<endl;

        m = nextMK(m);
    }
}

void createMK(list &l,string &nim)
{
    address p;
    p = first(l);
    while(p!=NULL && nim(p)!=nim)
    {
        p = next(p);
    }
    firstMK(p) = NULL;

}
//Kalo mau make prosedur insertTerurut harus diubah ubah lagi codenya, soalnya rawan ketauan plagiarisme, coba dibalik balik urutan if nya
//Kalo bisa dijadiin contoh aja, terus bikin algoritma sendiri
void insertTerurut(list &L1, address &p,string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu)
    {
        input(nim,nama,ipk,namaAyah,namaIbu);
        alokasiMa(p,nim,nama,ipk,namaAyah,namaIbu);

        address last;
        if(first(L1)!=NULL)
        {
            last = first(L1);
            while (next(last)!= NULL)
            {
                last = next(last);
            }
        }
        if(first(L1)==NULL)
        {
            insertFirst(L1,p);
        }

        else if(ipk(first(L1))>=ipk(p))
        {
            insertFirst(L1,p);
        }

        else if(ipk(p)>=ipk(last))
        {
            insertLast(L1,last,p);
        }
        else
        {
            address y;
            y = first(L1);
            while(ipk(y)>ipk(p) && y!=NULL)
            {
                y = next(y);
            }
            insertAfter(L1,y,p);
        }
    }
void cari(list &l,string nim)
{
    address p;
    p = first(l);
    while(p!=NULL && nim(p)!=nim)
    {
        p = next(p);
    }

}
