#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class GV
{
private:
    char name[30];
    int age;
    char bc[15];
    char chuyenNganh[20];
    float bl;

public:
    void inPut();
    void outPut();
    float luongCb();
};

void GV ::inPut()
{
    cout << "Ho ten GV: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Tuoi GV: ";
    cin >> age;
    cout << "Bang cap: ";
    cin.ignore();
    cin.getline(bc, 15);
    cout << "Chuyen nganh: ";
    cin.getline(chuyenNganh, 20);
    cout << "Bac luong: ";
    cin >> bl;
}

float GV ::luongCb()
{
    float lcb;
    lcb = bl * 610;
    return bl * 610;
}

void GV ::outPut()
{
    // float lcb;
    //  cout << setw(8) << "HO TEN" << setw(15) << "TUOI" << setw(8) << "BANG CAP" << setw(15) << "CHUYEN NGANH" << setw(15) << "BAC LUONG" << endl;
    cout << setw(7) << name << setw(14) << age << setw(14) << bc << setw(14) << chuyenNganh << setw(14) << bl << endl;
}

int main()
{
    int n;
    cout << "So luong GV: ";
    cin >> n;
    GV a[n];

    for (int i = 0; i < n; i++)
    {
        cout << "GV thu " << i + 1 << ": " << endl;
        a[i].inPut();
    }

    cout << "\t\t\tDANH SACH NHAN VIEN CO TIEN LUONG < 2000" << endl;
    cout << setw(8) << "HO TEN" << setw(15) << "TUOI" << setw(15) << "BANG CAP" << setw(15) << "CHUYEN NGANH" << setw(15) << "BAC LUONG" << endl;

    for (int i = 0; i < n; i++)
    {
        if (a[i].luongCb() < 2000)
        {
            a[i].outPut();
        }
    }
    return 0;
}