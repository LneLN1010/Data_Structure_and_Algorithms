#include <bits/stdc++.h>
using namespace std;
template <class Object>
class TreeNode{
	private:
		Object elem;
		TreeNode *Parent;
		vector<TreeNode*>Child;
	public:	
		
		TreeNode(Object  o=0,TreeNode *father=0){
			elem = o;
			Parent = father;
		}
		TreeNode *&getParent(){
			return Parent;
		}
		void setParent(TreeNode* father){
			Parent = father;
		}
		void insertChild(TreeNode *child){
			Child.push_back(child);
		}
		vector<TreeNode*>  &getChild(){
			return Child;
		}
		Object &getElem(){
			return elem; 
		}
		void setElem(Object o){
			elem = o;
		}
		bool hasChild(){
			return Child.size()>0;
		}

};
//Duyet Tien thu tu
void preOrder(TreeNode<int> *Root,string p="\n"){
			if(Root==0) return;
			cout<<p<<Root->getElem();
			for(auto z:Root->getChild()) preOrder(z,p+"\t");
}
//Duyet Hau thu tu
void postOrder(TreeNode<int> *Root,string p="\n"){
			if(Root==0) return;
			for(auto z:Root->getChild()) postOrder(z,p+"\t");
			cout<<p<<Root->getElem();
}
//Duyet Trung thu tu
void inOrder(TreeNode<int> *Root,string p="\n"){
			if(Root==0) return;
			if(Root->hasChild()){
				inOrder(Root->getChild()[0],p+"\t");
			}
			cout<<p<<Root->getElem();
			for(int i=1;i<Root->getChild().size();i++) inOrder(Root->getChild()[i],p+"\t");
}
//Duong di tu nut s den nut f
void path(TreeNode<int> *s, TreeNode<int> *f){
	if(s==f) cout<<s->getElem()<<" ";
	else{
		path(s,f->getParent());
		cout<<f->getElem()<<" ";
	}
}
//chieu cao cua cay
int high(TreeNode<int> *Root){
	if(Root->getChild().size()){
		int max = 0;
		for(auto z:Root->getChild()){
			int h = high(z);
			if(max<h) max  =h;
		}
		return max+1;
	}
	return 0;
}
/*
int main ()
{
	TreeNode<int> *A = new TreeNode<int>(10);//Goc
	TreeNode<int> *B = new TreeNode<int>(15);//Con A
	TreeNode<int> *C = new TreeNode<int>(20);//Con A
	A->getChild().push_back(B);
	A->getChild().push_back(C);
	B->setParent(A);
	C->setParent(A);
	TreeNode<int> *D = new TreeNode<int>(30);//Con B
	B->getChild().push_back(D);
	D->setParent(B);
	TreeNode<int> *E = new TreeNode<int>(40);//Con B
	B->getChild().push_back(E);
	E->setParent(B);
	TreeNode<int> *F = new TreeNode<int>(50);//Con C
	C->getChild().push_back(F);
	F->setParent(C);
//	preOrder(A);
//	postOrder(A);
	inOrder(A);
	cout<<"\nDuong di tu 10 den 50: ";
	path(A,F);
	cout<<"\nChieu cao cua cay: "<<high(A);
  return 0;
}
*/
