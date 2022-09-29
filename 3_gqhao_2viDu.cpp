#include <iostream>
#include <cstring>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Student
{
private:
    char ht[30];
    float toan, ly, hoa;

public:
    // Ham ko tham so
    Student()
    {
        strcpy(ht, "");
        toan = 0;
        ly = 0;
        hoa = 0;
    }
    // Ham nhieu tham so
    Student(char *ht, float toan, float ly, float hoa)
    {
        strcpy(this->ht, ht);
        this->toan = toan;
        this->ly = ly;
        this->hoa = hoa;
    }
    // Ham tao sao chep
    Student(const Student &hs)
    {
        // this->ht = hs.ht;
        this->toan = hs.toan;
        this->ly = hs.ly;
        this->hoa = hs.hoa;
    }
    void input()
    {
        fflush(stdin);
        cout << "\nNhsp ho ten";
        cin.getline(ht, 30);
        cout << "\nNhap diem toan";
        cin >> toan;
        cout << "\nNhap diem ly";
        cin >> ly;
        cout << "\nNhap diem hoa";
        cin >> hoa;
    }
    void title()
    {
        cout << setw(20) << "Ho ten ";
        cout << setw(20) << "Diem toan";
        cout << setw(20) << "Diem ly";
        cout << setw(20) << "Diem hoa";
        cout << endl;
    }
    void output()
    {
        cout << setw(20) << ht;
        cout << setw(20) << toan;
        cout << setw(20) << ly;
        cout << setw(20) << hoa;
        cout << endl;
    }
};

int main()
{
    Student *hs;
    int n;

    cout << "\nNhap so luong hs";
    cin >> n;
    hs = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nThong tin hoc sinh thu: " << i + 1 << endl;
        hs[i].input();
    }
    cout << "\nDanh sach hoc sinh vua nhap" << endl;
    hs->title();
    for (int i = 0; i < n; i++)
    {
        hs[i].output();
    }
    Student *hs2(hs);
    for (int i = 0; i < n; i++)
    {
        hs[i].output();
    }
}