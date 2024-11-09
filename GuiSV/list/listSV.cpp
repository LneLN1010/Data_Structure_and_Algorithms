#include <bits/stdc++.h>
#include"dlist.cpp"
using namespace std;
class sv{
	public:
		int msv;
		string hoten;
		sv(){
			msv=0;
		}
		friend istream &operator>>(istream &in,sv &A){
			cout<<"\nMSV: ";
			in>>A.msv;
			cout<<"\nHo ten: ";
			fflush(stdin);
			getline(in,A.hoten);
			return in;
		}
		friend ostream &operator<<(ostream &out,sv A){
			out<<"\nMSV: "<<A.msv<<" Ho ten: "<<A.hoten;
			return out;
		}
};

int menu(){
	int chon;
	cout<<"\nHE THONG QUAN LY SINH VIEN\n";
	cout<<"Moi ban chon chuc nang ben duoi\n";
	cout<<"\n1. Them SV vao dau DS.";
	cout<<"\n2. Them SV vao cuoi DS.";
	cout<<"\n3. Hien thi danh sach SV.";
	cout<<"\n4. Thoat\n";
	cin>>chon;
	return chon;
}

int main ()
{
	dlist<sv> L;
	int chon;
	sv a;
	while(chon=menu()){
	switch(chon){
		case 1:
			//sv a;
			cin>>a;
			L.push_front(a);
			break;
		case 2:
		//	sv a;
			cin>>a;
			L.push_back(a);
			break;
		case 3:
			cout<<"\nDanh sach SV vua nhap la:\n";
			for(dlist<sv>::iterator x=L.begin();x!=L.end();x++) cout<<*x;
			break;
		case 4:
			return 1;
			break;
	}
}
//	int n;
//	cout<<"Nhap so luong SV: "; cin>>n;
//	for(int i=1;i<=n;i++){
//		cout<<"Nhap SV thu "<<i;
//		sv a;
//		cin>>a;
//		L.push_back(a);
//	}
	
  return 0;
}

