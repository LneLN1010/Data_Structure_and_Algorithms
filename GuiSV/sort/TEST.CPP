#include"conio.h"
#include"stdio.h"
#include"math.h"
#include"dos.h"
#include"stdlib.h"
#include"time.h"
#include"iostream"
#include"../Sort/Sort.cpp"
using namespace std;
//Ham tao mot day so ngau nhien co n phan tu
void CreateArray(float *a, int n)
{
	randomize;
	for(int i=0;i<n;i++)
	{
	   a[i]= random(1000000);
	}
}
template <class T>
void PrintArray(T *a, int n)
{
	for(int i=0;i<n;i++)
	   cout<<a[i]<<"\n";
} 
int main(){
	  struct time t;
	  long t1,t2;
	  float *a;
	  int n;
	  system("cls");
	  cout<<"Nhap n=";
	  cin>>n;
	  a = new float[n];
	  CreateArray(a,n);
	  gettime(&t);
	  t1= t.ti_hour*60*60*1000+t.ti_min*60*1000+t.ti_sec*1000+t.ti_hund;
	  QuickSort(a,0,n-1);
	  gettime(&t);
	  t2=t.ti_hour*60*60*1000+t.ti_min*60*1000+t.ti_sec*1000+t.ti_hund;
	  cout<<"Thoi gian sap xep="<<t2-t1;
	  getch();
	  PrintArray(a,n);
	  getch();
	  return 0;
}
