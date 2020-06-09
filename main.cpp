#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
using namespace std;

struct NhanVien{
    char maNhanVien[3];
    char hoTen[50];
    char ngayThangNamSinh[10];
    char diaChi[50];
    char bpct[30];
};

void tim(){
        cout << "Nhap ma nhan vien can tim: ";
        string s;
        getline(cin, s);
    fstream file("DSNV.txt",ios::in);


    NhanVien nv;

    while (!file.eof())
    {
        char temp[255];
        file.getline(temp, 255);
        char *line = temp;

        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");

        if(mnv==s){
            cout<<"Ma nhan vien:"<<mnv<<endl;
            ht=strtok(NULL,",");
            cout<<"Ho ten:"<<ht<<endl;
            ntns=strtok(NULL,",");
            cout<<"Ngay thang nam sinh:"<<ntns<<endl;
            dc=strtok(NULL,",");
            cout<<"Dia chi:"<<dc<<endl;
            bpct=strtok(NULL,",");
            cout<<"Bo phan cong tac:"<<bpct<<endl;
            break;
        }
    }
}

void nhap(NhanVien &nv ){
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::app);
    fflush(stdin);
    printf("\nNhap ma nhan vien: ");  gets(nv.maNhanVien); fflush(stdin);
    printf("\nNhap ho va ten nhan vien: ");  gets(nv.hoTen); fflush(stdin);
    printf("\nNhap ngay thang nam sinh: ");  gets(nv.ngayThangNamSinh); fflush(stdin);
    printf("\nNhap dia chi: ");  gets(nv.diaChi); fflush(stdin);
    printf("\nNhap bo phan cong tac: ");  gets(nv.bpct); fflush(stdin);

    DSNV<<"\n";
    DSNV<<nv.maNhanVien;
    DSNV<<"," ;
    DSNV<<nv.hoTen;
    DSNV<<"," ;
    DSNV<<nv.ngayThangNamSinh;
    DSNV<<"," ;
    DSNV<<nv.diaChi;
    DSNV<<"," ;
    DSNV<<nv.bpct;
    DSNV.close();
}

int main()
{
    int t;
    printf("\n=========================================");
    printf("\n= 1-Nhap thong tin nhan vien            =");
    printf("\n= 2-Tim thong tin nhan vien             =");
    printf("\n=========================================");
    printf("\nChon chuc nang (1-2)");
    scanf("%d",&t);
    switch(t)
    { case 1:
    {   int n;
        printf("\nSo luong nhan vien can nhap: ");
        scanf("%d",&n);
        NhanVien a[n];
        for(int i = 0; i< n; ++i){
            printf("\nNhap nhan vien thu %d:", i+1);
            nhap(a[i]);
        }
        break;
    }
    case 2:
    {   tim();
    }

}
}
