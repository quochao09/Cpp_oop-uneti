#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

void title()
{
    cout << setw(5) << "HO TEN" << setw(15) << "NAM SINH" << setw(10) << "DIEM TOAN" << setw(10) << "DIEM LY" << setw(10) << "DIEM HOA" << endl;
}

class people
{
private:
    char name[30];
    struct namsinh
    {
        int date;
        int month;
        int year;
    } ns;

public:
    people()
    {
        strcpy(name, " ");
        this->ns.year = 0;
    }
    ~people(){};
    void nhap();
    void xuat();
};

void people::nhap()
{
    cout << "Ho ten: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Nam sinh: ";
    cin >> ns.year;
}

void people::xuat()
{
    cout << "Ho va ten: " << name << endl;
    cout << "Nam sinh: " << ns.year << endl;
    // cout << setw(5) << name << setw(15) << ns.year << setw(10) <<
}

class ThiSinh : public people
{
private:
    char sbd[10];
    float toan, ly, hoa;

public:
    ThiSinh() : people()
    {
        strcpy(sbd, "");
        this->toan = 0;
        this->ly = 0;
        this->hoa = 0;
    }
    void inPut();
    void outPut();
    friend void sort(ThiSinh a[], int n);
    friend void find(ThiSinh a[], int n);
    friend float ThongKe(ThiSinh a[], int n);
};

void ThiSinh::inPut()
{
    nhap();
    cout << "So bao danh: ";
    cin.ignore();
    cin.getline(sbd, 10);
    cout << "Diem toan: ";
    cin >> toan;
    cout << "Diem ly: ";
    cin >> ly;
    cout << "Diem hoa: ";
    cin >> hoa;
}

void ThiSinh::outPut()
{
    xuat();
    cout << "SBD: " << sbd << endl;
    cout << "DIEM TOAN: " << toan << endl;
    cout << "DIEM LY: " << ly << endl;
    cout << "DIEM HOA: " << hoa << endl;
}

void sort(ThiSinh a[], int n)
{
    float sum = 0;
    float sum1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum = a[i].toan + a[i].ly + a[i].hoa;
        for (int j = i + 1; j < n; j++)
        {
            sum1 = a[j].toan + a[j].ly + a[j].hoa;
            if (sum > sum1)
            {
                swap(a[i], a[j]);
            }
            sum1 = 0;
        }
        sum = 0;
    }
}

void find(ThiSinh a[], int n)
{
    int x = 0;
    char temp[10];
    cout << "NHAP SBD THI SINH CAN TIM: ";
    cin.ignore();
    cin.getline(temp, 10);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(temp, a[i].sbd) == 0)
        {
            a[i].outPut();
            x = 1;
        }
        else
        {
            continue;
        }
    }
    if (x == 0)
    {
        cout << "KHONG CO THI SINH CAN TIM !" << endl;
    }
}

float ThongKe(ThiSinh a[], int n)
{
    float result = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].toan >= 5 && a[i].ly >= 5 && a[i].hoa >= 5)
        {
            count++;
        }
    }
    result = ((float)count / n) * 100;
    return result;
}

int main()
{
    int select;
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    ThiSinh *a;
    a = new ThiSinh[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Thi sinh thu " << i + 1 << ": " << endl;
        a[i].inPut();
    }
    do
    {
        cout << "*********************************************************\n";
        cout << "1. SAP XEP DANH SACH THI SINH CO TONG DIEM 3 MON TANG DAN." << endl;
        cout << "2. TIM KIEM THI SINH." << endl;
        cout << "3. THONG KE PHAN TRAM THI SINH DAT YEU CAU." << endl;
        cout << "0. EXIT" << endl;
        cout << "*********************************************************\n";
        cout << "VUI LONG NHAP LUA CHON: ";
        cin >> select;
        switch (select)
        {
        case 1:
            sort(a, n);
            cout << "XUAT DANH SACH TONG DIEM TANG DAN: " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "THI SINH THU " << i + 1 << ": " << endl;
                a[i].outPut();
            }
            break;

        case 2:
            find(a, n);
            break;

        case 3:
            cout << "PHAN TRAM THI SINH DAT YEU CAU: " << ThongKe(a, n) << "%" << endl;
            break;

        default:
            cout << "VUI LONG NHAP LAI LUA CHON !" << endl;
            break;
        }

    } while (select != 0);

    return 0;
}