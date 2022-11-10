#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

class Sach
{
protected:
    char MaSach[10];
    float DonGia;
    int SoLuong;
    char NhaXuatBan[20];

public:
    float getDonGia()
    {
        return DonGia;
    }
    char *getNhaXB()
    {
        return NhaXuatBan;
    }
    virtual void Nhap();
    virtual void Xuat();
    virtual float ThanhTien() = 0;
    virtual int LoaiSach() = 0;
};

void Sach::Nhap()
{
    cout << "Ma Sach: ";
    fflush(stdin);
    cin.getline(this->MaSach, 10);
    cout << "Don Gia: ";
    cin >> this->DonGia;
    cout << "So Luong: ";
    cin >> this->SoLuong;
    cout << "Nha Xuat Ban: ";
    fflush(stdin);
    cin.getline(this->NhaXuatBan, 20);
}

void Sach::Xuat()
{
    cout << setfill(' ')
         << "| " << setw(10) << left << this->MaSach
         << "| " << setw(8) << left << this->DonGia
         << "| " << setw(9) << left << this->SoLuong
         << "| " << setw(12) << left << this->NhaXuatBan << " |";
}

class SachGiaoKhoa : public Sach
{
private:
    char TinhTrang[5];

public:
    void Nhap();
    void Xuat();
    float ThanhTien();
    int LoaiSach()
    {
        return 0;
    }
};

void SachGiaoKhoa::Nhap()
{
    Sach::Nhap();
    do
    {
        cout << "Nhap Tinh Trang: ";
        fflush(stdin);
        cin.getline(this->TinhTrang, 5);
        if (strcmp(this->TinhTrang, "Moi") != 0 && strcmp(this->TinhTrang, "Cu") != 0)
        {
            cout << "Vui Long Nhap lai Tinh Trang \"Moi\" hoac \"Cu\". \n";
        }
    } while (strcmp(this->TinhTrang, "Moi") != 0 && strcmp(this->TinhTrang, "Cu") != 0);
}

void SachGiaoKhoa::Xuat()
{
    Sach::Xuat();
    cout << " " << setw(16) << left << this->TinhTrang
         << "| " << setw(10) << left << this->ThanhTien() << " |";
}

float SachGiaoKhoa::ThanhTien()
{
    if (strcmp(this->TinhTrang, "Moi") == 0)
    {
        return (this->SoLuong * this->DonGia);
    }
    else if (strcmp(this->TinhTrang, "Cu") == 0)
    {
        return (this->SoLuong * this->DonGia * 50 / 100);
    }
}

class SachThamKhao : public Sach
{
private:
    float Thue;

public:
    void Nhap();
    void Xuat();
    float ThanhTien();
    int LoaiSach()
    {
        return 1;
    }
};

void SachThamKhao::Nhap()
{
    Sach::Nhap();
    cout << "Thue: ";
    cin >> this->Thue;
}

void SachThamKhao::Xuat()
{
    Sach::Xuat();
    cout << " " << setw(16) << left << this->Thue
         << "| " << setw(10) << left << this->ThanhTien() << " |";
}

float SachThamKhao::ThanhTien()
{
    return (this->DonGia * this->SoLuong + this->Thue);
}

void Endline(int x)
{
    cout << "\n+" << setw(x) << right << setfill('-') << "+\n";
}

void title()
{
    cout << "+" << setw(80) << right << setfill('-') << "+\n";
    cout << setfill(' ')
         << setw(12) << left << "|  Ma Sach"
         << setw(10) << left << "| Don Gia"
         << setw(11) << left << "| So Luong"
         << setw(15) << left << "| Nha Xuat Ban"
         << setw(18) << left << "| Tinh Trang/Thue"
         << setw(12) << left << "| Thanh Tien"
         << " |\n";
    cout << "+" << setw(80) << right << setfill('-') << "+\n";
}

int main()
{
    int n;
    cout << "Nhap So Luong Sach: ";
    cin >> n;
    Sach *a[n];
    int choice;
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "\nDanh Sach Cac Loai Sach. \n";
            cout << "1. Sach Giao Khoa. \n";
            cout << "2. Sach Tham Khao. \n";
            cout << "Nhap Loai Sach thu " << i + 1 << ": ";
            cin >> choice;
            if (choice != 1 && choice != 2)
            {
                cout << "\nNhap Sai, Vui Long Nhap lai 1 hoac 2. \n";
            }
        } while (choice != 1 && choice != 2);
        if (choice == 1)
        {
            a[i] = new SachGiaoKhoa;
        }
        else
        {
            a[i] = new SachThamKhao;
        }
        a[i]->Nhap();
    }
    cout << "\nDanh Sach Cac Loai Sach: \n";
    title();
    for (int i = 0; i < n; i++)
    {
        a[i]->Xuat();
        Endline(80);
    }
    float SGK = 0, STK = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiSach() == 0)
        {
            SGK += a[i]->ThanhTien();
        }
        else if (a[i]->LoaiSach() == 1)
        {
            STK += a[i]->ThanhTien();
        }
    }
    cout << "\nTong Thanh Tien cua Sach Giao Khoa = " << SGK;
    cout << "\nTong Thanh Tien cua Sach Tham Khao = " << STK << endl;
    float TongDGSTK = 0, DemSTK = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiSach() == 1)
        {
            TongDGSTK += a[i]->getDonGia();
            DemSTK++;
        }
    }
    cout << "Trung Binh Cong Don Gia cua Sach Tham Khao = " << TongDGSTK / DemSTK << endl;
    char X[20];
    cout << "\nTim Sach Giao Khoa cua Nha Xuat Ban X. \n";
    cout << "Nhap Nha Xuat Ban X: ";
    fflush(stdin);
    cin.getline(X, 20);
    cout << "\nDanh Sach cac Sach Giao Khoa cua Nha Xuat Ban \"" << X << "\" la: \n";
    title();
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiSach() == 0)
        {
            if (strcmp(a[i]->getNhaXB(), X) == 0)
            {
                a[i]->Xuat();
                Endline(80);
            }
        }
    }
    return 0;
}