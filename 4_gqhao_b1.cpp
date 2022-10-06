#include <iostream>
using namespace std;
// Viet lai cac hàm bằng return
class PhanSo
{
private:
    int t, m;

public:
    PhanSo(int tu = 1, int mau = 1)
    {
        t = tu;
        m = mau;
    }
    ~PhanSo(){};
    PhanSo rutGon();
    void outPut()
    {
        cout << this->t << "/" << this->m << endl;
    }

    friend void inPut(PhanSo &ps);
    friend void tong(PhanSo ps1, PhanSo ps2);
    friend void hieu(PhanSo ps1, PhanSo ps2);
    friend void tich(PhanSo ps1, PhanSo ps2);
    friend void thuong(PhanSo ps1, PhanSo ps2);
    PhanSo sum1();
};

void inPut(PhanSo &ps)
{
    cout << "Tu so: ";
    cin >> ps.t;
    cout << "Mau so: ";
    cin >> ps.m;
}

PhanSo PhanSo::rutGon()
{
    int a, b;
    a = abs(this->t);
    b = abs(this->m);
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    this->t /= a;
    this->m /= a;
    return *this;
}

PhanSo PhanSo::sum1()
{
    PhanSo ps;
    PhanSo ps1;
    PhanSo ps2;
    //...
    ps.t = ps1.t * ps2.m + ps2.t * ps1.m;
    ps.m = ps1.m * ps2.m;
    return ps;
}

void tong(PhanSo ps1, PhanSo ps2)
{
    cout << "Tong 2 Phan So = ";
    cout << (ps1.t * ps2.m + ps2.t * ps1.m) << "/" << (ps1.m * ps2.m) << endl;
}

void hieu(PhanSo ps1, PhanSo ps2)
{
    cout << "Hieu 2 Phan So = ";
    cout << (ps1.t * ps2.m - ps2.t * ps1.m) << "/" << (ps1.m * ps2.m) << endl;
}

void tich(PhanSo ps1, PhanSo ps2)
{
    cout << "Tich 2 Phan So = ";
    cout << (ps1.t * ps2.t) << "/" << (ps1.m * ps2.m) << endl;
}

void thuong(PhanSo ps1, PhanSo ps2)
{
    cout << "Thuong 2 Phan So = ";
    cout << (ps1.t * ps2.m) << "/" << (ps2.t * ps2.m) << endl;
}

int main()
{
    PhanSo ps1;
    PhanSo ps2;

    cout << "Phan so 1: " << endl;
    inPut(ps1);
    ps1.rutGon();
    ps1.outPut();

    cout << "Phan so 2: " << endl;
    inPut(ps2);
    ps2.rutGon();
    ps2.outPut();

    // tong(ps1, ps2);
    // hieu(ps1, ps2);
    // tich(ps1, ps2);
    // thuong(ps1, ps2);

    return 0;
}