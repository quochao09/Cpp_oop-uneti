#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct student
{
    char ma[7];
    char hoten[30];
    char address[30];
    float sum;
};
typedef struct student hs;

void Chuan_Hoa_Name(char a[])
{
    int n = strlen(a);
    // Xóa khoảng trắng đầu chuỗi
    while (a[0] == ' ')
    {
        if (a[0] == ' ')
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = a[i + 1];
            }
        }
    }
    // Xóa khoảng trắng cuối chuỗi
    while (a[n - 1] == ' ')
    {
        if (a[n - 1] == ' ')
        {
            a[n - 1] = '\0';
        }
    }
    // Xóa khoảng trắng ở giữa
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == ' ')
        {
            if (a[i + 1] == ' ')
            {
                for (int j = i; j < n; j++)
                {
                    a[j] = a[j + 1];
                }
                i--;
            }
        }
        i++;
    }
    strlwr(a);
    a[0] = toupper(a[0]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ' ')
        {
            a[i + 1] = toupper(a[i + 1]);
        }
    }
    // cout << "Name chuan hoa: " << a << endl;
}

void inPut(hs a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ma hoc sinh thu " << i + 1 << " : ";
        cin.ignore();
        cin.getline(a[i].ma, 7);
        cout << "Ho ten hoc sinh thu " << i + 1 << " : ";
        cin.getline(a[i].hoten, 30);
        Chuan_Hoa_Name(a[i].hoten);
        cout << "Que quan: ";
        cin.getline(a[i].address, 30);
        Chuan_Hoa_Name(a[i].address);
        cout << "Tong diem: ";
        cin >> a[i].sum;
    }
}

void diemGiamDan(hs a[], int n)
{
    cout << "=========================DANH SACH HOC SINH DIEM GIAM DAN=========================" << endl;
    cout << "==================================================================================" << endl;
    cout << setw(8) << "MA HS";
    cout << setw(15) << "HO TEN";
    cout << setw(15) << "QUE QUAN";
    cout << setw(15) << "TONG DIEM" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].sum < a[j].sum)
            {
                swap(a[i].sum, a[i].sum);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << setw(7) << a[i].ma;
        cout << setw(15) << a[i].hoten;
        cout << setw(15) << a[i].address;
        cout << setw(15) << a[i].sum << endl;
    }
    cout << "==================================================================================" << endl;
}

void namDinh(hs a[], int n)
{
    cout << "=========================DANH SACH HOC SINH QUE NAM DINH==========================" << endl;
    cout << "==================================================================================" << endl;
    cout << setw(8) << "MA HS";
    cout << setw(15) << "HO TEN";
    cout << setw(15) << "QUE QUAN";
    cout << setw(15) << "TONG DIEM" << endl;
    char nd[15] = "Nam Dinh";
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].address, nd) == 0)
        {
            cout << setw(7) << a[i].ma;
            cout << setw(15) << a[i].hoten;
            cout << setw(15) << a[i].address;
            cout << setw(15) << a[i].sum << endl;
        }
    }
    cout << "==================================================================================" << endl;
}

int main()
{
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    hs a[n];
    inPut(a, n);
    diemGiamDan(a, n);
    namDinh(a, n);
    return 0;
}