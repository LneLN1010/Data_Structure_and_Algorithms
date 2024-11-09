//cai dat queue bang ds lien ket don
#include <bits/stdc++.h>
using namespace std;
template<class T>
struct node{
	T elem;
	node<T> *next;
	node<T>(T x,node<T> *N=0){elem = x; next =N;}
};
template <class T>
class Queue{
	int num;
	node<T> *head,*trail;
	public:
		Queue(){num=0;head=trail=0;}
		int size(){return num;}
		bool empty(){return num==0;}
		T &front(){return head->elem;}
		T &back(){return trail->elem;}
		void pop(){
			head=head->next;num--;
			if(!num) trail=0;
		}
		void push(T x){
			if(num==0) head=trail=new node(x);
			else{trail->next = new node<T>(x); trail=trail->next;}
			num++;
		}
};
int main ()
{

  return 0;
}

