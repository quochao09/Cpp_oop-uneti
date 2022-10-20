#include<iostream>
using namespace std;
class vector3{
    private:
    int a,b,c;
    public:
    vector3( int a =0, int b=0, int c=0){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    ~vector3(){
        a=0;
        b=0;
        c=0;
    }
    void input(){
        cout<<" Nhap vector: \n";
        cout<<" a = "; cin>>a;
        cout<<" b = "; cin>>b;
        cout<<" c = "; cin>>c;
    }
    void output(){
        cout<<"( "<<a<<","<<b<<","<<c<<" )"<<endl;
    }
    friend vector3 operator +( vector3 v1, vector3 v2){
        vector3 t;
        t.a = v1.a + v2.a;
        t.b = v1.b + v2.b;
        t.c = v1.c + v2.c;
        return t;
    }
    friend vector3 operator -( vector3 v1, vector3 v2){
        vector3 h;
        h.a = v1.a - v2.a;
        h.b = v1.b - v2.b;
        h.c = v1.c - v2.c;
        return h;
    }
};
int main(){
    vector3 v;
    v.output();
    vector3 v1 ,v2 ;
    cout<<" Nhap vector thu 1: \n";
    v1.input();
    v1.output();
    cout<<" Nhap vector thu 2: \n";
    v2.input();
    v2.output();
    cout<<" Tong 2 vector la: ";
    vector3 v3 = v1 +v2;
    v3.output();
    cout<<" hieu 2 vector la: ";
    vector3 v4 = v1 - v2;
    v4.output();
    return 0;
}