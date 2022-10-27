#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class sp
{
private:
    char msp[10];
    char tenSp[20];
    struct namSx
    {
        int date;
        int month;
        int year;
    } ns;

public:
    void inPut();
    void outPut();
};

void sp::inPut()
{
    cout << "Ma sp: ";
    cin.ignore();
    cin.getline(msp, 10);
    cout << "Ten sp: ";
    cin.getline(tenSp, 20);
    cout << "Nam sx: ";
    cin >> ns.year;
}

void sp::outPut()
{
    cout << "Ma sp: " << msp << endl;
    cout << "Ten sp: " << tenSp << endl;
    cout << "Nam sx: " << ns.year << endl;
}

class Tivi : public sp
{
private:
    float cd, cr;

public:
    void nhap();
    void xuat();
    float DT();
    friend void sort(Tivi a[], int n);
};

void Tivi::nhap()
{
    inPut();
    cout << "Chieu dai tivi: ";
    cin >> cd;
    cout << "Chieu rong tivi: ";
    cin >> cr;
}

void Tivi::xuat()
{
    outPut();
    cout << "Chieu dai tivi: " << cd << endl;
    cout << "Chieu rong tivi: " << cr << endl;
}

float Tivi::DT()
{
    return cd * cr;
}

void sort(Tivi a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        a[i].DT();
        for (int j = i + 1; j < n; j++)
        {
            a[j].DT();
            if (a[i].DT() > a[j].DT())
            {
                swap(a[i], a[j]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "So luong TiVi: ";
    cin >> n;
    Tivi *a;
    a = new Tivi[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Tivi thu " << i + 1 << ": " << endl;
        a[i].nhap();
    }

    sort(a, n);
    cout << "DIEN TICH TIVI SAU KHI SAP XEP:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Tivi 1: " << endl;
        a[i].xuat();
    }

    return 0;
}