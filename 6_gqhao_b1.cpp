#include<iostream>
using namespace std;
int ucln(int a, int b){
    if( a<0){
        a = a* (-1);
    }
    if( b<0){
        b = b* (-1);
    }
    while(a != b){
        if( a>b){
            a =a -b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
class phanso{
    int tu, mau;
    public:
    phanso( int a =1, int b =1){
        tu = a;
        mau = b;
    }
    void rutgon(){
        int u;
        u = ucln(tu,mau);
        tu = tu/u;
        mau = mau/u;
    }
    friend istream& operator >>( istream &is , phanso &p){
        cout<<" Nhap tu so: ";
        is>>p.tu;
        cout<<" Nhap mau  so: ";
        is>>p.mau;
    }
    friend ostream& operator <<( ostream &os , phanso &p){
        os<<p.tu<<"/"<<p.mau<<endl;
    }
    friend phanso operator + (phanso a, phanso b){
        phanso t;
        t.tu = a.tu * b.mau + a.mau * b.tu;
        t.mau = a.mau * b.mau;
        t.rutgon();
        return t;
    }
    friend phanso operator - (phanso a, phanso b){
        phanso h;
        h.tu = a.tu * b.mau - a.mau * b.tu;
        h.mau = a.mau * b.mau;
        h.rutgon();
        return h;
    }
    friend phanso operator * (phanso a, phanso b){
        phanso tich;
        tich.tu = a.tu * b.tu;
        tich.mau = a.mau * b.mau;
        tich.rutgon();
        return tich;
    }
    friend phanso operator / (phanso a, phanso b){
        phanso thuong;
        thuong.tu = a.tu * b.mau;
        thuong.mau = a.mau * b.tu;
        thuong.rutgon();
        return thuong;
    }
    friend bool operator <( phanso a, phanso b){
        if( a.tu / a.mau < b.tu / b.mau){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator ==( phanso a, phanso b){
        if( a.tu / a.mau == b.tu / b.mau){
            return true;
        }
        else{
            return false;
        }
    }
    friend float gt( phanso &a);
};
float gt( phanso &a){
    float x;
    x = (float)a.tu/ a.mau;
    return x;
}
int main(){
    phanso p;
    cout<<p;
    phanso a, b;
    cout<<" Nhap phan so thu 1: ";
    cin>>a;
    cout<<" Nhap phan so thu 2: ";
    cin>>b;
    phanso c = a+b;
    cout<<" Tong 2 phan so tren la: ";
    cout<<c;
    phanso d = a-b;
    cout<<" Hieu 2 phan so tren la: ";
    cout<<d;
    phanso e = a*b;
    cout<<" Tich 2 phan so tren la: ";
    cout<<e;
    phanso f = a/b;
    cout<<" Thuong 2 phan sp tren la: ";
    cout<<f;
    int n;
    cout<<" Nhap so phan so: ";
    cin>>n;
    phanso *s;
    s = new phanso[n];
    for ( int i =0; i<n;i++){
        cout<<" Nhap phan so thu "<<i+1<<" : \n";
        cin>>s[i];
    }
    for ( int i =0; i<n;i++){
        cout<<"s["<<i+1<<"]: "<<s[i]<<endl;
    }
    float smax, smin;
    int counta = 0;
    int countb = 0;
    smax = (float)gt(s[0]);
    smin = (float)gt(s[0]);
    for( int i=0; i<n;i++){
        if( (float)gt(s[i]) > smax){
            smax = (float)gt(s[i]);
            counta = i;
        }
    }
    for( int i=0; i<n;i++){
       if( (float)gt(s[i]) <smin){
            smin = (float)gt(s[i]);
            countb = i;
        } 
    }
    cout<<" phan so lon nhat la: "<<s[counta]<<endl;
    cout<<" Phan so nho nhat la: "<<s[countb];
    return 0;
}