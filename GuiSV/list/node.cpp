#include <bits/stdc++.h>
#ifndef __node__cpp__
#define __node__cpp__
using namespace std;
template <class T>
class node{
	T elem;
	node<T> *prev,*next;
	public:
		node(T x, node<T> *L=0,node<T> *R=0){
			elem=x;prev=L;next = R;
		}
		T &getelem(){
			return elem;
		}
		node<T> *&getprev(){return prev;}
		node<T> *&getnext(){return next;}
		void setelem(T x){elem=x;}
		void setprev(node<T> *p=nullptr){prev=p;}
		void setnext(node<T> *p=nullptr){next=p;}
};

#endif
//
//int main(){
//	node<int> N(2);
//	node<int> *A = new node<int>(7,0,&N);
//
//	node<int> C(8,A,A);
//	node<int> *B = new node<int>(6,A,&C);
//	node<int> *p=B;
//	while(p!=NULL){
//
//		cout<<p->getelem()<<" ";
//		p=p->getnext();
//	}
//
//}
