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
void SelectionSort(T *a, int n){
    int i,j,min;
     for(i=0;i<n-1;i++){ 
         min=i;
         for(j=i+1;j<n;j++)
             if(a[min]>a[j]) min=j;
         if(min!=i) 
             Swap(a[i],a[min]);
     }		  		  
}

int main(){
 double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  SelectionSort<double>(a,n);
  for(auto x:a) cout<<x<<" ";
}


