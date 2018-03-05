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
void menuUtama(list &L1, address &p,string &nim, string &nama, int &ipk, string &namaAyah, string &namaIbu)
{

    int n,i,x;
    string temp;
    while(x!=999)
    {
        addressMK m = new elemenMK;
        nextMK(m) = NULL;

        cout<<"----------------------------------------------------"<<endl;
        cout<<"--------------------MENU UTAMA----------------------"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"0. Buat list baru"<<endl;
        cout<<"1. Masukan data"<<endl;
        cout<<"2. Hapus data"<<endl;
        cout<<"3. Lihat data"<<endl;
        cout<<"4. Daftarkan NIM unutk mengambil MK"<<endl;
        cout<<"5. Masukan data MK"<<endl;
        cout<<"6. Lihat data MK yang diambil"<<endl;
        cout<<"7. Edit nilai"<<endl;
        cout<<"8. Memisahkan NIM ganjil dan genap, lalu menyatukannya kembali :')"<<endl;
        cout<<"999. EXIT"<<endl;

        cout<<"Masukan pilihan anda ";
        cin>>x;
        if (x==0)//buat list baru
        {
            createList(L1);
            if (first(L1)==NULL)
            {
                cout<<"List berhasil dibuat"<<endl;
            }
            else
            {
                cout<<"List gagal dibuat"<<endl;
            }
            getch();
            menuUtama(L1,p,nim,nama,ipk,namaAyah,namaIbu);
        }
        else if (x==1)//insert data
        {

            cout<<"Berapa mahasiswa yang diinput? ";
            cin>>n;
            i=0;
            while(i!=n)
            {
                i++;
                cout<<"Mahasiswa ke "<<i<<endl;
                insertTerurut(L1,p,nim,nama,ipk,namaAyah,namaIbu);
                cout<<endl;
            }
            getch();
            menuUtama(L1,p,nim,nama,ipk,namaAyah,namaIbu);

        }
        else if(x==2)//delete data
        {
            string xx;
            cout<<"Masukan NIM yang mau didelete ";
            cin>>xx;

            address q;
            q = first(L1);
            while(next(q)!=NULL)
            {
                q = next(q);
            }//q adalah last

            if(nim(first(L1))==xx)
            {
                deleteFirst(L1);

            }
            else if(nim(q)==xx)
            {
                address u;
                u = first(L1);
                while(next(u)!=NULL)
                {
                    u = next(u);
                }
                next(u) = NULL;
                deleteLast(L1);
            }
            else
            {
                address p;
                p = first(L1);
                while(nim(next(p))!=xx && p!=NULL)
                {
                    p = next(p);
                }
                if (p != NULL)
                {
                    deleteAfter(L1,p);
                }
                else if(p == NULL)
                {
                    cout<<"DATA TIDAK DITEMUKAN"<<endl;
                }

            }
        }
        else if(x==3)//lihat data
        {
            printInfo(L1);
            getch();
            menuUtama(L1,p,nim,nama,ipk,namaAyah,namaIbu);
        }

        else if(x==4)
        {
            cout<<"Masukan NIM yang ingin didaftarkan :";
            cin>>temp;
            createMK(L1,temp);
        }

        else if(x==5)
        {
            string x;

            cout<<"Masukan NIM yang ingin ditambahkan MK : ";
            cin>>x;
            cout<<"Kode MK : ";
            cin>>kodeMK(m);
            cout<<"Nama MK : ";
            cin>>namaMK(m);
            cout<<"Semester : ";
            cin>>semester(m);
            cout<<"Nilai : ";
            cin>>nilaiMK(m);
            insertFirstMK(L1,m,x);

            getch();
            menuUtama(L1,p,nim,nama,ipk,namaAyah,namaIbu);
        }
        else if(x==6)
        {
            cout<<"Masukan NIM yang akan ditampilkan MK nya : ";
            cin>>temp;
            printInfoMK(L1,temp);
            getch();
            menuUtama(L1,p,nim,nama,ipk,namaAyah,namaIbu);

        }
        else if(x==7)
        {

            string xx;
            cout<<"Masukan NIM yang ingin diedit ";
            cin>>xx;

            address x;
            x=first(L1);
            while(x!=NULL && nim(x)!=xx)
            {
                x =  next(x);
            }

            addressMK x1;
            int ni;
            x1 = firstMK(x);
            while(x1!=NULL)
            {
                cout<<"Masukan nilai "<<namaMK(x1)<<" yang baru : ";
                cin>>ni;
                nilaiMK(x1) = ni;
                cout<<endl;
                x1 = nextMK(x1);
            }
            cout<<"Data berhasil diubah!"<<endl;

        }
        else if(x==8)
        {
            int temp1;
            string tempa;
            list L2, L3;
            createList(L2);
            createList(L3);
            address r,rx;
            r = first(L1);
            while(r!=NULL)
            {
                rx = r;
                r = next(r);
                tempa = nim(rx);
                temp1 = atoi(tempa.c_str()); //value = 45

                if(temp1%2==0)
                {
                    insertFirst(L2,rx);
                }
                else
                {
                    insertFirst(L3,rx);
                }
            }
            cout<<"List berisi NIM genap"<<endl;
            printInfo(L2);
            cout<<"List berisi NIM ganjil"<<endl;
            printInfo(L3);

            getch();
            menuUtama(L1,p,nim,nama,ipk,namaAyah,namaIbu);
        }


    }
}
