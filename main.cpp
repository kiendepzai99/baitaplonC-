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
string convertToString(char* a)
{   int size = sizeof(a)/ sizeof(char);
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
bool soSanh (char ma[], string s1){

    std::string s(ma);
    if(s1.compare(s)==0)
        return true;


    return false;
}
void tim(char ma[]){

    fstream file("DSNV.txt",ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file,line )) {

            if(soSanh(ma,line)){
                cout << line << endl;

               //in ra thong tin tren 4 dong tiep theo ?
            }
            ;

        }
        file.close();
    }



}

typedef NhanVien NV;
void nhap(NhanVien &nv ){
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::app);

    printf("\nNhap ma nhan vien: ");  gets(nv.maNhanVien); fflush(stdin);
    printf("\nNhap ho va ten nhan vien: ");  gets(nv.hoTen); fflush(stdin);
    printf("\nNhap ngay thang nam sinh: ");  gets(nv.ngayThangNamSinh); fflush(stdin);
    printf("\nNhap dia chi: ");  gets(nv.diaChi); fflush(stdin);
    printf("\nNhap bo phan cong tac: ");  gets(nv.bpct); fflush(stdin);

    DSNV<<nv.maNhanVien;
    DSNV<<"\n" ;
    DSNV<<nv.hoTen;
    DSNV<<"\n" ;
    DSNV<<nv.ngayThangNamSinh;
    DSNV<<"\n" ;
    DSNV<<nv.diaChi;
    DSNV<<"\n" ;
    DSNV<<nv.bpct;
    DSNV<<"\n" ;

    DSNV.close();
}

int main(int argc, char *argv[])
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
        char ma[3];
        printf("\nNhap ma can tim: ");
        scanf("%c",&ma);
        tim(ma);
    }
    return 0;
}
