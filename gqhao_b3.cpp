//Bài 3: Để quản lý hàng hóa, mỗi một mặt hàng được lưu trữ các thông tin: mã hàng (char[8]), tên hàng (char[30]), số lượng (int), đơn giá (float), thành tiền (float). 
//Hãy lập chương trình thực hiện các yêu cầu sau:
//-  Khai báo kiểu dữ liệu cấu trúc lưu trữ thông tin cho một mặt hàng
//-  Nhập vào từ bàn phím một danh sách n mặt hàng (không nhập trường Thành tiền).
//-  Viết hàm tính thành tiền cho các mặt hàng biết
//-  Thành tiền = số lượng * đơn giá
//-  Hiển thị thông tin những mặt hàng có đơn giá lớn hơn 50.

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct inFormation
{
    char maHang[8];
    char tenHang[30];
    int soLuong;
    float donGia;
    float monNey;
};
typedef inFormation tt;

void inPut(tt a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ma hang thu " << i + 1 << " : ";
        cin.ignore();
        cin.getline(a[i].maHang, 8);
        cout << "Ten hang thu " << i + 1 << " : ";
        cin.getline(a[i].tenHang, 30);
        cout << "So luong: ";
        cin >> a[i].soLuong;
        cout << "Don gia: ";
        cin >> a[i].donGia;
    }
}

float thanhTIen(tt a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].monNey = a[i].soLuong * a[i].donGia;
    }
}

void outPut(tt a[], int n)
{
    cout << "=================Thon tin mat hang co don gia > 50=================" << endl;
    cout << "===================================================================" << endl;
    cout << setw(8) << "MA HANG";
    cout << setw(15) << "TEN HANG";
    cout << setw(15) << "SO LUONG";
    cout << setw(15) << "DON GIA";
    cout << setw(15) << "THANH TIEN" << endl;
    for (int i = 0; i < n; i++)
    {
        thanhTIen(a, n);
        if (a[i].donGia > 50)
        {
            cout << setw(7) << a[i].maHang;
            cout << setw(14) << a[i].tenHang;
            cout << setw(14) << a[i].soLuong;
            cout << setw(14) << a[i].donGia;
            cout << setw(14) << a[i].monNey << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong hang: ";
    cin >> n;
    tt a[n];
    inPut(a, n);
    outPut(a, n);
    return 0;
}
