#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

class MayIn
{
protected:
    char SoHieu[10];
    int SoLuong;

public:
    MayIn(char *a = "", int b = 0)
    {
        strcpy(this->SoHieu, a);
        this->SoLuong = b;
    }
    ~MayIn() {}
    void nhapkho(int q);
    void xuatkho(int q);
    void Nhap();
    void Xuat();
};

void MayIn::nhapkho(int q)
{
    this->SoLuong += q;
}

void MayIn::xuatkho(int q)
{
    if (this->SoLuong > q)
    {
        this->SoLuong -= q;
    }
    else
    {
        cout << "\nKhong du So Luong de Xuat Kho. \n";
    }
}

void MayIn::Nhap()
{
    cout << "So Hieu: ";
    cin >> this->SoHieu;
    cout << "So Luong: ";
    cin >> this->SoLuong;
}

void MayIn::Xuat()
{
    cout << "May In " << this->SoHieu << " ton " << this->SoLuong << " chiec. \n";
}

class MayInLaser : public virtual MayIn
{
protected:
    int DPI;

public:
    MayInLaser(char *a = "", int b = 0, int c = 0) : MayIn(a, b)
    {
        this->DPI = c;
    }
    void NhapLaser();
    void XuatLaser();
};

void MayInLaser::NhapLaser()
{
    MayIn::Nhap();
    cout << "DPI: ";
    cin >> this->DPI;
}

void MayInLaser::XuatLaser()
{
    cout << "May In Laser " << this->SoHieu << " (" << this->DPI << " DPI) ton " << this->SoLuong << " chiec. \n";
}

class MayInMau : public virtual MayIn
{
protected:
    int BangMau;

public:
    MayInMau(char *a = "", int b = 0, int d = 0) : MayIn(a, b)
    {
        this->BangMau = d;
    }
    void NhapMau();
    void XuatMau();
};

void MayInMau::NhapMau()
{
    if (strcmp(this->SoHieu, "") == 0)
    {
        MayIn::Nhap();
        cout << "Bang Mau: ";
        cin >> this->BangMau;
    }
    else
    {
        cout << "Bang Mau: ";
        cin >> this->BangMau;
    }
}

void MayInMau::XuatMau()
{
    cout << "May In Mau " << this->SoHieu << " (Bang Mau: " << this->BangMau << ") ton " << this->SoLuong << " chiec. \n";
}

class MayInLaserMau : public MayInLaser, public MayInMau
{
public:
    MayInLaserMau(char *a = "", int b = 0, int c = 0, int d = 0) : MayIn(a, b), MayInLaser(a, b, c), MayInMau(a, b, d)
    {
    }
    void NhapLaserMau();
    void XuatLaserMau();
};

void MayInLaserMau::NhapLaserMau()
{
    MayInLaser::NhapLaser();
    MayInMau::NhapMau();
}

void MayInLaserMau::XuatLaserMau()
{
    cout << "May In Laser Mau " << this->SoHieu << " (" << this->DPI << " DPI, Bang Mau: " << this->BangMau << ") ton " << this->SoLuong << " chiec. \n";
}

void clear()
{
    cout << "\n\n";
    system("pause");
    system("cls");
}

int main()
{
    MayIn m1;
    MayInLaser m2;
    MayInMau m3;
    MayInLaserMau m4;

    cout << "Nhap Thong tin Kho ban dau: \n";
    cout << "Nhap Thong tin May In: \n";
    m1.Nhap();
    cout << "Nhap Thong tin May In Laser: \n";
    m2.NhapLaser();
    cout << "Nhap Thong tin May In Mau: \n";
    m3.NhapMau();
    cout << "Nhap Thong tin May In Laser Mau: \n";
    m4.NhapLaserMau();

    int choice1, choice2, n;
    do
    {
        clear();
        cout << "Main Menu: \n";
        cout << "1. Nhap Kho. \n";
        cout << "2. Xuat Kho. \n";
        cout << "3. In So luong cac loai Trong Kho. \n";
        cout << "0. Exit. \n";
        cout << "Nhap Lua Chon cua ban: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            cout << "Nhap So Luong ban Muon Nhap: ";
            cin >> n;
            cout << "Menu: \n";
            cout << "1. May In. \n";
            cout << "2. May In Laser. \n";
            cout << "3. May In Mau. \n";
            cout << "4. May In Laser Mau. \n";
            cout << "0. Exit to main Menu. \n";
            cout << "Nhap Mat Hang ban muon Nhap: ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                m1.nhapkho(n);
                break;
            case 2:
                m2.nhapkho(n);
                break;
            case 3:
                m3.nhapkho(n);
                break;
            case 4:
                m4.nhapkho(n);
                break;
            case 0:
                continue;
            default:
                cout << "Nhap sai, Vui long nhap lai. \n";
                break;
            }
            break;
        case 2:
            cout << "Nhap So Luong ban Muon Xuat: ";
            cin >> n;
            cout << "Menu: \n";
            cout << "1. May In. \n";
            cout << "2. May In Laser. \n";
            cout << "3. May In Mau. \n";
            cout << "4. May In Laser Mau. \n";
            cout << "0. Exit to main Menu. \n";
            cout << "Nhap Mat Hang ban muon Xuat: ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                m1.xuatkho(n);
                break;
            case 2:
                m2.xuatkho(n);
                break;
            case 3:
                m3.xuatkho(n);
                break;
            case 4:
                m4.xuatkho(n);
                break;
            case 0:
                continue;
            default:
                cout << "Nhap sai, Vui long nhap lai. \n";
                break;
            }
            break;
        case 3:
            m1.Xuat();
            m2.XuatLaser();
            m3.XuatMau();
            m4.XuatLaserMau();
            break;
        }
    } while (1);
    return 0;
}
