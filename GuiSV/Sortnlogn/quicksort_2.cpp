#include <bits/stdc++.h>
using namespace std;
template <class T>
void Swap(T &a,T &b){
	T x = a;
	a = b;
	b = x;
}
template <class T>
int partition(T *a,int left,int right){
	T x=a[left];
	int i = left+1;
	int j = right;
	while(i<=j){
		while(a[i]<=x && i<=j) i++;
		while(a[j]>x && i<=j) j--;
		if(i<j) Swap(a[i],a[j]);
	}
	if(left!=j) Swap(a[left],a[j]);
	return j;
}
template <class T>
void quicksort(T *a,int left,int right){
	int k;
	if(left<right){
		k =partition(a,left,right);
		quicksort(a,left,k-1);
		quicksort(a,k+1,right);
	}
}
int main ()
{
  double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  quicksort<double>(a,0,n-1);
  for(auto x:a) cout<<x<<" ";
  return 0;
}

