#include<bits/stdc++.h>
#include<list>
using namespace std;

class Thuebao{
    private:
        int phone;
        string name;
        string address;
    public:
        Thuebao(){}
        Thuebao(int p,string n,string a){
            phone=p;
            name=n;
            address=a;
        }
        friend istream& operator>>(istream& is,Thuebao& t){
            cout<<"Nhap so thue bao         : ";is>>t.phone;
            is.ignore();
            cout<<"Nhap ten thue bao        : ";getline(is,t.name);
            cout<<"Nhap dia chi thue bao    : ";getline(is,t.address);
            return is;
        }
        friend ostream& operator<<(ostream& os,Thuebao& t){
            os<<"So thue bao:      "<<t.phone<<endl;
            os<<"Ten thue bao:     "<<t.name<<endl;
            os<<"Dia chi thue bao: "<<t.address<<endl;
            return os;
        }
        int getPhone(){
            return phone;
        }
        string getname(){
            return name;
        }
        string getadd(){
            return address;
        }
};
class qltb:public Thuebao{
    private:
        list<Thuebao> listtb;
    public:
        void in(){
            cout<<"Danh sach thue bao:"<<endl;
            for(auto& t:listtb){
                cout<<t<<endl;
            }
        }
        void themd(Thuebao t){
            listtb.push_front(t);
        }
        void themc(Thuebao t){
            listtb.push_back(t);
        }
        void xoa(int n) {
        list<Thuebao>::iterator it = listtb.begin();
        while (it != listtb.end()) {
            if (it->getPhone() == n) {
                it = listtb.erase(it);
            }else {
                ++it;
                }
            }
        }

        void find(int n){
            list<Thuebao>::iterator it = listtb.begin();
             while (it!=listtb.end())
             {
                if(it->getPhone()==n){
                    cout << "So thue bao: " << it->getPhone() << endl; 
                    cout << "Ten thue bao: " << it->getname() << endl; 
                    cout << "Dia chi thue bao: " << it->getadd() << endl; 
                    return;
                }
             }
             cout<<"khong tim thay thue bao: "<<n<<endl;
        }

};

class app:public qltb{
    private:
        qltb tb;
    public:
        void showMenu(){
            int x,m;
            Thuebao t;
            do{
                cout<<"1. In Danh sach thue bao"<<endl;
                cout<<"2. Them thue bao vao dau ds"<<endl;
                cout<<"3. Them thue bao vao cuoi danh sach"<<endl;
                cout<<"4. Tim kiem thue bao"<<endl;
                cout<<"5. Xoa thue bao"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Nhap lua chon: ";cin>>x;

                switch (x){
                    case 1:
                        tb.in();
                        break;
                    case 2:
                        cout<<"Nhap thong tin thue bao them:"<<endl;cin>>t;
                        tb.themd(t);
                        break;
                    case 3:
                        cout<<"Nhap thong tin thue bao them:"<<endl;cin>>t;
                        tb.themc(t);
                        break;
                    case 4:
                        cout<<"Nhap so thue bao muon tim: ";cin>>m;
                        tb.find(m);
                        break;
                    case 5:
                        cout<<"Nhap so thue bao muon xoa: ";cin>>m;
                        tb.xoa(m);
                        break;
                    case 0:
                        cout<<"Ket thuc chuong trinh!!!";
                        break;
                    default:
                        cout << "Lua chon khong hop le!\n";
                }
            }while(x!=0);
        }    
};
int main(){
    app ap;
    ap.showMenu();
    return 0;
}