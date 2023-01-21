#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;



bool isSama (double hasil)
{
    if(hasil-24<=0.00000001 && 24-hasil<=0.00000001)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void hitung_hitung(double a,int oprt1,double b,int oprt2,double c,int oprt3,double d,bool simpan,int * jmloprs,ofstream * datafile)
{
    //operator di inisialkan sebagai angka
    //'+' adalah 0
    //'-' adalah 1
    //'*' adalah 2
    //'/' adalah 3
    char oper1,oper2,oper3;
    if(oprt1 ==0)
    {
        oper1 = '+';
    }
    else if(oprt1==1)
    {
        oper1 = '-';
    }
    else if(oprt1==2)
    {
        oper1 = '*';
    }else if(oprt1==3)
    {
        oper1 = '/';
    }
    if(oprt2 ==0)
    {
        oper2 = '+';
    }
    else if(oprt2==1)
    {
        oper2 = '-';
    }
    else if(oprt2==2)
    {
        oper2 = '*';
    }else if(oprt2==3)
    {
        oper2 = '/';
    }
    if(oprt3 ==0)
    {
        oper3 = '+';
    }
    else if(oprt3==1)
    {
        oper3 = '-';
    }
    else if(oprt3==2)
    {
        oper3 = '*';
    }else if(oprt3==3)
    {
        oper3 = '/';
    }

    //------------------------------------
    //Kasus 1 ((a..b)..c)..d
    //------------------------------------
    double kasus1;
    double kasus12;
    if(oprt1==0)
    {
        kasus12=a+b;
    }
    else if(oprt1==1)
    {
        kasus12=a-b;
    }
    else if(oprt1==2)
    {
        kasus12=a*b;
    }
    else if(oprt1==3)
    {
        kasus12=a/b;
    }
    double kasus13;
    if(oprt2==0)
    {
        kasus13=kasus12+c;
    }
    else if(oprt2==1)
    {
        kasus13=kasus12-c;
    }
    else if(oprt2==2)
    {
        kasus13=kasus12*c;
    }
    else if(oprt2==3)
    {
        kasus13=kasus12/c;
    }

    double kasus14;
    if(oprt3==0)
    {
        kasus14=kasus13+d;
    }
    else if(oprt3==1)
    {
        kasus14=kasus13-d;
    }
    else if(oprt3==2)
    {
        kasus14=kasus13*d;
    }
    else if(oprt3==3)
    {
        kasus14=kasus13/d;
    }
    kasus1 = kasus14;// hasil akhir kasus 1

    //------------------------------------
    //Kasus 2 (a..(b..c))..d
    //------------------------------------

    double kasus2;
    double kasus21;
    if(oprt2==0)
    {
        kasus21 = b+c;
    }
    else if(oprt2==1)
    {
        kasus21 = b-c;
    }
    else if(oprt2==2)
    {
        kasus21 = b*c;
    }
    else if(oprt2==3)
    {
        kasus21 = b/c;
    }
    double kasus22;
    if(oprt1==0)
    {
        kasus22 = a+kasus21;
    }
    else if(oprt1 == 1)
    {
        kasus22 = a-kasus21;
    }
    else if(oprt1==2)
    {
        kasus22 = a*kasus21;
    }
    else if(oprt1==3)
    {
        kasus22 = a/kasus21;
    }
    double kasus23;
    if(oprt3==0)
    {
        kasus23 = kasus22+d;
    }
    else if(oprt3 == 1)
    {
        kasus23 = kasus22-d;
    }
    else if(oprt3==2)
    {
        kasus23 = kasus22*d;
    }
    else if(oprt3==3)
    {
        kasus23 = kasus22/d;
    }
    kasus2 = kasus23;//hasil akhir kasus 2
    //------------------------------------
    //Kasus 3 a..((b..c)..d)
    //------------------------------------
    double kasus3;
    double kasus31;
    if(oprt2==0)
    {
        kasus31 = b+c;
    }
    else if(oprt2==1)
    {
        kasus31 = b-c;
    }
    else if(oprt2==2)
    {
        kasus31 = b*c;
    }
    else if(oprt2==3)
    {
        kasus31 = b/c;
    }
    double kasus32;
    if(oprt3 ==0)
    {
        kasus32 = kasus31+d;
    }
    else if(oprt3 ==1)
    {
        kasus32 = kasus31-d;
    }
    else if(oprt3 ==2)
    {
        kasus32 = kasus31*d;
    }
    else if(oprt3 ==3)
    {
        kasus32 = kasus31/d;
    }
    double kasus33;
    if(oprt1 == 0)
    {
        kasus33 = a+kasus32;
    }
    else if(oprt1 == 1)
    {
        kasus33 = a-kasus32;
    }
    else if(oprt1 == 2)
    {
        kasus33 = a*kasus32;
    }
    else if(oprt1 == 3)
    {
        kasus33 = a/kasus32;
    }
    kasus3 = kasus33;//hasil akhir kasus 3
    //------------------------------------
    //Kasus 4 a..(b..(c..d))
    //------------------------------------
    double kasus4;
    double kasus41;
    if(oprt3==0)
    {
        kasus41 = c+d;
    }
    else if(oprt3==1)
    {
        kasus41 = c-d;
    }
    else if(oprt3==2)
    {
        kasus41 = c*d;
    }
    else if(oprt3==3)
    {
        kasus41 = c/d;
    }
    double kasus44;
    if(oprt2==0)
    {
        kasus44 = b+kasus41;
    }
    else if(oprt2==1)
    {
        kasus44 = b-kasus41;
    }
    else if(oprt2==2)
    {
        kasus44 = b*kasus41;
    }
    else if(oprt2==3)
    {
        kasus44 = b/kasus41;
    }
    double kasus43;
    if(oprt1==0)
    {
        kasus43 = a+kasus44;
    }
    else if(oprt1==1)
    {
        kasus43 = a-kasus44;
    }
    else if(oprt1==2)
    {
        kasus43 = a*kasus44;
    }
    else if(oprt1==3)
    {
        kasus43 = a/kasus44;
    }
    kasus4 = kasus43;//Hasil akhir kasus 4
    //------------------------------------
    //Kasus 5 (a..b)..(c..d)
    //------------------------------------
    double kasus5;
    double kasus51;
    if(oprt1==0)
    {
        kasus51 = a+b;
    }
    else if(oprt1==1)
    {
        kasus51 = a-b;
    }
    else if(oprt1==2)
    {
        kasus51 = a*b;
    }
    else if(oprt1==3)
    {
        kasus51 = a/b;
    }
    double kasus52;
    if(oprt3 == 0)
    {
        kasus52 = c+d;
    }
    else if(oprt3==1)
    {
        kasus52 = c-d;
    }
    else if(oprt3==2)
    {
        kasus52 = c*d;
    }
    else if(oprt3==3)
    {
        kasus52 = c/d;
    }
    double kasus53;
    if(oprt2 == 0)
    {
        kasus53 = kasus51+kasus52;
    }
    else if(oprt2 == 1)
    {
        kasus53 = kasus51-kasus52;
    }
    else if(oprt2 == 2)
    {
        kasus53 = kasus51*kasus52;
    }
    else if(oprt2 == 3)
    {
        kasus53 = kasus51/kasus52;
    }
    kasus5 = kasus53;

    //Print hasil
    if(!simpan){
        if(isSama(kasus1))
        {
            cout<<"(("<<a<<oper1<<b<<")"<<oper2<<c<<")"<<oper3<<d<<"="<<kasus1<<endl;//Kasus 1
            *jmloprs+=1;
        }
        if(isSama(kasus2))
        {
            cout<<"("<<a<<oper1<<"("<<b<<oper2<<c<<"))"<<oper3<<d<<"="<<kasus2<<endl;//Kasus 2
            *jmloprs+=1;
        }
        if(isSama(kasus3))
        {
            cout<<a<<oper1<<"(("<<b<<oper2<<c<<")"<<oper3<<d<<")="<<kasus3<<endl;//Kasus 3
            *jmloprs+=1;
        }
        if(isSama(kasus4))
        {
            cout<<a<<oper1<<"("<<b<<oper2<<"("<<c<<oper3<<d<<"))="<<kasus4<<endl;//Kasus 4
            *jmloprs+=1;
        }
        if(isSama(kasus5))
        {
            cout<<"("<<a<<oper1<<b<<")"<<oper2<<"("<<c<<oper3<<d<<")="<<kasus5<<endl;//Kasus 5
            *jmloprs+=1;
        }
    }
    else if(simpan)
    {
        if(isSama(kasus1))
        {
            *datafile<<"(("<<a<<oper1<<b<<")"<<oper2<<c<<")"<<oper3<<d<<"="<<kasus1<<endl;//Kasus 1
        }
        if(isSama(kasus2))
        {
            *datafile<<"("<<a<<oper1<<"("<<b<<oper2<<c<<"))"<<oper3<<d<<"="<<kasus2<<endl;//Kasus 2
        }
        if(isSama(kasus3))
        {
            *datafile<<a<<oper1<<"(("<<b<<oper2<<c<<")"<<oper3<<d<<")="<<kasus3<<endl;//Kasus 3
        }
        if(isSama(kasus4))
        {
            *datafile<<a<<oper1<<"("<<b<<oper2<<"("<<c<<oper3<<d<<"))="<<kasus4<<endl;//Kasus 4
        }
        if(isSama(kasus5))
        {
            *datafile<<"("<<a<<oper1<<b<<")"<<oper2<<"("<<c<<oper3<<d<<")="<<kasus5<<endl;//Kasus 5
        }
    }
}



int main()
{
    cout<<"--------------------------------"<<endl;
    cout<<"Selamat Datang di Game 24 Solver"<<endl;
    cout<<"--------------------------------"<<endl;
    char cari[15];
    int i;
    int count=0;
    int a[4];//buat menyimpan angka
    cout<<"Pilih 4 angka atau huruf diantara angka berikut:"<<endl;
    cout<<"A(dalam game ini bernilai 1)"<<endl<<"Angka 2 - 10"<<endl<<"Q(dalam game ini bernilai 11)"<<endl<<"J(dalam game ini bernilai 12)"<<endl<<"K(dalam game ini bernilai 13)"<<endl;
    cout<<"Masukkan 4 jenis kartu: ";
    cin.getline(cari,15);
    bool benar = true;
    int panjang = strlen(cari);
    for(i=0;i<panjang;i++)
    {
        if(cari[i]=='A')
        {
            a[count] = 1;
            count+=1;
        }
        else if (cari[i]=='2')
        {
            a[count] = 2;
            count+=1;
        }
        else if (cari[i]=='3')
        {
            a[count] = 3;
            count+=1;
        }
        else if (cari[i]=='4')
        {
            a[count] = 4;
            count+=1;
        }
        else if (cari[i]=='5')
        {
            a[count] = 5;
            count+=1;
        }
        else if (cari[i]=='6')
        {
            a[count] = 6;
            count+=1;
        }
        else if (cari[i]=='7')
        {
            a[count] = 7;
            count+=1;
        }
        else if (cari[i]=='8')
        {
            a[count] = 8;
            count+=1;
        }
        else if (cari[i]=='9')
        {
            a[count] = 9;
            count+=1;
        }
        else if (cari[i]=='1' && cari[i+1]=='0')
        {
            a[count] = 10;
            count+=1;
        }
        else if (cari[i]=='0' && cari[i-1]=='1')
        {
            continue;
        }
        else if (cari[i]=='J')
        {
            a[count] = 11;
            count+=1;
        }
        else if( cari[i]=='Q')
        {
            a[count] = 12;
            count+=1;
        }
        else if(cari[i]=='K')
        {
            a[count] = 13;
            count+=1;
        }
        else if(cari[i]==' ' && cari[i-1]!=' ' && cari[i+1]!=' ' )
        {
            continue;
        }
        else if(cari[i]==' ' && cari[i-1]==' ' || cari[i+1]==' ' )
        {
            benar = false;
        }
        else
        {
            benar = false;
        }
    }
    if(benar && count==4 && panjang==7 || panjang==8)
    {
        ofstream buang;
        clock_t start, end;
        start=clock();
        int jml=0;
        int x;
        int y;
        int z;
        int j;
        int k;
        int l;
        int m;
        for (j=0;j<4;j++)
        {
            for (k=0;k<4;k++)
            {
                for (l=0;l<4;l++)
                {
                    for (m=0;m<4;m++)
                    {
                        for (x=0;x<4;x++)
                        {
                            for (y=0;y<4;y++)
                            {
                                for (z=0;z<4;z++)
                                {
                                    if(j!=k && j!=l && j!=m && k!=l && k!=m && l!=m)
                                    {
                                        hitung_hitung(a[j],x,a[k],y,a[l],z,a[m],false,&jml,&buang);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        buang.close();
        cout<<"Jumlah solusi="<<jml<<endl;
        end = clock();
        double waktu = double(end-start)/double(CLOCKS_PER_SEC);
        cout<<"Time execution="<<fixed<<waktu<<" sec"<<endl;
        cout<<"Apakah anda ingin memasukkan solusi ke dalam file?(y/n)=";
        char nanya;
        cin>>nanya;
        if(nanya=='y')
        {
            cout<<"Masukkan nama file untuk menyimpan solusi(.txt)="<<endl;
            string namafile;
            cin>>namafile;
            ofstream simpanfile(namafile);
            simpanfile<<"Kartu yang dipilih sebagai berikut:"<<endl;
            simpanfile<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
            simpanfile<<"Berikut "<<jml<<" solusi yang tersedia:"<<endl;
            for (j=0;j<4;j++)
            {
            for (k=0;k<4;k++)
            {
                for (l=0;l<4;l++)
                {
                    for (m=0;m<4;m++)
                    {
                        for (x=0;x<4;x++)
                        {
                            for (y=0;y<4;y++)
                            {
                                for (z=0;z<4;z++)
                                {
                                    if(j!=k && j!=l && j!=m && k!=l && k!=m && l!=m)
                                    {
                                        hitung_hitung(a[j],x,a[k],y,a[l],z,a[m],true,&jml,&simpanfile);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            }
            simpanfile.close();
            cout<<"File berhasil disimpan. Game telah berakhir";
        }
        else if(nanya=='n')
        {
            cout<<endl<<"Oke, hasil solusi tidak disimpan. Game telah berakhir";
        }
    }
    else
    {
        cout<<"Input tidak benar. Game tidak dapat diselesaikan";
    }
}