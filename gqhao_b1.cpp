// Bài 1: Một số phức được biểu diễn dưới dạng  a = phầnthực + phần ảo*j.
// Viết chương trình nhập 2 số phức và in ra màn hình tổng, hiệu 2 số phức đó.
#include <iostream>
using namespace std;

struct soPhuc
{
    float pt;
    float pa;
};
typedef soPhuc sp;

void inPut(sp &a, sp &b)
{
    cout << "Phan thuc so phuc 1: ";
    cin >> a.pt;
    cout << "Phan ao so phuc 1: ";
    cin >> a.pa;
    cout << "Phan thuc so phuc 2: ";
    cin >> b.pt;
    cout << "Phan ao so phuc 2: ";
    cin >> b.pa;
}

void tong(sp &a, sp &b)
{
    cout << "Tong = " << (a.pt + b.pt) << " + " << (a.pa + b.pa) << ".j" << endl;
}

void hieu(sp &a, sp &b)
{
    cout << "Hieu = " << (a.pt - b.pt) << " + " << (a.pa - b.pa) << ".j" << endl;
}

int main()
{
    sp a;
    sp b;
    inPut(a, b);
    tong(a, b);
    hieu(a, b);
    return 0;
}
