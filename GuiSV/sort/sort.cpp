#include <bits/stdc++.h>
using namespace std;
 template<class T>
void printArray(T *A,int n);
template <class T>
void Swap(T &a, T &b)
{
     T tg =a;
     a= b;
     b=tg;
}
template<class T>
  void printArray(T *A,int n){
  	for(int i =0;i<n;i++) cout<<A[i]<<" ";
  	cout<<endl;
  }
template <class T>
void Partition (T *A, int i, int j, int   &right)
{
     T p = A[i];
     int left = i;
			right = j;
     while( left < right)
     {
	     while(A[left]<=p && left<=right) left++; 
	     while(A[right]>p) right--;
	     if(left < right)
        	 Swap(A[left],A[right]);	
      }
     	if(i!=right)
     	   Swap(A[i],A[right]);	 
 } 
 template <class T>
 void QuickSort(T *a,int i, int j)
 {
      int k;
      if(i<j)
      {
             Partition(a,i,j,k);
            // printArray(a,8);
             QuickSort(a,i,k-1);
             QuickSort(a,k+1,j);
      }
 }  
//Thuat toan sap xep tron
template <class T>
void Merge( T *A, T *B, int i, int k, int j)
{
    int left=i;
    int right=k+1;
    int t = i;
    while(left<=k && right<=j)
    {
       if (A[left]<A[right])
       {
		     B[t] = A[left];
		     left++;
           t++;
       }
	    else
	    {
		     B[t] = A[right];
		     right++;
           t++;            
       }
     }//ket thuc while
     if(left>k)
         for(int r=right;r<=j;j++)
         {
            B[t]=A[r];
            t++;
         }
     else
         for(int r=left; r<=k; r++)
         {
             B[t]=A[r];
             t++;
         } 
     for(int r =i; r<=j ;r++)
         A[r] = B[r] ; 
   }
template <class T>
void Mergesort(T *A, T *B, int i, int j)
{
     if(i<j)
     {
         int k=(i+j)/2;
	      Mergesort(A,B,i, k);
	      Mergesort(A,B,k+1,j);
       	Merge(A,B, i, k, j);
      }
}  
//Sap xep heap sort
template<class T>
void Pushdown (T *A, int i, int n)
{
    int j = i; 
    int kt=0;
    int max;
    while (j<=n/2 && kt==0)
    {
       if(2*j==n)
           max = 2*j;
       else 
          if (A[2*j]<=A[2*j+1])
              max = 2*j+1;
          else  
			  max = 2*j;
       if (A[j]<A[max])  
       {
          Swap (A[j], A[max]);
          j = max;
       }
       else 
         kt=1;
     }
     printArray(A,8);
  }
  template<class T>
  void HeapSort(T *A, int n)
  {  
     int i;
     
     for(i=(n-1)/2; i>= 0;i--)
        Pushdown(A,i, n-1);
        
     for(i=n-1;i>=2;i--)
     {
        Swap(A[0],A[i]);
	     Pushdown(A,0,i-1);
     }
  } 
  
int main ()
{
	int a[]={12,43  , 11  , 34   , 23  ,  43  ,  12 ,  435};
//	int a[]={10,3,24,1,4,21,54,5};
	int n = sizeof(a)/sizeof(int);
	//QuickSort(a,0,n-1);
HeapSort(a,n);
	printArray(a,n);
  return 0;
}

