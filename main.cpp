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
struct DiemDanh{
    char maNhanVien[3];
    char ngayDiemDanh[10];
    char trangThaiDiLam[4];
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

void diemDanh(DiemDanh &d){
    int n;
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::app );
    fflush(stdin);
    printf("\nNhap ma nhan vien: ");  gets(d.maNhanVien); fflush(stdin);
    DSDD<<"\n";
    DSDD<<d.maNhanVien;
    printf("\nNhap so ngay diem danh: ");
    scanf("%d",&n);
    for(int i = 0; i< n; ++i){
        fflush(stdin);
        printf("\nNhap ngay diem danh: ");  gets(d.ngayDiemDanh); fflush(stdin);
        printf("\nNhap trang thai di lam: ");  gets(d.trangThaiDiLam);
        DSDD<<"," ;
        DSDD<<d.ngayDiemDanh;
        DSDD<<"," ;
        DSDD<<d.trangThaiDiLam;
    }
    DSDD.close();
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
    printf("\n= 3-Nhap thong tin diem danh            =");
    printf("\n=========================================");
    printf("\nChon chuc nang (1-2-3)");
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
        printf("\n\n 4-Tro ve");
        printf("\n 5-Thoat ");
        printf("\nChon chuc nang (4-5): ");
        scanf("%d",&a);
        switch(a){
        case 4: luaChon();
        case 5: exit(0);
        }
    }
    case 2:
    {
        fflush(stdin);
        tim();
        int a;
        printf("\n\n 4-Tro ve");
        printf("\n 5-Thoat ");
        printf("\nChon chuc nang (4-5): ");
        scanf("%d",&a);
        switch(a){
        case 4: luaChon();
        case 5: exit(0);

        }}
    case 3:
    {   int n;
        printf("\nSo luong nhan vien can nhap: ");
        scanf("%d",&n);
        DiemDanh d[n];
        for(int i = 0; i< n; ++i){
            printf("\nNhap nhan vien thu %d:", i+1);
            diemDanh(d[i]);
        }
        int a;
        printf("\n\n 4-Tro ve");
        printf("\n 5-Thoat ");
        printf("\nChon chuc nang (4-5): ");
        scanf("%d",&a);
        switch(a){
        case 4: luaChon();
        case 5: exit(0);
        }
    }
    }

}
int main()
{
    luaChon();
}
