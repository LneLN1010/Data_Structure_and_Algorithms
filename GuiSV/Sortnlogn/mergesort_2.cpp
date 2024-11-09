#include <bits/stdc++.h>
using namespace std;
template <class T>
void Merge(T *A,int left,int mid, int right){
	int i=left,j=mid+1;
	int n = right-left+1;
	T *B = new T[n];
	int k=0;
	while(i<=mid && j<=right){
		if(A[i]<A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];	
	}
	while(i<=mid) B[k++] = A[i++];
	while(j<=right) B[k++] = A[j++];
	for(k=0;k<n;k++) A[left++] = B[k];
	delete []B;
}	
template <class T>
void MergeSort(T *A,int left,int right){
	if(left < right){
		int mid =(left+right)/2;
		MergeSort(A,left,mid);//goi de quy trai
		MergeSort(A,mid+1,right);//goi de quy phai
		Merge(A,left,mid,right);
	}
}
int main ()
{
  double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  MergeSort<double>(a,0,n-1);
  for(auto x:a) cout<<x<<" ";
  return 0;
}

