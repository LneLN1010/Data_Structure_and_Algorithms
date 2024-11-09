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
		void preOrder(TreeNode<T>*,void (*visit)(TreeNode<T>*));
		void inOrder(TreeNode<T>*,void (*visit)(TreeNode<T>*));
		void postOrder(TreeNode<T>*,void (*visit)(TreeNode<T>*));
		TreeNode<T>* insert(TreeNode<T>*,T);
		void remove(TreeNode<T>*);
};
	template <class T>
	void Tree<T>::inOrder(TreeNode<T>* v, 
	                        void (*visit)(TreeNode<T>* a)){
		 if(v!=NULL){
		 		if(v==0) return;
				if(v->hasChild()){
					inOrder(v->getChild()[0],visit);
				}
				visit(v);
				for(int i=1;i<v->getChild().size();i++) inOrder(v->getChild()[i],visit);

	    }
	}     
	template <class T>
	void Tree<T>::postOrder(TreeNode<T>* v, 
	                       void (*visit)(TreeNode<T>* a)){
	     if(v!=NULL){
				for(auto z:v->getChild()) postOrder(z,visit);
				visit(v);
	     }
	}     
	template <class T>
	void Tree<T>::preOrder(TreeNode<T>* v,
	                       void (*visit)(TreeNode<T>* a)){
	     if(v!=NULL){
	        visit(v);
			for(auto z:v->getChild()) preOrder(z,visit);
	     }
	}     
//Them 1 nut vao cay
	template <class T>
	TreeNode<T>* Tree<T>::insert(TreeNode<T> *parent,T elem){
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
	template <class T>
	void Tree<T>::remove(TreeNode<T> *v){
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

void print(TreeNode<int> *p){
     cout<<p->getElem()<<" ";
}
float t;
void tinhtong(TreeNode<int> *p){
	t = t + p->getElem();
}	
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
	tree.preOrder(tree.getRoot(),print);
	cout<<"\n Duyet theo thu tu giua:";
	tree.inOrder(tree.getRoot(),print);
	cout<<"\n Duyet theo thu tu sau:";
	tree.postOrder(tree.getRoot(),print);
	 //Tinh tong tat ca cac nut tren cay
	t=0;
	tree.postOrder(tree.getRoot(),tinhtong);
	cout<<"\n Tong cua cac nut tren cay = "<<t;
  return 0;
}


