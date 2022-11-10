#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

class DichVu
{
public:
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual long int GiaDV() = 0;
    virtual int LoaiDV() = 0;
};

class GiatLa : public DichVu
{
private:
    int SoKG;
    long int DonGia;
    long int TienThem;
    long int ThanhTien;

public:
    void Nhap();
    void Xuat();
    long int GiaDV();
    int LoaiDV()
    {
        return 1;
    }
};

void GiatLa::Nhap()
{
    cout << "Don Gia: ";
    cin >> this->DonGia;
    cout << "So KG: ";
    cin >> this->SoKG;
    cout << "Tien Dich Vu Them: ";
    cin >> this->TienThem;
}

void GiatLa::Xuat()
{
    cout << "\t\t     " << setfill(' ')
         << "| " << setw(6) << left << this->SoKG
         << "| " << setw(8) << left << this->DonGia
         << "| " << setw(18) << left << this->TienThem
         << "| " << setw(13) << left << this->ThanhTien << " |";
}

long int GiatLa::GiaDV()
{
    this->ThanhTien = this->DonGia * this->SoKG + this->TienThem;
    if (this->SoKG > 5)
    {
        this->ThanhTien = this->ThanhTien * 95 / 100;
    }
    return (this->ThanhTien);
}

class ThueXe : public DichVu
{
private:
    int SoGio;
    long int DonGia;
    long int ThanhTien;

public:
    void Nhap();
    void Xuat();
    long int GiaDV();
    int LoaiDV()
    {
        return 2;
    }
};

void ThueXe::Nhap()
{
    cout << "So Gio Thue: ";
    cin >> this->SoGio;
    cout << "Don Gia: ";
    cin >> this->DonGia;
}

void ThueXe::Xuat()
{
    cout << "\t\t     " << setfill(' ')
         << "| " << setw(9) << left << this->SoGio
         << "| " << setw(18) << left << this->DonGia
         << "| " << setw(20) << left << this->ThanhTien << " |";
}

long int ThueXe::GiaDV()
{
    this->ThanhTien = this->DonGia * this->SoGio;
    if (this->SoGio > 10)
    {
        this->ThanhTien = this->ThanhTien * 90 / 100;
    }
    return (this->ThanhTien);
}

class HoaDon
{
private:
    DichVu *DV[50];
    char MaHoaDon[10];
    char MaKhachHang[10];
    char TenKhachHang[30];
    int SoDV;
    int choice;
    long int s1, s2;

public:
    void Nhap();
    void Xuat();
    int getSoDV()
    {
        return (this->SoDV);
    }
    long int TongThanhTien()
    {
        long int temp = 0;
        temp = temp + (this->s1) + (this->s2);
        return temp;
    }
    long int getTienGiat()
    {
        return s1;
    }
    long int getTienXe()
    {
        return s2;
    }
    void titleHD(int x);
    void titleGiatLa();
    void titleThueXe();
    friend void Endline(int x);
};

void HoaDon::Nhap()
{
    cout << "Ma Hoa Don: ";
    fflush(stdin);
    cin.getline(this->MaHoaDon, 10);
    cout << "Ma Khach Hang: ";
    fflush(stdin);
    cin.getline(this->MaKhachHang, 10);
    cout << "Ten Khach Hang: ";
    fflush(stdin);
    cin.getline(this->TenKhachHang, 10);
    this->SoDV = 0;
    do
    {
        cout << "\nDanh Sach Cac Dich Vu. \n";
        cout << "1. Dich Vu Giat La. \n";
        cout << "2. Dich Vu Thue Xe. \n";
        cout << "0. Ket Thuc Hoa Don. \n";
        cout << "Nhap Dich Vu thu " << SoDV + 1 << ": ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            DV[SoDV] = new GiatLa;
            DV[SoDV]->Nhap();
            s1 = s1 + DV[SoDV]->GiaDV();
            SoDV++;
            break;
        case 2:
            DV[SoDV] = new ThueXe;
            DV[SoDV]->Nhap();
            s2 = s2 + DV[SoDV]->GiaDV();
            SoDV++;
            break;
        case 0:
            return;
            break;
        default:
            cout << "\nNhap Sai, Vui Long Nhap lai tu 0 -> 2. \n";
            break;
        }
    } while (1);
}

void HoaDon::Xuat()
{
    cout << "\t" << setfill(' ')
         << "| " << setw(11) << left << this->MaHoaDon
         << "| " << setw(14) << left << this->MaKhachHang
         << "| " << setw(15) << left << this->TenKhachHang
         << "| " << setw(19) << left << this->SoDV
         << "| " << setw(18) << left << this->TongThanhTien() << " |";
    cout << "\n\t+" << setw(89) << right << setfill('-') << "+\n";
}

void HoaDon::titleHD(int x)
{
    HoaDon::Xuat();
    cout << "\n\t\t\t\tDanh Sach Su Dung Dich Vu Giat La:";
    titleGiatLa();
    for (int i = 0; i < SoDV; i++)
    {
        if (DV[i]->LoaiDV() == 1)
        {
            DV[i]->Xuat();
            Endline(55);
        }
    }
    cout << "\n\t\t     ---Tong Tien Dich Vu Giat La = " << this->getTienGiat() << endl;

    cout << "\n\t\t\t\tDanh Sach Su Dung Dich Vu Thue Xe:";
    titleThueXe();
    for (int i = 0; i < SoDV; i++)
    {
        if (DV[i]->LoaiDV() == 2)
        {
            DV[i]->Xuat();
            Endline(55);
        }
    }
    cout << "\n\t\t     ---Tong Tien Dich Vu Thue Xe = " << this->getTienXe() << endl;
}

void HoaDon::titleGiatLa()
{
    cout << "\n\t\t     +" << setw(55) << right << setfill('-') << "+\n";
    cout << "\t\t     " << setfill(' ')
         << setw(8) << left << "| So KG"
         << setw(10) << left << "| Don Gia"
         << setw(20) << left << "| Tien Dich Vu Them"
         << setw(15) << left << "|  Thanh Tien"
         << " |\n";
    cout << "\t\t     +" << setw(55) << right << setfill('-') << "+\n";
}

void HoaDon::titleThueXe()
{
    cout << "\n\t\t     +" << setw(55) << right << setfill('-') << "+\n";
    cout << "\t\t     " << setfill(' ')
         << setw(11) << left << "|  So Gio"
         << setw(20) << left << "|      Don Gia"
         << setw(22) << left << "|      Thanh Tien"
         << " |\n";
    cout << "\t\t     +" << setw(55) << right << setfill('-') << "+\n";
}

void Endline(int x)
{
    cout << "\n\t\t     +" << setw(x) << right << setfill('-') << "+\n";
}

void title(int x)
{
    cout << "\n-" << setw(51) << right << setfill('-') << "- Hoa Don thu " << x + 1 << " -" << setw(51) << right << "-\n";
    cout << "\n\t+" << setw(89) << right << setfill('-') << "+\n";
    cout << "\t" << setfill(' ')
         << setw(13) << left << "| Ma Hoa Don"
         << setw(16) << left << "| Ma Khach Hang"
         << setw(17) << left << "| Ten Khach Hang"
         << setw(21) << left << "| So Dich Vu Su Dung"
         << setw(20) << left << "| Tong Tien Phai Tra"
         << " |\n";
    cout << "\t+" << setw(89) << right << setfill('-') << "+\n";
}

void endtitle()
{
    cout << "\n-" << setw(105) << right << setfill('-') << "-\n";
}

int main()
{
    //
    int n;
    HoaDon *HD;
    HD = new HoaDon[n];
    cout << "Nhap So Luong Hoa Don: ";
    cin >> n;
    //
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap Thong Tin Hoa Don thu " << i + 1 << endl;
        HD[i].Nhap();
    }
    //
    cout << "\nB )--Danh Sach cac Hoa Don:";
    for (int i = 0; i < n; i++)
    {
        title(i);
        HD[i].titleHD(i);
        endtitle();
    }
    //
    long int Tong = 0;
    for (int i = 0; i < n; i++)
    {
        Tong = Tong + HD[i].TongThanhTien();
    }
    cout << "\n\nC )--Tong Tien Khach San nhan duoc la: " << Tong << "\n\n";
    //
    cout << "\nD )--Thong Tin Hoa Don co Dich Vu Giat lon hon 10tr bao gom: \n";
    for (int i = 0; i < n; i++)
    {
        if (HD[i].getTienGiat() > 10000000)
        {
            title(i);
            HD[i].titleHD(i);
            endtitle();
        }
    }
    return 0;
}
