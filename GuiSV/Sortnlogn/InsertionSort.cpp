#include <bits/stdc++.h>
using namespace std;
template <class T>
void Swap(T &a, T &b)
{
    T tg =a;
    a= b;
    b=tg;
}
template<class T>
void InsertionSort(T *a,int n){
     T x;
     int i, j;
     for(i=1; i<n;i++){
        j = i-1;
        x = a[i];
        while(x<a[j] && j>=0){
           a[j+1]=a[j];
            j--;
        }   
        a[j+1]= x;
     }      
}

int main(){
 double a[] = {3.5, 1.2, 4.7, 6.3, 1.8, 8.2, 5};
  int n = sizeof(a)/sizeof(double);
  InsertionSort<double>(a,n);
  for(auto x:a) cout<<x<<" ";
}


