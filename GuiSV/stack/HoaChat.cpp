//Cong thuc hoa hoc
#include <bits/stdc++.h>
using namespace std;
map<char,int> K={{'C',12},{'H',1},{'O',16},{'(',0}};
int main ()
{
  //string x="((CHOH)2(COOH)2H2O)4";
  char x[10005];
  cin>>x;
  cout<<strlen(x);
  stack<int> S;
  for(int i=0;i<strlen(x);i++){
  	char c = x[i];
  //for(auto c:x){
  	if(K.find(c)!=K.end()) S.push(K[c]);
  	else if(c==')'){
  		int t=0;
  		while(S.top()){
  			t+=S.top();S.pop();
		}
		S.pop();
		S.push(t);
	  }
	  else S.top()*=c-'0';
  }
  int t=0;
  while(S.size()) {t+=S.top(); S.pop();}
  cout<<"Khoi luong "<<x<<" la: "<<t;
  return 0;
}

