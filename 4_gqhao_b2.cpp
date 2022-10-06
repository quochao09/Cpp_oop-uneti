#include <iostream>
#include <cstring>
#include <conio.h>
#include <iomanip>
using namespace std;

struct ngay
{
    int date;
    int month;
    int year;
};

class HoaDon
{
private:
    char maVt[10];
    char tenVt[30];
    char loai_Phieu[10];
    struct ngay NL;
    float height;
    float donGia;
    float thanhTien;

public:
    void inPut(HoaDon a[], int n);
    void outPut(HoaDon a[], int n);
    friend float Sum(HoaDon a[], int n);
    friend void Sort(HoaDon a[], int n);
    bool checkMa();
};

void title()
{
    cout << setw(5) << "MA VAT TU" << setw(13) << "TEN VAT TU" << setw(15) << "LOAI PHIEU"
         << setw(10) << "NGAY LAP" << setw(13) << "KHOI LUONG" << setw(10) << "DON GIA" << endl;
}

bool HoaDon::checkMa()
{
    char coppy[10];
    strcpy(coppy, this->maVt);
    int check = strcmp(coppy, this->maVt);
    if (check == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void HoaDon::inPut(HoaDon a[], int n)
{

    cout << "Ma vat tu: ";
    fflush(stdin);
    cin.getline(maVt, 10);
    cout << "Ten vat tu: ";
    cin.getline(tenVt, 30);
    cout << "Loai phieu: ";
    cin.getline(loai_Phieu, 10);
    cout << "Ngay lap: ";
    cin >> NL.date;
    cout << "Khoi luong: ";
    cin >> height;
    cout << "Don gia: ";
    cin >> donGia;
    cout << "Thanh tien: ";
    cin >> thanhTien;
}

void HoaDon::outPut(HoaDon a[], int n)
{
    cout << setw(5) << maVt << setw(13) << tenVt << setw(15) << loai_Phieu << setw(10) << NL.date
         << setw(13) << height << setw(10) << donGia << endl;
}

float Sum(HoaDon a[], int n)
{
    float tong = 0;
    for (int i = 0; i < n; i++)
    {
        // a[i].thanhTien = a[i].donGia * a[i].height;
        tong += a[i].thanhTien;
    }
    return tong;
}

void Sort(HoaDon a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].thanhTien < a[j].thanhTien)
            {
                swap(a[i], a[j]);
            }
        }
    }
    title();
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << a[i].maVt << setw(13) << a[i].tenVt << setw(15) << a[i].loai_Phieu << setw(10) << a[i].NL.date
             << setw(13) << a[i].height << setw(10) << a[i].donGia << endl;
    }
}

int main()
{
    int n;
    cout << "Nhap so luong hoa don: ";
    cin >> n;
    // HoaDon *a;
    // a = new HoaDon[n];
    HoaDon a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].inPut(a, n);
    }
    title();
    for (int i = 0; i < n; i++)
    {
        a[i].outPut(a, n);
    }

    cout << "Tong thanh tien = " << Sum(a, n) << endl;

    cout << "Danh sach sau khi sap xep theo tien giam dan: " << endl;
    Sort(a, n);

    return 0;
}