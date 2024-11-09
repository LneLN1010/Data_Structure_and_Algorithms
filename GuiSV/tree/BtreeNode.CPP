#ifndef BTreeNode_CPP 
#define BTreeNode_CPP
using namespace std;
template <class T>
class BTreeNode{
    private:
       T elem ;
	   BTreeNode *parent,*left,*right ;
	public:
	   BTreeNode(){
		  parent = 0 ;
		  left = 0 ;
		  right = 0 ;
		}
		BTreeNode *getParent(){	return parent;	}
		BTreeNode *getLeft(){return left;}
		BTreeNode *getRight(){ return right;}
		void setParent(BTreeNode *p){ parent = p ;}
		void setLeft(BTreeNode *p){ left = p;}
		void setRight(BTreeNode *p){ right = p ; }
		void setElem(T element){ elem = element ; }
		T getElem(){ return elem ; }
		int hasLeft(){ return left != 0;   }
        int hasRight(){ return right != 0; } 
 };
#endif
