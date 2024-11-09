#include <bits/stdc++.h>
using namespace std;
template <class T>
void mergesort(T *L,T *R, T *b, bool cmp(T,T)=[](T x, T y){return x<y;}){
//SX tu con tro L den R-1, mang b la mang trung gian, ham so sanh cmp de mac dinh tang dan
	if(L+1>=R) return;
	T *M = L+(R-L)/2;
	mergesort(L,M,b,cmp);//goi de quy trai
	mergesort(M,R,b,cmp);//goi de quy phai
	T *p=L, *q=M,*r;
	for(r=b;r<b+(R-L);r++){
		if(p<M && q<R){
			*r = cmp(*p,*q)?*p++:*q++;
		}
		else{
			*r = p<M?*p++:*q++;
		}
	}
	for(p=L,r=b;p<R;p++,r++) *p=*r;
}

bool ss(double u, double v){ return u>v;}

int main ()
{
  double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5}, b[10000];
  int n = sizeof(a)/sizeof(double);
  mergesort<double>(a,a+n,b);
  for(auto x:a) cout<<x<<" ";
  return 0;
}

