#ifndef ARRAY_H
#define ARRAY_H 0
#include"iostream"
using namespace std;
template <class T>
void InputArr(T *a, int n, char *c){
     for(int i=0;i<n;i++){
       cout<<c<<"["<<i<<"]=";
       cin>>a[i];
     } 
}
template <class T>
void PrintArr(T *a, int n, int xuongdong){
      //xuongdong=1 thi in ra theo cot, nguoc lai in ra theo hang
	  for(int i=0;i<n;i++)
	     if (xuongdong)
            cout<<a[i]<<"\n";     
         else  
            cout<<a[i]<<" ";     
}
#endif
