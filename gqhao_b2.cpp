// Bài 2: Một phân số được biểu diễn dưới dạng   t/m.
// Viết chương trình nhập  vào n phân số (n nguyên dương nhập từ bàn phím) và
// tính tổng các phân số đó.
#include <iostream>
using namespace std;

struct phanSo
{
    float t;
    float m;
};
typedef phanSo ps;

void inPut(ps a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Tu so ps thu " << i + 1 << " : ";
        cin >> a[i].t;
        cout << "Mau so ps thu " << i + 1 << " : ";
        cin >> a[i].m;
    }
}

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

float sumPs(ps a[], int n)
{
    int temp = BCNN(a[0].m, a[1].m);
    for (int i = 2; i < n; i++)
    {
        temp = BCNN(temp, a[i].m);
    }
    float sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + (temp / a[i].m) * (a[i].t);
    }
    return sum1 / temp;
}

int main()
{
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;
    ps a[n];
    inPut(a, n);
    cout << "Tong cac phan so = " << sumPs(a, n);
    return 0;
}