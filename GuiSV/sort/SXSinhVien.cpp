#include"conio.h"
#include"stdio.h"
#include"string.h"
#include"iostream"
#include"sortnn.cpp"
#include"array.cpp"
#include"student.cpp"
using namespace std;
int compare(Student x, Student y){
   if (x.getMaSV()<y.getMaSV())
      return 1;
   else
      return 0;     
}
int compare_Name(Student x, Student y){
   if (strcmp(x.getHoten(),y.getHoten())<0)
      return 1;
   else
      return 0;     
}
int main(){
     Student *a;
     int n;
     system("cls");
     cout<<"Nhap so sinh vien n=";
     cin>>n;
     a =  new Student[n];
     InputArr(a, n, "Nhap SV thu ");
     system("cls");
     cout<<"Danh sach sinh vien:\n";
     PrintArr(a,n,1);     
     //BubbleSort(a,n,compare);
     BubbleSort(a,n,compare_Name);
     // SelectionSort(a,n,compare);
     //InsertionSort(a,n,compare);
     cout<<"\nDanh sach sinh vien sau khi sap xep:\n";
     PrintArr(a,n,1);
     getch();     
     return 0;
}
