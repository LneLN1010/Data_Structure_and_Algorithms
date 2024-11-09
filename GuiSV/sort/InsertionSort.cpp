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
template<class T>
void InsertionSort(T *a,int n){
     T x;
     int i, j;
     for(i=1; i<=n-1;i++){
        j = i-1;
        x = a[i];
        cout<<"i = "<<i<<", j = "<<j<<": ";
		printArray(a,n);
        while(a[j]>x && j>=0){
           a[j+1]=a[j];
           j--;
           cout<<"\nj= "<<j<<", x =  "<<x<<" : ";
           printArray(a,n);
        }

		a[j+1]= x;
		cout<<"\n";
		printArray(a,n);
     }
}
int main ()
{
//	int a[]={80, 76, 10, 15 ,75, 20, 9};
	int a[]={12 , 43 ,  11,   34  ,  23  ,  43};
	int n =sizeof(a)/sizeof(int);
printArray(a,n);
	InsertionSort(a,n);
	printArray(a,n);
  return 0;
}

