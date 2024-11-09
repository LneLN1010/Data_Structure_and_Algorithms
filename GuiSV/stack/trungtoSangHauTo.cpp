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
int uu_tien(char c)
{
	
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/')
		return 2;
	return 0;
}
string infixToPostfix(string s)
{
    stack<char> opr;
    //opr.push('N');
	string ns;
    for(auto c:s)
    {
        if((c >= '0' && c <= '9')) ns+=c;
	    // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(') opr.push('(');
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')')
        {
            while(opr.top() != '(')
            {
                char o = opr.top();
                opr.pop();
                ns += o;
            }
            opr.pop();
        }

        //If an operator is scanned
        else{
			if(opr.size()){
				while(uu_tien(c) <= uu_tien(opr.top()))
		            {
		                char o = opr.top();
		                opr.pop();
		                ns += o;
		                if(opr.empty()) break;
 		            }

			}
            opr.push(c);

        }
    }
    // Pop all the remaining elements from the stack
	while(opr.size())
    {
        char o = opr.top();
        opr.pop();
        ns += o;
    }

    return ns;

}
int main ()
{
	stack<char> x;
	string exp = "1+2*3-3";
	string pos=infixToPostfix(exp);
	cout<<pos;
//	string x="2342*+5*323+*++";//72
//	stack<int> S;
//	for(char c:x){
//		if('0'<=c && c<='9') S.push(c-'0');
//		else{
//			int x = S.top();S.pop();
//			int y = S.top();S.pop();
//			S.push(f(y,x,c));
//		}
//	}
//	cout<<S.top();
  return 0;
}

