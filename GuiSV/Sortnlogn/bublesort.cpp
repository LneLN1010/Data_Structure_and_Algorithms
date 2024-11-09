#include <bits/stdc++.h>
using namespace std;
template <class T>
void Swap(T &a, T &b)
{
    T tg =a;
    a= b;
    b=tg;
}
template <class T>
void BubbleSort(T *a, int n){
  int i, j;
  for (i=0;i<n-1;i++)
	  for(j=n-1;j>i;j--)
      	  if(a[j]<a[j-1])
			  Swap(a[j],a[j-1]);			  		  
}
template <class T>
void BubbleSort2(T *a, int n){
  int i, j;
  for (i=0;i<n-1;i++)
	  for(j=0;j<n-i-1;j++)
      	  if(a[j]>a[j+1])
			  Swap(a[j],a[j+1]);			  		  
}
int main(){
 double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  BubbleSort2<double>(a,n);
  for(auto x:a) cout<<x<<" ";
}


