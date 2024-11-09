#include <bits/stdc++.h>
using namespace std;
int main ()
{
	unsigned int n;cin>>n;
	char HEX[] = "0123456789ABCDEF";
	stack<char> S;
	while(n){
		S.push(HEX[n%16]); n/=16;//n>>=4;
	}
	while(S.size()) {cout<<S.top(); S.pop();
	}
//	cout<<setbase(16)<<n;
  
  return 0;
}

