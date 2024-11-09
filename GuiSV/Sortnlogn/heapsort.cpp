#include <bits/stdc++.h>
using namespace std;
template <class T>
void heapify(T *L, T *R,T *p,bool cmp(T,T))//Tao heap, vun dong cho vi tri p
{
	if(p+(p-L)+1>=R) return ;
	T *z = p + (p-L)+1;
	if(z+1<R && cmp(*z,*(z+1))) z++;
	if(cmp(*p,*z)) {swap(*p,*z); heapify(L,R,z,cmp);}
}
template <class T>
void HeapSort(T *L,T *R,bool cmp(T,T)=[](T x,T y){return x<y;}){
	for(T *p=R-1;p>=L;p--) heapify(L,R,p,cmp);//tao dong
	for(T *p=R-1;p>L;p--){
		swap(*L,*p);
		heapify(L,p,L,cmp);
	}	
}
bool ss(double u, double v){ return u>v;}
int main ()
{
  double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  HeapSort<double>(a,a+n);
  for(auto x:a) cout<<x<<" ";
  return 0;
}

