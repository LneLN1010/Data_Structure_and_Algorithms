#include <bits/stdc++.h>
using namespace std;
template <class T>
void quicksort(T *L,T *R, bool cmp(T,T)=[](T x, T y){return x<y;}){
//SX tu con tro L den R-1, mang b la mang trung gian, ham so sanh cmp de mac dinh tang dan
	if(L+1>=R) return;
	T x = *(L+(R-L)/2);//Lay gia tri phan tu chot o giua
	T *p=L,*q=R-1;
	while(p<=q){
		while(p<R && cmp(*p,x)) p++;
		while(q>=L && cmp(x,*q)) q--;
		if(p<=q){
			swap(*p,*q);
			p++;
			q--;
		}
	}
	quicksort(L,q+1,cmp);
	quicksort(p,R,cmp);

}

bool ss(double u, double v){ return u>v;}

int main ()
{
  double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  quicksort<double>(a,a+n);
  for(auto x:a) cout<<x<<" ";
  return 0;
}

