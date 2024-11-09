#include <bits/stdc++.h>
#include "Btree.cpp"
using namespace std;
void pri(BTreeNode<int> *p){
     cout<<p->getElem()<<" ";
}
float t;
void tinhtong(BTreeNode<int> *p){
	t = t + p->getElem();
}	
int main(){	 
	BTree<int> tree;
	BTreeNode<int> *p,*a,*b;
	//Tao cay
	p = tree.insert(NULL,0, 50);
	p = tree.insert(tree.getRoot(),0, 30);
	a = tree.insert(p , 0 , 85);
	tree.insert(a,0, 19);
	tree.insert(a,1, 26);
	a = tree.insert(p , 1 , 36);
	tree.insert(a,0, 98);
	tree.insert(a,1, 99);
	p = tree.insert(tree.getRoot(),1, 15);
	tree.insert(p,0, 20);
	b = tree.insert(p , 1 , 40);
	tree.insert(b,0, 72);
	tree.insert(b,1, 66);
	//tree.remove(tree.getRoot());
	//Duyet cay
	cout<<"\n Duyet theo thu tu truoc:";
	tree.preOrder(tree.getRoot(),pri);
	cout<<"\n Duyet theo thu tu giua:";
	tree.inOrder(tree.getRoot(), pri);
	cout<<"\n Duyet theo thu tu sau:";
	tree.postOrder(tree.getRoot(),pri);
	//Tinh tong tat ca cac nut tren cay
	t=0;
	tree.postOrder(tree.getRoot(),tinhtong);
	cout<<"\n Tong cua cac nut tren cay = "<<t;
	return 0;
}
 
