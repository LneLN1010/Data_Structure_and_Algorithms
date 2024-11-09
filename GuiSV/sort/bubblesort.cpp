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
void printArray(T *A,int n){
	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;
}
template <class T>
void BubbleSort(T *a, int n){
	  int i, j;
	  for (i=0;i<n-1;i++)
	  {
	  	for(j=n-1;j>i;j--)
	  	{
	  		if(a[j]<a[j-1])
				Swap(a[j],a[j-1]);
			cout<<"i="<<i<<", j="<<j<<": ";
			printArray(a,n);
		}
	  }
}
//template <class T>
//void BubbleSort(T *a, int n, int (*comp)(T,T)){
//	  int i, j;
//	  for (i=0;i<n-1;i++)
//		  for(j=n-1;j>i;j--)
//          	  if(comp(a[j],a[j-1]))
//				  Swap(a[j],a[j-1]);
//}

//template <class T>
int GiamDan(int a,int b){
	if(a>b) return 1;
	return 0;
}
int TangDan(int a,int b){
	if(a<b) return 1;
	return 0;
}

int main ()
{
	int a[]={80, 76, 10, 15 ,75, 20, 9};
	int n =sizeof(a)/sizeof(int);
	
	//BubbleSort(a,n,TangDan);//Tang dan
	printArray(a,n);
	//BubbleSort(a,n,GiamDan);//Giam dan
	BubbleSort(a,n);
	//printArray(a,n);
  return 0;
}

