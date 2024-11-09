#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;
template <class T>
class Tree {
private:
	TreeNode<T>* root;
	int n;
public:
    Tree(){ root=NULL;  n=0;}
	TreeNode<T> *&getRoot(){ return root;}
	int isEmpty(){
        return root==NULL;
    }           
	int size(){return n;}
	int isInternal(TreeNode<T>*v){
	   return(v->hasChild()) ;           
    }
	int isExternal(TreeNode<T>*v) {
	    return (!v->hasChild()) ;           
	}
	int isRoot(TreeNode<T>*v){
		return v->getParent()==NULL;           
	}
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
	//Them 1 nut vao cay
	TreeNode<T>* insert(TreeNode<T> *parent,T elem){
     TreeNode<T>* p = new TreeNode<T> ;
     p->setParent(parent);
     p->setElem(elem);
     if (parent==NULL)
        root = p;
    else
    	parent->insertChild(p);
     n++;
     return p;
}
	//Xoa 1 nut khoi cay
	void remove(TreeNode<T> *v){
		if(v!=NULL){
			for(auto z:v->getChild()) 
				remove(z);//Goi de quy xoa con cua v
			if(v->hasChild())
				v->getChild().clear();//Clear cac con cua v khoi danh sach Child cua v
			TreeNode<T> *parent = v->getParent();//Lay dia chi nut cha cua v
			if(parent!=NULL){//Neu v ko phai nut goc
				for(auto z = parent->getChild().begin();z!= parent->getChild().end();z++)//Duyet cac nut con z cua parent
				if(*z==v) {//Neu z la v thi xoa z khoi danh sach con cua parent
					parent->getChild().erase(z);
					break;
				}
			}
			delete v;//Cuoi cung la` lá thì giai phong vung nho ma v tro den
		}
	}
};
int main ()
{
	Tree<int> tree;
	TreeNode<int> *p;
	//Tao cay
	tree.insert(NULL, 100);
	TreeNode<int> *q;
	q = tree.insert(tree.getRoot(), 20);
	p = tree.insert(tree.getRoot(), 10);
	TreeNode<int> *r;
	r = tree.insert(p, 8);
	tree.insert(p, 6);
	tree.insert(q,30);
//	tree.remove(q);
	//Duyet cay
	cout<<"\n Duyet theo thu tu truoc:";
	tree.preOrder(tree.getRoot());
	cout<<"\n Duyet theo thu tu giua:";
	tree.inOrder(tree.getRoot());
	cout<<"\n Duyet theo thu tu sau:";
	tree.postOrder(tree.getRoot());
	cout<<"\nChieu cao cua cay: "<<tree.high(tree.getRoot())<<endl;
	//in duong di tu goc den la'
//	cout<<"\nDuong di tu nut goc den nut 8: ";
//	path(tree.getRoot(),q);
  return 0;
}


