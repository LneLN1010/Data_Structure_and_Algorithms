#include <bits/stdc++.h>
#include "node.cpp"
#include "dlist_iterator.cpp"
using namespace std;
#ifndef __dlist__cpp__
#define __dlist__cpp__
template <class T>
class dlist{
	node<T> *head,*trail;
	unsigned int num;
	public:
		typedef dlist_iterator<T> iterator;
		typedef dlist_reverse_iterator<T> reverse_iterator;
		dlist(){num=0;head=trail=nullptr;}
		dlist(int k,T x){num=0;head=trail=nullptr;while(k--) push_back(x);}//Tao list k phan tu bang x
		bool empty(){ return num==0;}
		unsigned size(){return num;}
		reverse_iterator rbegin(){
			return trail;
		}
		reverse_iterator rend(){
			return NULL;
		}
		iterator begin(){
			return head;
		}
		iterator end(){
			return NULL;
		}
		void push_back(T x){
			if(num==0) head=trail=new node<T>(x);
			else {
				trail->setnext(new node<T>(x,trail,0));
				trail = trail->getnext();
			}
			num++;
		}
		void push_front(T x){
			if(num==0) head=trail=new node<T>(x);
			else {
				head->setprev(new node<T>(x,0,head));
				head = head->getprev();
			}
			num++;
		}
		T &front(){return head->getelem();}
		T &back(){return trail->getelem();}
		void pop_back(){
			if(num==0) return;
			if(num==1) head=trail=nullptr;
			else{
				trail=trail->getprev();
				trail->setnext(NULL);
			}
			num--;
		}
		void pop_front(){
			if(num==0) return;
			if(num==1) head=trail=nullptr;
			else{
				head=head->getnext();
				head->setprev(0);
			}
			num--;
		}
		void insert(iterator it,T x){
			node<T> *p = it.getcurr();
			if(p==head) return push_front(x);
			node<T> *q = p->getprev();
			node<T> *r = new node<T>(x,q,p);
			p->setprev(r);
			q->setnext(r);
			num++;
		}
		void erase(iterator it)
		{
			if(it.getcurr()==head) return pop_front();
			if(it.getcurr()==trail) return pop_back();
			node<T>*L=it.getcurr()->getprev(),*R=it.getcurr()->getnext();
			L->setnext(R); R->setprev(L);
			num--;
		}
};
#endif
//int main(){
//	dlist<int> L; cout<<"L init: num = "<<L.size()<<" head = "<<L.gethead()<<" trail = "<<L.gettrail()<<endl;
//	L.push_back(5);
//	L.push_back(6);
//	L.push_back(7);
//	L.push_front(1);
//	L.push_front(2);
//	L.push_front(3);
//	dlist<int>::iterator k=L.begin();
//	k++;k++;
//	L.erase(k);
//	k=L.begin();
////	//k++;k++;
//	L.insert(k,9);
//	cout<<"\nDuyet xuoi: ";
//	for(dlist<int>::iterator it=L.begin();it!=L.end();it++) cout<<*it<<" ";
////	cout<<"\nDuyet nguoc: ";
////	for(dlist<int>::reverse_iterator rit=L.rbegin();rit!=L.rend();rit++) cout<<*rit<<" ";
//}
