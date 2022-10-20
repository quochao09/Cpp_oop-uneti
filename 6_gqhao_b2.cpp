#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class kh{
    char ht[30];
    char cmnd[10];
    char k[50];
    struct ns{
        int ngay, thang , nam;
    } date;
    public:
    friend istream& operator >>( istream &is , kh &a){
        fflush(stdin);
        cout<<" Ten khach hang : ";
        is.getline(a.ht,30);
        cout<<" So cmnd: ";
        is.getline(a.cmnd,10);
        cout<<" Ho khau: ";
        is.getline(a.k , 50);
        cout<<" Nhap ngay sinh: ";
        is>>a.date.ngay;
        cout<<" Nhap thang sinh: ";
        is>>a.date.thang;
        cout<<" Nhap nam sinh: ";
        is>>a.date.nam;
    }
    friend ostream& operator <<( ostream& os , kh &a){
        os<<" Ten khach hang: "<<a.ht<<endl;
        os<<" SO cmnd: "<<a.cmnd<<endl;
        os<<" Ho khau: "<<a.k<<endl;
        os<<" Ngay sinh: "<<a.date.ngay<<"/"<<a.date.thang<<"/"<<a.date.nam<<endl;
    }
    friend bool operator >(kh a, kh b){
        if( a.date.nam = b.date.nam){
            if( a.date.thang = b.date.thang){
                if( a.date.ngay > b.date.ngay){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if( a.date.thang > b.date.thang){
                return true;
            }
            else{
                return false;
            }
        }
        else if( a.date.nam > b.date.nam){
            return true;
        }
        else{
            return false;
        }
    }
    const char* trave(){
        return k;
    }
};
int main(){
    kh *s;
    int count =0;
    int n;
    cout<<" Nhap so khach hang: ";
    cin>>n; 
    s = new kh[n];
    for( int i =0;i<n;i++){
        cout<<"      Nhap thong tin khach hang thu:"<<i+1<<" : \n";
        cin>>s[i];
    }
    for( int i =0;i<n;i++){
        cout<<"      DS Thong tin khach hang thu:"<<i+1<<" : \n";
        cout<<s[i]<<endl;
    }
    cout<<"          DS cac khach hang o khu vuc HA NOI: \n";
    for( int i=0;i<n;i++){
        if( strcmp( s[i].trave() , "HA NOI")==0){
            cout<<s[i];
        }
        else{
            count =1;
        }
    }
    if( count ==1){
        cout<<"    .... Khong co khach hang nao o HA NOI\n";
    }
    kh temp;
    for( int i=0; i<n;i++){
        for( int j =i +1;j<n;j++){
            if( s[i]> s[i]){
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
    cout<<"       DS sau khi sap xep: \n";
    for( int i=0;i<n;i++){
        cout<<s[i];
    }
}