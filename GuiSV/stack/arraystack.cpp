//Cai dat stack bang mang
#include <bits/stdc++.h>
using namespace std;
#ifndef __arraystack__cpp
#define __arraystack__cpp
template <class T>
class Stack{
	unsigned cap,num;
	T *buff;
	public:
		Stack(){
			buff=NULL; cap=num=0;
		}
		void reserve(unsigned newcap){
			if(newcap<cap) return;
			cap = newcap;
			T *temp = new T[cap];
			for(int i=0;i<num;i++) temp[i] = buff[i];
			if(buff) delete[] buff;
			buff=temp;
		}
		int size(){return num;}
		bool empty(){return num==0;}
		T &top(){ return buff[num-1];}
		void pop(){if(num) num--;}
		void push(T x){
			if(cap==num) reserve(cap*2+2);
			buff[num++]=x;
		}
};

int menu(){
	int chon;
	cout<<"\nCHUONG TRINH QUAN LY STACK\n";
	cout<<"\n1. Thêm m?t ph?n t? vào stack";
	cout<<"\n2. L?y m?t ph?n t? ra kh?i stack";
	cout<<"\n3. Cho bi?t stack có r?ng hay không?";
	cout<<"\n0. K?t thúc chuong trình.";
	cout<<"\nMoi ban chon chuc nang: (1,2,3,0): ";
	cin>>chon;
	return chon;
}
#endif
/*
int main(){
	Stack<int> S;
	int chon;
	while(chon=menu()){
		switch(chon){
			case 1:
				cout<<"\nNhap phan tu: ";
				int x;cin>>x;
				S.push(x);
				cout<<"\nDa them vao Stack thanh cong\n";
				break;
			case 2:
				cout<<"\nPhan tu lay duoc la: "<<S.top();
				S.pop();
				break;
			case 3:
				if(S.empty()) cout<<"\nStack rong!";
				else cout<<"Stack chua rong!";
				break;
			default:
				break;
		}
		cout<<"BYE BYE";
		}
	
	
	
	
//	for (int i=0; i<10; i++){
//		S.push(i);
//	}
//	
//	cout << "Phan tu tren cung cua stack la: " << S.top() << endl;
//
//	S.push(100);
//	cout << "Them phan tu 100: " << endl;
//	cout << "Phan tu tren cung cua stack la: " << S.top() << endl;
//
//	S.pop();
//	cout << "Sau khi lay 1 phan tu, phan tu tren cung la: " << S.top() << endl;
//	
//	cout << (S.empty() ? "Stack dang rong" : "Stack khong rong") << endl;
	
	return 0;
}
*/
