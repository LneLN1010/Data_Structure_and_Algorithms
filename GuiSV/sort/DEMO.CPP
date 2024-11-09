#include"conio.h"
#include"stdio.h"
#include"iostream"
#include"sortnn.cpp"
#include"array.cpp"
using namespace std;
int compare(float x, float y){
   if (x<y)
      return 1;
   else
      return 0;     
}
int compare1(float x, float y){
   if (x>y)
      return 1;
   else
      return 0;     
}
int main(){
     float *a;
     int n;
     system("cls");
     cout<<"Nhap n=";
     cin>>n;
     a =  new float[n];
     InputArr(a, n, "a");
     system("cls");
     //cout<<"Day so ban dau:";
     //PrintArr(a,n,1);
      BubbleSort(a,n,compare);
     //SelectionSort(a,n,compare1);
     //InsertionSort(a,n,compare);
     //cout<<"\nDay so duoc sep:";
     //PrintArr(a,n,1);
     getch();     
     return 0;
}
