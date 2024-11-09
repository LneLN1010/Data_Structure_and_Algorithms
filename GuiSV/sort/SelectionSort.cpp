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
void SelectionSort(T *a,int n){
     int i,j,min;
     for(i=0;i<=n-2;i++){
             min=i;
             for(j=i+1;j<n;j++)
				{
					if(a[min]>a[j]) min=j;
					cout<<"i="<<i<<", j="<<j<<": "<<" postmin = "<<min<<endl;
				}
             if(min!=i)
                 Swap(a[i],a[min]);
		cout<<"i="<<i<<", j="<<j<<": ";
		printArray(a,n);
     }
}


int main ()
{
	//int a[]={80, 76, 10, 15 ,75, 20, 9};
	int a[]={12 , 43 ,  11 ,  34 ,   23 ,   435};
	int n =sizeof(a)/sizeof(int);

printArray(a,n);
	SelectionSort(a,n);
	printArray(a,n);
  return 0;
}

