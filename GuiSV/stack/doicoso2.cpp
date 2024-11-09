#include <bits/stdc++.h>
#include "arraystack.cpp"
#include "nodestack.cpp"
using namespace std;
int main ()
{
	int n;cin>>n;
	STACK<int> S;
	while(n){S.push(n%2);
	n/=2;//n>>1;Dich bit sang trai 1 bit. 
	}
	while(S.size()) {cout<<S.top(); S.pop();}
  
  return 0;
}

