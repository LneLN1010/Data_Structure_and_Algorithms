#include <bits/stdc++.h>
using namespace std;
int main ()
{
  int n,m;
  vector<double> P,Q,R;
  cin>>n;  P.resize(n+1); for(auto &x:P) cin>>x;
  cin>>m;  Q.resize(m+1); for(auto &x:Q) cin>>x;
  R.resize(m+n+1,0);
  for(int i=0;i<=n;i++){
  	for(int j=0;j<=m;j++){
		R[i+j] +=P[i]*Q[j];
	}
  }
  for(auto r:R) cout<<r<<" ";
  return 0;
}

