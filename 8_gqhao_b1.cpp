#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>
using namespace std;

class STUDENT
{
private:
    char msv[10];
    char fullName[30];
    char sex[5];

public:
    STUDENT()
    {
        strcpy(this->msv, " ");
        strcpy(this->fullName, " ");
        strcpy(this->sex, " ");
    }
    STUDENT(char *a, char *b, char *c)
    {
        strcpy(this->msv, a);
        strcpy(this->fullName, b);
        strcpy(this->sex, c);
    }
    ~STUDENT()
    {
        // delete this->msv;
        // delete this->fullName;
        // delete this->sex;
    }
    friend istream &operator>>(istream &is, STUDENT &x);
    friend ostream &operator<<(ostream &os, STUDENT &x);

    char *getGioiTinh()
    {
        return sex;
    }
    char *getFullName()
    {
        return fullName;
    }
};

istream &operator>>(istream &is, STUDENT &x)
{
    cout << "Ma sinh vien: ";
    fflush(stdin);
    is.getline(x.msv, 10);
    cout << "Ho ten sinh vien: ";
    is.getline(x.fullName, 30);
    cout << "Gioi tinh: ";
    is.getline(x.sex, 5);
}

ostream &operator<<(ostream &os, STUDENT &x)
{
    os << "MSV: " << x.msv << endl;
    os << "HO TEN: " << x.fullName << endl;
    os << "GIOI TINH: " << x.sex << endl;
}

class MONHOC
{
private:
    char maMon[10];
    char tenMon[20];

public:
    MONHOC()
    {
        strcpy(this->maMon, " ");
        strcpy(this->tenMon, " ");
    }

    MONHOC(char *x, char *y)
    {
        strcpy(this->maMon, x);
        strcpy(this->tenMon, y);
    }
    ~MONHOC()
    {
        // delete this->maMon;
        // delete this->tenMon;
    }
    friend istream &operator>>(istream &is, MONHOC &t);
    friend ostream &operator<<(ostream &os, MONHOC &t);
    char *getSubject()
    {
        return tenMon;
    }
};

istream &operator>>(istream &is, MONHOC &t)
{
    cout << "Ma Mon Hoc: ";
    is.getline(t.maMon, 10);
    cout << "Ten Mon: ";
    is.getline(t.tenMon, 20);
}

ostream &operator<<(ostream &os, MONHOC &t)
{
    os << "MA MON: " << t.maMon << endl;
    os << "TEN MON: " << t.tenMon << endl;
}

class DIEMMONHOC : public STUDENT, public MONHOC
{
private:
    float DIEMMH;

public:
    DIEMMONHOC() : STUDENT(), MONHOC()
    {
        this->DIEMMH = 0;
    }
    ~DIEMMONHOC() {}
    friend istream &operator>>(istream &is, DIEMMONHOC &t);
    friend ostream &operator<<(ostream &os, DIEMMONHOC &t);
    friend void ShowListMen(DIEMMONHOC a[], int n);
    friend float TinhDiemTB(DIEMMONHOC a[], int n);
    friend void FindStudent(DIEMMONHOC a[], int n);
    friend void FindSubject(DIEMMONHOC a[], int n);
    friend void SortSubject(DIEMMONHOC a[], int n);
};

istream &operator>>(istream &is, DIEMMONHOC &t)
{
    is >> (STUDENT &)t;
    is >> (MONHOC &)t;
    cout << "Diem Mon Hoc: ";
    is >> t.DIEMMH;
}

ostream &operator<<(ostream &os, DIEMMONHOC &t)
{
    os << (STUDENT &)t;
    os << (MONHOC &)t;
    os << "DIEM MON HOC: " << t.DIEMMH << endl;
}

void ShowListMen(DIEMMONHOC a[], int n)
{
    cout << "DANH SACH HOC SINH GIOI TINH NAM: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcmpi(a[i].getGioiTinh(), "nam") == 0)
        {
            cout << a[i];
        }
    }
}

float TinhDiemTB(DIEMMONHOC a[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].DIEMMH;
    }
    return (sum / n);
}

void FindStudent(DIEMMONHOC a[], int n)
{
    char temp[30];
    cout << "Nhap ten hoc sinh can tim: ";
    cin.ignore();
    cin.getline(temp, 30);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].getFullName(), temp) == 0)
        {
            cout << "Hoc sinh can tim: " << a[i].getFullName() << endl;
            cout << "DIEM MON HOC: " << a[i].DIEMMH << endl;
        }
        // else
        // {
        //     cout << "KHONG TIM THAY HOC SNH CAN TIM" << endl;
        // }
    }
}

void FindSubject(DIEMMONHOC a[], int n)
{
    float min = 0;
    float temp = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmpi(a[i].getSubject(), "Toan") == 0)
        {
            min = a[i].DIEMMH;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (strcmpi(a[i].getSubject(), "Toan") == 0)
        {
            if (a[i].DIEMMH < min)
            {
                min = a[i].DIEMMH;
            }
        }
    }
    cout << "DIEM MH Toan Thap Nhat: " << min << endl;
    cout << "Thong tin hoc sinh co diem Toan thap nhat: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].DIEMMH == min)
        {
            cout << a[i] << endl;
        }
    }
}

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void SortSubject(DIEMMONHOC a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].DIEMMH < a[j].DIEMMH)
            {
                swap(a[i], a[j]);
            }
        }
    }
    cout << "DANH SACH DIEM MH THEO CHIEU GIAM DAN CUA DIEM THI" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Full Name: " << a[i].getFullName() << endl;
        cout << "Subject: " << a[i].getSubject() << endl;
        cout << "DIEM MH: " << a[i].DIEMMH << endl;
    }
}

int main()
{
    int n, select;
    cout << "NHAP SO LUONG DOI TUONG: ";
    cin >> n;
    DIEMMONHOC *a;
    a = new DIEMMONHOC[n];

    cout << "NHAP DANH SACH DOI TUONG DIEM MON HOC: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "STUDENT " << i + 1 << ": " << endl;
        cin >> a[i];
    }

    cout << "IN DANH SACH DOI TUONG MON HOC: " << endl;
    cout << "=================================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "DOI TUONG HOC SINH THU " << i + 1 << ": " << endl;
        cout << a[i];
    }
    cout << "=================================" << endl;

    cout << "=================================" << endl;
    cout << "=============MENU================" << endl;
    cout << "1. LIET KE HOC SINH GIOI TINH NAM" << endl;
    cout << "2. TINH DIEM TB CAC MON HOC " << endl;
    cout << "3. TIM DOI TUONG DIEM MON HOC" << endl;
    cout << "4. THONG TIN DIEM MON TOAN NHO NHAT" << endl;
    cout << "5. SAP XEP DIEM MH THEO CHIEU GIAM DAN" << endl;
    cout << "=================================" << endl;

    do
    {
        cout << "Vui long nhap lua chon: ";
        cin >> select;
        switch (select)
        {
        case 1:
            ShowListMen(a, n);
            break;
        case 2:
            cout << "DIEM TB CAC MON HOC: " << TinhDiemTB(a, n) << endl;
            break;
        case 3:
            FindStudent(a, n);
            break;
        case 4:
            FindSubject(a, n);
            break;
        case 5:
            SortSubject(a, n);
            break;
        default:
            break;
        }

    } while (select != 0);

    return 0;
}