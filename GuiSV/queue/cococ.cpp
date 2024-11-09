#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,k;
	cout<<"Nhap so luong coc: ";cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cout<<"Nhap dung tich coc a["<<i<<"]: ";
		cin>>a[i];
	}
	cout<<"Nhap k: ";cin>>k;
	queue<int> Q;
	sort(a,a+n);
	Q.push(a[0]);
	for(int i=1;i<n;i++){
		if(a[i]-Q.front()>=k) {
			Q.pop();
		}
		Q.push(a[i]);
	}
	cout<<"\n So coc it nhat la: "<<Q.size();
  return 0;
}

