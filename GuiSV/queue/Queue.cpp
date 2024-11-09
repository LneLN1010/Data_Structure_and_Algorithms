//cai dat Q bang mang
#include <bits/stdc++.h>
#ifndef __Queue__cpp
#define __Queue__cpp
using namespace std;
template<class T>
class Queue{
	T *buff;
	int num,cap,F,L;
	public:
		Queue<T>(){
			num=cap=0;F=L=0;
			buff=0;
		}
		~Queue<T>(){
			if(buff) delete[]buff;buff=0;
		}
		int size(){ return num;}
		bool empty(){ return num==0;}
		T &front(){ return buff[F];	}
		T &back(){ return L==0?buff[cap-1]:buff[L-1];}
		void pop(){
			F = (F+1)%cap;
			num--;
		}
		void push(T x){
			if(num==cap){
				int newcap = cap*2+1;
				T *tem = new T[newcap];
				for(int i=F,j=0;i<F+cap;i++,j++) tem[j] = buff[i%cap];
				if(buff) delete[]buff;
				buff=tem;
				F=0;L=cap;
				cap=newcap;
			}
			buff[L]=x;
			L=(L+1)%cap;
			num++;
		}
};
#endif
