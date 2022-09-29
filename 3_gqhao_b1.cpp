#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class DaThuc3
{
private:
    int a, b, c, d;

public:
    // Ham khoi tao khong tham so
    DaThuc3()
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
    // Ham khoi tao co tham so
    DaThuc3(int x)
    {
        a = x;
        b = x;
        c = x;
        d = x;
    }
    DaThuc3(int x, int y)
    {
        a = x;
        b = y;
        c = y;
        d = y;
    }
    DaThuc3(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
        d = y;
    }
    DaThuc3(int x, int y, int z, int t)
    {
        a = x;
        b = y;
        c = z;
        d = t;
    }
    ~DaThuc3(){};
    // Ham sao chep;
    DaThuc3(const DaThuc3 &dt)
    {
        this->a = dt.a;
        this->b = dt.b;
        this->c = dt.c;
        this->d = dt.d;
    }

    void inPut();
    void outPut();

    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int getC()
    {
        return c;
    }
    int getD()
    {
        return d;
    }
};

void DaThuc3::inPut()
{
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;
    cout << "Nhap he so d: ";
    cin >> d;
}

void DaThuc3::outPut()
{
    cout << "Da Thuc sau khi nhap: " << endl;
    cout << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << endl;
}

int main()
{

    DaThuc3 dt1;
    DaThuc3 dt2;

    cout << "Nhap Da Thuc 1: " << endl;
    dt1.inPut();
    dt1.outPut();
    DaThuc3 dt = dt1;
    cout << "Sao chep dt1:" << endl;
    dt.outPut();
    cout << "Nhap Da Thuc 2: " << endl;
    dt2.inPut();
    dt2.outPut();
    cout << "Da Thuc sau khi cong: ";
    cout << dt1.getA() + dt2.getA() << "x^3 + " << dt1.getB() + dt2.getB() << "x^2 + " << dt1.getC() + dt2.getC() << "x + " << dt1.getD() + dt2.getD() << endl;
    return 0;
}