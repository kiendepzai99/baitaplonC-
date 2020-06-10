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
    fstream file;
    file.open("DSNV.txt",ios::in);
    string ma;
    cout << "Nhap ma nhan vien can tim: ";
    getline(cin, ma);
    int i=0;
    NhanVien nv;
    while (!file.eof())
    {
        char temp[255];
        file.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");
        if(mnv==ma){
            cout<<"Ma nhan vien:"<<mnv<<endl;
            ht=strtok(NULL,",");
            cout<<"Ho ten:"<<ht<<endl;
            ntns=strtok(NULL,",");
            cout<<"Ngay thang nam sinh:"<<ntns<<endl;
            dc=strtok(NULL,",");
            cout<<"Dia chi:"<<dc<<endl;
            bpct=strtok(NULL,",");
            cout<<"Bo phan cong tac:"<<bpct<<endl;
            i=1;
            break;
        }

    }
    if(i==0){cout <<"Khong tim thay nhan vien" ;}
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
void luaChon() {
    int t;
    printf("\n=========================================");
    printf("\n= 1-Nhap thong tin nhan vien            =");
    printf("\n= 2-Tim thong tin nhan vien             =");
    printf("\n=========================================");
    printf("\nChon chuc nang (1-2)");
    scanf("%d",&t);
    switch(t)
    {
    case 1:
    {   int n;
        printf("\nSo luong nhan vien can nhap: ");
        scanf("%d",&n);
        NhanVien nv[n];
        for(int i = 0; i< n; ++i){
            printf("\nNhap nhan vien thu %d:", i+1);
            nhap(nv[i]);
        }
        int a;
        printf("\n\n 3-Tro ve");
        printf("\n 4-Thoat ");
        printf("\nChon chuc nang (3-4): ");
        scanf("%d",&a);
        switch(a){
        case 3: luaChon();
        case 4: break;
        }
    }
    case 2:
        fflush(stdin);
        tim();
        int a;
        printf("\n\n 3-Tro ve");
        printf("\n 4-Thoat ");
        printf("\nChon chuc nang (3-4): ");
        scanf("%d",&a);
        switch(a){
        case 3: luaChon();
        case 4: break;
        }
    }

}
int main()
{
    luaChon();
}
