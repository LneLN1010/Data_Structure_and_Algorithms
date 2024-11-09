#ifndef BTREE_CPP
#define BTREE_CPP
#include "BTreeNode.cpp"
template <class T>
class BTree {
private:
	BTreeNode<T>* root;
	int n;
public:
    BTree(){ root=0;  n=0;}
	BTreeNode<T>* getRoot(){ return root;}
	int isEmpty(){
        return root==0;
    }           
	int size(){return n;}
	int isInternal(BTreeNode<T>*v){
	   return(v->hasLeft()|| v->hasRight()) ;           
    }
	int isExternal(BTreeNode<T>*v) {
	    return (!v->hasLeft()) && (!v->hasRight()) ;           
	}
	int isRoot(BTreeNode<T>*v){
		return v->getParent()==0;           
	}
	void preOrder(BTreeNode<T>*,void (*visit)(BTreeNode<T>*));
	void inOrder(BTreeNode<T>*,void (*visit)(BTreeNode<T>*));
	void postOrder(BTreeNode<T>*,void (*visit)(BTreeNode<T>*));
	BTreeNode<T>* insert(BTreeNode<T>*,int,T);
	void remove(BTreeNode<T>*);
};
template <class T>
void BTree<T>::inOrder(BTreeNode<T>* v, 
                        void (*visit)(BTreeNode<T>* a)){
	 if(v!=0){
        inOrder(v->getLeft(),visit);
        visit(v);
        inOrder(v->getRight(),visit);
    }
}     
template <class T>
void BTree<T>::postOrder(BTreeNode<T>* v, 
                       void (*visit)(BTreeNode<T>* a)){
     if(v!=0){
         postOrder(v->getLeft(),visit);
         postOrder(v->getRight(),visit);
         visit(v);
     }
}     
template <class T>
void BTree<T>::preOrder(BTreeNode<T>* v,
                       void (*visit)(BTreeNode<T>* a)){
     if(v!=0){
         visit(v);
         preOrder(v->getLeft(),visit);
         preOrder(v->getRight(),visit);
     }
}     
template <class T>
BTreeNode<T>* BTree<T>::insert(BTreeNode<T>* parent, int LeftRight,T elem){
     BTreeNode<T>* p = new BTreeNode<T> ;
     p->setParent(parent);
     p->setElem(elem);
     if (parent==0)
        root = p;
     else
        if(LeftRight==1) 
           parent->setRight(p);
        else 
		   parent->setLeft(p);
     n++;
     return p;
}
template <class T>
void BTree<T>::remove(BTreeNode<T>*v){
	  if(v!=0){
		  remove(v->getLeft());
		  remove(v->getRight());
		  BTreeNode<T> *parent = v->getParent();
		  if(parent!=0) {
		  	if(parent->getLeft()==v) parent->setLeft(0);
		  	if(parent->getRight()==v) parent->setRight(0);
		  }
		  if(v==root) root=0;
		  delete v;
		  n--;  
     }
}
#endif
