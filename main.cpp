#include <stdio.h>
#include <list>
#include <iterator>
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
void timTheoTen(){

    fstream DSNV;
    DSNV.open("DSNV.txt",ios::in);
    string ten;
    cout << "Nhap ten nhan vien can tim: ";
    getline(cin, ten);
    int i=0;
    cout <<"KET QUA TIM KIEM NHAN VIEN CO TEN "<<ten<< " :"<<endl;
    while (!DSNV.eof())
    {
        char temp[255];
        DSNV.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");
        ht=strtok(NULL,",");
        if(ht==ten){
            cout<<endl;
            cout<<"NHAN VIEN THU "<<i+1<<" :"<<endl;
            cout<<"Ma nhan vien:"<<mnv<<endl;
            cout<<"Ho ten:"<<ht<<endl;
            ntns=strtok(NULL,",");
            cout<<"Ngay thang nam sinh:"<<ntns<<endl;
            dc=strtok(NULL,",");
            cout<<"Dia chi:"<<dc<<endl;
            bpct=strtok(NULL,",");
            cout<<"Bo phan cong tac:"<<bpct<<endl;
            i=i+1;

        }

    }
    if(i==0){cout <<"Khong tim thay nhan vien" ;}
}

void tim(){
    // mo 2 file danh sach nhan vien va danh sach diem danh
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::in);
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::in);
    string ma;
    cout << "Nhap ma nhan vien can tim: ";
    getline(cin, ma);
    int i=0;
    int j=0;
    //duyet 2 file den khi nao tim duoc ma trung voi ma nhan vien trong ca 2 file thi xuat thong tin tren cac dong tuong ung
    while (!DSNV.eof())
    {
        char temp[255];
        DSNV.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");    // strtok: tach chuoi ky tu den dau ","

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
    //luu thong tin diem danh vao file dsdd.txt
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

void importCSV(){
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::app);
    int a=0;
    ifstream ifs("ImportData.csv", ios::in);
    // duyet file csv, lay ra tung dong, tach thong tin trong tung dong ra de luu vao file txt
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
        a++;
    }
    DSNV.close();
    if(a==0){
        cout<<"file trong hoac bi loi"<<endl;
    } else { cout<<"Import thanh cong !"<<endl; }
}
string month(char *date){
    char *ngay, *thang;
    ngay=strtok(date,"/");
    thang=strtok(NULL,"/");
    return thang;
}
void xemTheoNhanVien(string thang){

    fstream DSNV;
    DSNV.open("DSNV.txt",ios::in);
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::in);
    string ma;
    fflush(stdin);
    cout << "Nhap ma nhan vien can xem: ";
    getline(cin, ma);
    cout<<"Thong tin diem danh cua ma nhan vien "<<ma<<" trong thang "<<thang<<" :"<<endl;
    while (!DSNV.eof())
    {
        char temp[255];
        DSNV.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");
        if (mnv==ma){
            ht=strtok(NULL,",");
            cout<<"Ho ten:"<<ht<<endl;
        }
    }
    while (!DSDD.eof())
    {
        char temp2[255],date[255];
        DSDD.getline(temp2, 255);
        char *line2 = temp2;
        char *mnv2,*ndd,*day,*ttdl;
        mnv2=strtok(line2,",");
        ndd=strtok(NULL,",");
        ttdl=strtok(NULL,",");
        strcpy(date,ndd);
        if(month(date)==thang && mnv2==ma){
            cout<<ndd<<" : "<<ttdl<<endl;

        }
    }
}

bool exist(vector<string> ds, string a){
    for (int i = 0; i < ds.size(); i++)
        if (a==ds[i]){
            return true;
        }
    return false;
}
void xemTheoBoPhan(string thang){
    vector<string> dsma;
    vector<string> dsten;
    vector<string> dsdd;
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::in);
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::in);
    string bp;
    fflush(stdin);
    cout << "Nhap bo phan can xem: ";
    getline(cin, bp);
    cout<<"Thong tin diem danh cua bo phan "<<bp<<" trong thang "<<thang<<" :"<<endl;
    while (!DSNV.eof())
    {
        char temp[255],ht2[255], ma[255];
        DSNV.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");
        strcpy(ma,mnv);
        ht=strtok(NULL,",");
        strcpy(ht2,ht);
        ntns=strtok(NULL,",");
        dc=strtok(NULL,",");
        bpct=strtok(NULL,",");
        if(bpct==bp){
            dsma.push_back(ma);
            dsten.push_back(ht2);
        }
    }
    while (!DSDD.eof())
    {
        char temp2[255],date[255],ma2[255];
        DSDD.getline(temp2, 255);
        char *line2 = temp2;
        char *mnv2,*ndd,*day,*ttdl;
        mnv2=strtok(line2,",");
        strcpy(ma2,mnv2);

        ndd=strtok(NULL,",");
        ttdl=strtok(NULL,",");
        strcpy(date,ndd);
        if(month(date)==thang){
            dsdd.push_back(ma2);
            dsdd.push_back(ndd);
            dsdd.push_back(ttdl);

        }
    }

    for (int i = 0; i < dsma.size(); i++){
        cout<<i+1<<". "<<dsten[i]<<endl;
        if(exist(dsdd,dsma[i])){
            for (int j = 0; j < dsdd.size(); j++){
                if (dsdd[j]== dsma[i]){
                    cout<<dsdd[j+1]<<" : "<<dsdd[j+2]<<endl;
                }}

        } else {cout<<"Khong co thong tin diem danh cua nhan vien nay"<<endl;}
    }

}
void xemTatCa(string thang){
    vector<string> dsma;
    vector<string> dsten;
    vector<string> dsdd;
    fstream DSNV;
    DSNV.open("DSNV.txt",ios::in);
    fstream DSDD;
    DSDD.open("DSDD.txt",ios::in);
    cout<<"Thong tin diem danh : "<<endl;
    while (!DSNV.eof())
    {
        char temp[255],ht2[255], ma[255];
        DSNV.getline(temp, 255);
        char *line = temp;
        char *mnv,*ht,*ntns,*dc,*bpct;
        mnv=strtok(line,",");
        strcpy(ma,mnv);
        ht=strtok(NULL,",");
        strcpy(ht2,ht);
        ntns=strtok(NULL,",");
        dc=strtok(NULL,",");
        bpct=strtok(NULL,",");
        dsma.push_back(ma);
        dsten.push_back(ht2);
    }
    while (!DSDD.eof())
    {
        char temp2[255],date[255],ma2[255];
        DSDD.getline(temp2, 255);
        char *line2 = temp2;
        char *mnv2,*ndd,*day,*ttdl;
        mnv2=strtok(line2,",");
        strcpy(ma2,mnv2);
        ndd=strtok(NULL,",");
        ttdl=strtok(NULL,",");
        strcpy(date,ndd);
        if(month(date)==thang){
            dsdd.push_back(ma2);
            dsdd.push_back(ndd);
            dsdd.push_back(ttdl);

        }
    }
    std::ofstream xemTatCa;
    xemTatCa.open ("xemTatCa.csv", ios::app);
    for (int i = 0; i < dsma.size(); i++){
        cout<<i+1<<". "<<dsten[i]<<endl;
        if(exist(dsdd,dsma[i])){
            for (int j = 0; j < dsdd.size(); j++){
                if (dsdd[j]== dsma[i]){
                    cout<<dsdd[j+1]<<" : "<<dsdd[j+2]<<endl;
                    xemTatCa << dsma[i]+dsdd[j+1]+dsdd[j+2] ;
                }
            }

        } else {cout<<"Khong co thong tin diem danh cua nhan vien nay"<<endl;}
    }
    xemTatCa.close();
}
void luaChon() {
    int t;
    printf("\n=========================================");
    printf("\n= 1-Nhap thong tin nhan vien            =");
    printf("\n= 2-Tim thong tin nhan vien             =");
    printf("\n= 3-Import tu file csv                  =");
    printf("\n= 4-Nhap thong tin diem danh            =");
    printf("\n= 5-Tim thong tin theo ten              =");
    printf("\n= 6-Xem lich su diem danh               =");
    printf("\n=========================================");
    printf("\nChon chuc nang (1-2-3-4-5-6): ");
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
        printf("\n\n 8-Tro ve");
        printf("\n 9-Thoat ");
        printf("\nChon chuc nang (8-9): ");
        scanf("%d",&a);
        switch(a){
        case 8: luaChon();
        case 9: exit(0);
        }
    }
    case 2:
    {
        fflush(stdin);
        tim();
        int a;
        printf("\n\n 8-Tro ve");
        printf("\n 9-Thoat ");
        printf("\nChon chuc nang (8-9): ");
        scanf("%d",&a);
        switch(a){
        case 8: luaChon();
        case 9: exit(0);
        }}
    case 3:
    {   importCSV();
        int a;
        printf("\n\n 8-Tro ve");
        printf("\n 9-Thoat ");
        printf("\nChon chuc nang (8-9): ");
        scanf("%d",&a);
        switch(a){
        case 8: luaChon();
        case 9: exit(0);
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
        printf("\n\n 8-Tro ve");
        printf("\n 9-Thoat ");
        printf("\nChon chuc nang (8-9): ");
        scanf("%d",&a);
        switch(a){
        case 8: luaChon();
        case 9: exit(0);
        }
    }
    case 5:
    {
        fflush(stdin);
        timTheoTen();
        int a;
        printf("\n\n 8-Tro ve");
        printf("\n 9-Thoat ");
        printf("\nChon chuc nang (8-9): ");
        scanf("%d",&a);
        switch(a){
        case 8: luaChon();
        case 9: exit(0);
        }}
    case 6:
    {
        fflush(stdin);
        string thang;
        cout << "Nhap thang can xem: "<<endl;
        getline(cin, thang);
        fflush(stdin);
        int e;
        cout<<"*--------------------------*"<<endl;
        cout<<"*  10-Xem theo nhan vien   *"<<endl;
        cout<<"*  11-Xem theo bo phan     *"<<endl;
        cout<<"*  12-Xem tat ca           *"<<endl;
        cout<<"*--------------------------*"<<endl;
        cout<<"Nhap chuc nang muon xem (10-11-12): "<<endl;
        scanf("%d",&e);
        switch(e){
        case 10: xemTheoNhanVien(thang);
            break;
        case 11: xemTheoBoPhan(thang);
            break;
        case 12: xemTatCa(thang);
            break;
        }
        int a;
        fflush(stdin);
        printf("\n\n 8-Tro ve");
        printf("\n 9-Thoat ");
        printf("\nChon chuc nang (8-9): ");
        scanf("%d",&a);
        switch(a){
        case 8: luaChon();
        case 9: exit(0);
        }}
    }

}
int main()
{

    luaChon();
}
