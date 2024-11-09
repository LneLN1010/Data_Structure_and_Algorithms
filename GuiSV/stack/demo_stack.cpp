#include <bits/stdc++.h>
using namespace std;

int main ()
{
	stack<int> S;
	int a[] = {4,7,2,8};
	for(auto x:a) S.push(x);
	while(!S.empty())  {cout<<S.top()<<" "; S.pop();} 
  return 0;
}

