#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <Import.h>

using namespace std;

struct DiemDanh{
    char maNhanVien[3];
    char ngayDiemDanh[10];
    char trangThaiDiLam[4];
};

struct NhanVien{
    char maNhanVien[3];
    char hoTen[50];
    char ngayThangNamSinh[10];
    char diaChi[50];
    char bpct[30];
    void read(ifstream &);
    void write(ofstream &);
};

void tim(){
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::in);
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::in);
    string ma;
    cout << "Nhap ma nhan vien can tim: ";
    getline(cin, ma);
    int i=0;
    int j=0;
    DiemDanh d;
    NhanVien nv;
    while (!DSNV.eof())
    {
        char temp[255];
        DSNV.getline(temp, 255);
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
    cout<<"Thong tin diem danh:"<<endl;
    while (!DSDD.eof())
    {
        char temp[255];
        DSDD.getline(temp, 255);
        char *line = temp;
        char *mnv,*ndd,*ttdl;
        mnv=strtok(line,",");

        if(mnv==ma){
            ndd=strtok(NULL,",");
            cout<<"Ngay:"<<ndd<<": ";
            ttdl=strtok(NULL,",");
            cout<<ttdl<<endl;
            j=1;

        }

    }
    if(i==0){cout <<"Khong tim thay nhan vien" ;}
    if(j==0){cout <<"Khong co thong tin diem danh" ;}
}
void diemDanh(DiemDanh &d){
    int n;
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::app );

    fflush(stdin);
    printf("\nNhap ma nhan vien: ");  gets(d.maNhanVien); fflush(stdin);
    DSDD<<d.maNhanVien;
    fflush(stdin);
    printf("\nNhap ngay diem danh: ");  gets(d.ngayDiemDanh); fflush(stdin);
    printf("\nNhap trang thai di lam: ");  gets(d.trangThaiDiLam);
    DSDD<<"," ;
    DSDD<<d.ngayDiemDanh;
    DSDD<<"," ;
    DSDD<<d.trangThaiDiLam;
    DSDD<<"\n";

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
void NhanVien::read(ifstream &in){
    char lines[500];
    fflush(stdin);
    in.getline(lines,500);

    string str = lines;
    vector<string> v = Import::split (str, ',');


}
void importCSV(){
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::app);
    //    vector<NhanVien*> list;
    // phần này chỉ lấy ra số dòng trong file csv và xuống khỏi dòng đầu tiên
    ifstream ifs("ImportData.csv", ios::in);
    int n;
    string abc;
    n=Import::numberLine(); // lấy ra số dòng
    n=n-1;
    cout<<n<<endl;
    ifs >> abc;
    char ss[5];
    ifs.getline(ss, 3);// loai bo xuong dong

    while (!ifs.eof())
    {
        char temp[255];
        ifs.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");
        DSNV<<"\n";
        DSNV<<mnv;
        ht=strtok(NULL,",");
        DSNV<<"," ;
        DSNV<<ht;
        ntns=strtok(NULL,",");
        DSNV<<"," ;
        DSNV<<ntns;
        dc=strtok(NULL,",");
        DSNV<<"," ;
        DSNV<<dc;
        bpct=strtok(NULL,",");
        DSNV<<"," ;
        DSNV<<bpct;

  }
     DSNV.close();

}
void luaChon() {
    int t;
    printf("\n=========================================");
    printf("\n= 1-Nhap thong tin nhan vien            =");
    printf("\n= 2-Tim thong tin nhan vien             =");
    printf("\n= 3-Import tu file csv                  =");
    printf("\n= 4-Nhap thong tin diem danh            =");
    printf("\n=========================================");
    printf("\nChon chuc nang (1-2-3-4)");
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
        printf("\n\n 5-Tro ve");
        printf("\n 6-Thoat ");
        printf("\nChon chuc nang (5-6): ");
        scanf("%d",&a);
        switch(a){
        case 5: luaChon();
        case 6: exit(0);
        }
    }
    case 2:
    {
        fflush(stdin);
        tim();
        int a;
        printf("\n\n 5-Tro ve");
        printf("\n 6-Thoat ");
        printf("\nChon chuc nang (5-6): ");
        scanf("%d",&a);
        switch(a){
        case 5: luaChon();
        case 6: exit(0);
        }}
    case 3:
    {   importCSV();
        int a;
        printf("\n\n 5-Tro ve");
        printf("\n 6-Thoat ");
        printf("\nChon chuc nang (5-6): ");
        scanf("%d",&a);
        switch(a){
        case 5: luaChon();
        case 6: exit(0);
        }
    }
    case 4:
    {   int n;
        printf("\nSo luong nhan vien can nhap: ");
        scanf("%d",&n);
        DiemDanh d[n];
        for(int i = 0; i< n; ++i){
            printf("\nNhap nhan vien thu %d:", i+1);
            diemDanh(d[i]);
        }
        int a;
        printf("\n\n 5-Tro ve");
        printf("\n 6-Thoat ");
        printf("\nChon chuc nang (5-6): ");
        scanf("%d",&a);
        switch(a){
        case 5: luaChon();
        case 6: exit(0);
        }
    }
    }

}
int main()
{

    luaChon();
}
