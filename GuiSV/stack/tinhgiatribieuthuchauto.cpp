//Chonbieu thuc hau to, tinh gia tri bieu thu
#include <bits/stdc++.h>
using namespace std;
int f(int a,int b,char o){
	if(o=='+') return a+b;
	if(o=='-') return a-b;
	if(o=='*') return a*b;
	if(o=='/') return a/b;
	if(o=='%') return a%b;
}

int main ()
{
	string x="2342*+5*323+*++";//72
	stack<int> S;
	for(char c:x){
		if('0'<=c && c<='9') S.push(c-'0');
		else{
			int x = S.top();S.pop();
			int y = S.top();S.pop();
			S.push(f(y,x,c));
		}
	}
	cout<<S.top();
  return 0;
}

