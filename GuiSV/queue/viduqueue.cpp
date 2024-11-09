#include <bits/stdc++.h>
using namespace std;
int main ()
{
	queue<int> Q;
	for(int x:{3,7,2,1}) Q.push(x);
	Q.back()=4;
	while(!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
  return 0;
}

