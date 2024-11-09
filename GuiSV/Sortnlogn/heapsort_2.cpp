#include <bits/stdc++.h>
using namespace std;
template <class T>
void Swap(T &a, T &b)
{
     T tg=a;
     a=b;
     b=tg;
}
template<class T>
void heapify (T *A, int n, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left<n&&A[left]>A[max]) max = left; 
    if(right<n&&A[right]>A[max]) max = right;
    if(max!=i){
    	Swap(A[i],A[max]);
    	heapify(A,n,max);
	}
}
template<class T>
void BuildMaxHeap(T *A,int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(A,n,i);
	}
}
template<class T>
void HeapSort(T *A, int n)
  {  
    BuildMaxHeap(A,n);
    for(int i=n-1; i>0;i--){
        Swap(A[0],A[i]);
	    heapify(A,i,0);
     }
  } 
int main(){
 double a[] = {3, 1, 4, 6, 2, 8, 5}, b[10000];
  int n = sizeof(a)/sizeof(double);
  HeapSort<double>(a,n);
  for(auto x:a) cout<<x<<" ";
  return 0;
}


