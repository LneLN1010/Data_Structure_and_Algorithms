#include<bits/stdc++.h>
using namespace std;
template <class T>
class node//Dinh nghia 1 nut
{
	T elem;//Thah
	node *next;
	public:
	node(T x,node *N=0) {elem=x;next=N;}
	void setelem(T x) {elem=x;}
	void setnext(node *N) {next=N;}
	T &getelem(){return elem;}
	node *getnext(){return next;}
};
template <class T>
class list_iterator
{
	node<T> *curr;
	public:
		//list_iterator() {curr=NULL;}
		list_iterator(node<T> *c) {curr=c;}
		node<T> *getcurr() {return curr;}
		//list_iterator<T> &operator=(list_iterator<T> p) {this->curr=p.getcurr();return *this;}
		list_iterator<T> operator++() {curr=curr->getnext();return curr;}
	//	list_iterator<T> operator++(int) {list_iterator<T> c=curr; curr=curr->getnext();return c;}
		T &operator*() {return curr->getelem();}
		bool operator!=(list_iterator<T> p) {return this->getcurr()!=p.getcurr();}
};
template <class T>
class slist
{
	node<T> *head,*tail;
	int num;
	public:
		typedef list_iterator<T> iterator;
		slist() {head=tail=NULL; num=0;}
		void push_back(T x) {if(num==0) head=tail=new node<T>(x); else tail->setnext(new node<T>(x)),tail=tail->getnext(); num++;}
		void push_front(T x) {if(num==0) head=tail=new node<T>(x); else head=new node<T>(x,head); num++;}
		iterator begin() {return (iterator)head;}		
		iterator end() {return (iterator)NULL;}
		void pop_back() 
		{
			if(num==0) return; 
			if(num==1) {num--; head=tail=NULL;}
			node<T>*p=head; while(p->getnext()!=tail) p=p->getnext(); p->setnext(NULL); tail=p; num--;
		}
		void pop_front() 
		{
			if(num==0) return; 
			if(num==1) {num--; head=tail=NULL;}
			head=head->getnext(); num--;
		}
		T front(){return head->getelem();}
		T back(){return tail->getelem();}
		int size(){return num;}
		bool empty(){return num==0;}
};
 
int main()
{
	slist<int> L;
	for(int i=1;i<=10;i++) i%2?L.push_front(i):L.push_back(i);
//	for(slist<int>::iterator it=L.begin(); it!=L.end();it++) cout<<*it<<" ";
	for(auto it=L.begin(); it!=L.end();it++) cout<<*it<<" ";
//	for(auto &x:L) x=6;
//	for(auto x:L) cout<<x<<" ";
}
