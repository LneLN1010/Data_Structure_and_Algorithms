#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n=10;
	vector<int> V(1,1);//Khoi tao 1 so 1
	for(int i=2;i<=n;i++){
		int mem=0;
		for(auto &x:V){
			mem+=x*i;
			x = mem%10;
			mem/=10;
			cout<<x;
		}
		while(mem!=0){
			 V.push_back(mem%10);
			 mem /=10;
		}
	}  
	for(auto it=V.rbegin();it!=V.rend();it++) cout<<*it;
	//reverse(V.begin(),V.end());//Dao nguoc vector
//	for(auto x:V) cout<<x;
  return 0;
}

