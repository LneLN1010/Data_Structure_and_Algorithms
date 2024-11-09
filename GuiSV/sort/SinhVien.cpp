#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
	int masv;
	char hoten[30];
	char gioi[4];
public:
    int getMaSV(){ return masv;}
    char* getHoten(){ return hoten;}
    char* getGioi(){ return gioi;}
	friend istream & operator >>(istream &is, Student &s);
	friend ostream & operator <<(ostream &os, Student s);
};
istream & operator >>(istream &is, Student &s)
{
	 cout<<"\nNhap ma sv:";
	 is>>s.masv;
	 cout<<"Nhap ho va ten:";
	 is.ignore(1);
	 is.get(s.hoten,30);
	 cout<<"Nhap gioi tinh:";
	 is.ignore(1);
	 is.get(s.gioi,4);
	 return is;
}
ostream & operator <<(ostream &os, Student s)
{
	  os<<s.masv<<"\t"<<s.hoten<<"\t" <<s.gioi;
	 return os;
}

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
int compare_GT(Student x, Student y){
   if (strcmp(x.getGioi(),y.getGioi())<0)
      return 1;
   else
      return 0;
}
template <class T>
void Swap(T &a, T &b)
{
    T tg =a;
    a= b;
    b=tg;
}

template <class T>
void BubbleSort(T *a, int n, int (*comp)(T,T)){
	  int i, j;
	  for (i=0;i<n-1;i++)
		  for(j=n-1;j>i;j--)
          	  if(comp(a[j],a[j-1]))
				  Swap(a[j],a[j-1]);
}
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
int main ()
{
	Student *a;
     int n;
     cout<<"Nhap so sinh vien n=";
     cin>>n;
     a =  new Student[n];
     InputArr(a, n, "Nhap SV thu ");
     cout<<"Danh sach sinh vien:\n";
     PrintArr(a,n,1);
     //BubbleSort(a,n,compare);
     BubbleSort(a,n,compare_GT);
     // SelectionSort(a,n,compare);
     //InsertionSort(a,n,compare);
     cout<<"\nDanh sach sinh vien sau khi sap xep:\n";
     PrintArr(a,n,1);
  return 0;
}

