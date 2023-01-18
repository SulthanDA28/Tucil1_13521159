#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char cari[15];
    int i;
    int count=0;
    int a[4];
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
        else if(cari[i]==' ')
        {
            continue;
        }
        else
        {
            benar = false;
        }
    }
    if(benar && count==4)
    {
        for(i=0;i<4;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        cout<<"Input tidak benar";
    }
}