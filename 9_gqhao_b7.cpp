#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

class BenhNhan
{
private:
    char MaHoSo[10];
    char HoTen[30];
    int NgaySinh;
    char ChuanDoanBenh[10];

public:
    int getNgaySinh()
    {
        return NgaySinh;
    }
    virtual void Nhap();
    virtual void Xuat();
    virtual int LoaiBenhNhan() = 0;
};

void BenhNhan::Nhap()
{
    cout << "Ma Ho So: ";
    fflush(stdin);
    cin.getline(this->MaHoSo, 10);
    cout << "Ho va Ten: ";
    fflush(stdin);
    cin.getline(this->HoTen, 30);
    cout << "Ngay Sinh: ";
    cin >> this->NgaySinh;
    cout << "Chuan Doan Benh: ";
    fflush(stdin);
    cin.getline(this->ChuanDoanBenh, 10);
}

void BenhNhan::Xuat()
{
    cout << setfill(' ')
         << "| " << setw(9) << left << this->MaHoSo
         << "| " << setw(18) << left << this->HoTen
         << "| " << setw(10) << left << this->NgaySinh
         << "| " << setw(15) << left << this->ChuanDoanBenh << " |";
}

class BenhNhanNoiTru : public BenhNhan
{
private:
    int NgayNhapVien;
    int NgayRaVien;
    char TenKhoa[10];
    int SoGiuong;

public:
    void Nhap();
    void Xuat();
    int LoaiBenhNhan()
    {
        return 0;
    }
};

void BenhNhanNoiTru::Nhap()
{
    BenhNhan::Nhap();
    cout << "Ngay Nhap Vien: ";
    cin >> this->NgayNhapVien;
    cout << "Ngay Ra Vien: ";
    cin >> this->NgayRaVien;
    cout << "Ten Khoa: ";
    fflush(stdin);
    cin.getline(this->TenKhoa, 10);
    cout << "So Giuong: ";
    cin >> this->SoGiuong;
}

void BenhNhanNoiTru::Xuat()
{
    BenhNhan::Xuat();
    cout << " " << setw(15) << left << this->NgayNhapVien
         << "| " << setw(13) << left << this->NgayRaVien
         << "| " << setw(9) << left << this->TenKhoa
         << "| " << setw(9) << left << this->SoGiuong << " |";
}

class BenhNhanNgoaiTru : public BenhNhan
{
private:
    int NgayChuyen;
    char NoiChuyen[10];

public:
    void Nhap();
    void Xuat();
    int LoaiBenhNhan()
    {
        return 1;
    }
};

void BenhNhanNgoaiTru::Nhap()
{
    BenhNhan::Nhap();
    cout << "Ngay Chuyen: ";
    cin >> this->NgayChuyen;
    cout << "Noi Chuyen: ";
    fflush(stdin);
    cin.getline(this->NoiChuyen, 10);
}

void BenhNhanNgoaiTru::Xuat()
{
    BenhNhan::Xuat();
    cout << " " << setw(12) << left << this->NgayChuyen
         << "| " << setw(10) << left << this->NoiChuyen << " |";
}

void Endline(int x)
{
    cout << "\n+" << setw(x) << right << setfill('-') << "+\n";
}

void titleNoiTru()
{
    cout << "+" << setw(117) << right << setfill('-') << "+\n";
    cout << setfill(' ')
         << setw(11) << left << "| Ma Ho So"
         << setw(20) << left << "|     Ho va Ten"
         << setw(12) << left << "| Ngay Sinh"
         << setw(18) << left << "| Chuan Doan Benh"
         << setw(17) << left << "| Ngay Nhap Vien"
         << setw(15) << left << "| Ngay Ra Vien"
         << setw(11) << left << "| Ten Khoa"
         << setw(11) << left << "| So Giuong"
         << " |\n";
    cout << "+" << setw(117) << right << setfill('-') << "+\n";
}

void titleNgoaiTru()
{
    cout << "+" << setw(89) << right << setfill('-') << "+\n";
    cout << setfill(' ')
         << setw(11) << left << "| Ma Ho So"
         << setw(20) << left << "|     Ho va Ten"
         << setw(12) << left << "| Ngay Sinh"
         << setw(18) << left << "| Chuan Doan Benh"
         << setw(14) << left << "| Ngay Chuyen"
         << setw(12) << left << "| Noi Chuyen"
         << " |\n";
    cout << "+" << setw(89) << right << setfill('-') << "+\n";
}

int main()
{
    //
    int n;
    cout << "Nhap So Luong Benh Nhan: ";
    cin >> n;
    BenhNhan *a[n];
    int choice;
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "\nDanh Sach Cac Benh Nhan. \n";
            cout << "1. Benh Nhan Noi Tru. \n";
            cout << "2. Benh Nhan Ngoai Tru. \n";
            cout << "Nhap Benh Nhan thu " << i + 1 << ": ";
            cin >> choice;
            if (choice != 1 && choice != 2)
            {
                cout << "\nNhap Sai, Vui Long Nhap lai 1 hoac 2. \n";
            }
        } while (choice != 1 && choice != 2);
        if (choice == 1)
        {
            a[i] = new BenhNhanNoiTru;
        }
        else
        {
            a[i] = new BenhNhanNgoaiTru;
        }
        a[i]->Nhap();
    }
    //
    cout << "\nDanh Sach Benh Nhan \"Noi Tru\": \n";
    titleNoiTru();
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiBenhNhan() == 0)
        {
            a[i]->Xuat();
            Endline(117);
        }
    }
    //
    cout << "\nDanh Sach Benh Nhan \"Ngoai Tru\": \n";
    titleNgoaiTru();
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiBenhNhan() == 1)
        {
            a[i]->Xuat();
            Endline(89);
        }
    }
    //
    int X;
    cout << "\nTim cac Ho So co Ngay Sinh lon hon Ngay Sinh X. \n";
    cout << "Nhap X: ";
    cin >> X;
    cout << "\nBenh Nhan \"Noi Tru\" bao gom: \n";
    titleNoiTru();
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiBenhNhan() == 0)
        {
            if (a[i]->getNgaySinh() > X)
            {
                a[i]->Xuat();
                Endline(117);
            }
        }
    }
    cout << "\nBenh Nhan \"Ngoai Tru\" bao gom: \n";
    titleNgoaiTru();
    for (int i = 0; i < n; i++)
    {
        if (a[i]->LoaiBenhNhan() == 1)
        {
            if (a[i]->getNgaySinh() > X)
            {
                a[i]->Xuat();
                Endline(89);
            }
        }
    }
    return 0;
}
