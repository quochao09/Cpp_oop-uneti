#include <iostream>
#include <conio.h>
using namespace std;

class PhanSo
{
private:
    int t, m;

public:
    // >Khoi tao ngam dinh
    PhanSo()
    {
        t = 1;
        m = 1;
    }
    ~PhanSo(){};
    void inPut();
    void outPut();

    int BCNN(int x, int y)
    {
        int tich = x * y;
        while (x != y)
        {
            if (x > y)
            {
                x = x - y;
            }
            else
            {
                y = y - x;
            }
        }
        int bcnn;
        return bcnn = tich / x;
    }
    void tong(PhanSo ps1, PhanSo ps2)
    {
        int bcnn = BCNN(ps1.getM(), ps2.getM());
        cout << (ps1.getT() * (bcnn / ps1.getM())) + (ps2.getT() * (bcnn / ps2.getM())) << "/" << bcnn << endl;
        // return (ps1.getT() * (bcnn / ps1.getM())) + (ps2.getT() * (bcnn / ps2.getM())) / bcnn;
    }
    void hieu(PhanSo ps1, PhanSo ps2)
    {
        int bcnn = BCNN(ps1.getM(), ps2.getM());
        cout << (ps1.getT() * (bcnn / ps1.getM())) - (ps2.getT() * (bcnn / ps2.getM())) << "/" << bcnn << endl;
    };
    float tich(PhanSo ps1, PhanSo ps2);
    float thuong(PhanSo ps1, PhanSo ps2);
    int getT()
    {
        return t;
    }
    int getM()
    {
        return m;
    }
};

void PhanSo::inPut()
{
    do
    {
        cout << "Tu so t: ";
        cin >> t;
        cout << "Mau so m: ";
        cin >> m;
    } while (m == 0);
}

void PhanSo::outPut()
{
    cout << "Phan so sau khi nhap: " << t << "/" << m << endl;
}

float PhanSo::tich(PhanSo ps1, PhanSo ps2)
{
    return (float)(ps1.getT() * ps2.getT()) / (ps1.getM() * ps2.getM());
}

float PhanSo::thuong(PhanSo ps1, PhanSo ps2)
{
    return (float)(ps1.getT() * ps2.getM()) / (ps1.getM() * ps2.getT());
}

int main()
{
    PhanSo ps;
    PhanSo ps1;
    PhanSo ps2;
    cout << "Nhap phan so thu 1: ";
    ps1.inPut();
    ps1.outPut();
    cout << "Nhap phan so thu 2: ";
    ps2.inPut();
    ps2.outPut();
    // Tong 2 phan so
    cout << "Tong 2 phan so: ";
    ps.tong(ps1, ps2);
    // Hieu 2 phan so
    cout << "Hieu 2 phan so: ";
    ps.hieu(ps1, ps2);
    // TIch 2 phan so
    cout << "Tich 2 phan so: " << ps.tich(ps1, ps2) << endl;
    // Thuong 2 phan so
    cout << "Thuong 2 phan so: " << ps.thuong(ps1, ps2);
    return 0;
}