#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class client
{
private:
    char fullName[30];
    struct ngaySinh
    {
        int date;
        int month;
        int year;
    };
    struct ngaySinh NS;
    char cmnd[10];
    char hoKhau[50];

public:
    void inPut();
    void outPut();
    int month12();
    bool sx(client a)
    {
        if (strcmpi(this->fullName, a.fullName) > 0)
        {
            return true;
        }
    }
};

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

void client ::inPut()
{
    cin.ignore();
    cout << "Ho ten: ";
    cin.getline(fullName, 30);
    Chuan_Hoa_Name(fullName);
    cout << "Ngay sinh: ";
    cin >> NS.date;
    cout << "Thang sinh: ";
    cin >> NS.month;
    cout << "Nam sinh: ";
    cin >> NS.year;
    cout << "So CMND: ";
    cin.ignore();
    cin.getline(cmnd, 10);
    cout << "So ho khau: ";
    // cin.ignore();
    cin.getline(hoKhau, 50);
}

void client ::outPut()
{
    // cout << setw(10) << "HO TEN" << setw(15) << "NGAY SINH" << setw(15) << "CMND" << setw(15) << "SHK" << endl;
    cout << setw(8) << fullName;
    cout << setw(13) << NS.date << "/" << NS.month << "/" << NS.year;
    cout << setw(13) << cmnd;
    cout << setw(13) << hoKhau << endl;

    // cout << "Ho ten: " << fullName << endl;
    // cout << "Ngay sinh: " << NS.date << "/" << NS.month << "/" << NS.year << endl;
    // cout << "CMND: " << cmnd << endl;
    // cout << "So ho khau: " << hoKhau << endl;
}

int client ::month12()
{
    if (NS.month == 12)
    {
        return true;
    }
}

int main()
{
    client *a;
    int n;
    cout << "So khach hang: ";
    cin >> n;
    a = new client[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin khach hang thu " << i + 1 << ": " << endl;
        a[i].inPut();
    }
    // cout << setw(10) << "HO TEN" << setw(15) << "NGAY SINH" << setw(15) << "CMND" << setw(15) << "SHK" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     // cout << "Thong tin khach hang thu " << i + 1 << ": " << endl;
    //     a[i].outPut();
    // }

    cout << "Danh sach khach hang sinh thang 12" << endl;
    cout << setw(10) << "HO TEN" << setw(17) << "NGAY SINH" << setw(17) << "CMND" << setw(15) << "SHK" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].month12() == true)
        {
            a[i].outPut();
        }
    }

    cout << "\nDanh sach khach hang tang dan theo ho ten" << endl;
    cout << setw(10) << "HO TEN" << setw(17) << "NGAY SINH" << setw(17) << "CMND" << setw(15) << "SHK" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].sx(a[j]))
            {
                client temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i].outPut();
    }

    return 0;
}